#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int fingerStatus1(float finger);
int fingerStatus2(float finger);
int fingerStatus3(float finger);
int fingerStatus4(float finger);
int region(float stretch);
#include <Wire.h>
#include <FaBo9Axis_MPU9250.h>
#include <Kalman.h> // Source: https://github.com/TKJElectronics/KalmanFilter

FaBo9Axis fabo_9axis;

#define RESTRICT_PITCH // Comment out to restrict roll to ±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;

/* IMU Data */
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
float tempRaw;
float mx,my,mz;
int a[5]={0};

float gyroXangle, gyroYangle; // Angle calculate using the gyro only
float compAngleX, compAngleY; // Calculated angle using a complementary filter
float kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

uint32_t timer;

float pitchprev=0,pitchnow;

void setup() {
  Serial.begin(9600);
  BTserial.begin(38400);
  Serial.println("RESET");
  Serial.println();

  Serial.println("configuring device.");

  if (fabo_9axis.begin()) {
    Serial.println("configured FaBo 9Axis I2C Brick");
  } else {
    Serial.println("device error");
    while(1);
  }
 /* float ax,ay,az;
  float gx,gy,gz;
  
  float temp;*/
  
  fabo_9axis.readAccelXYZ(&accX,&accY,&accZ);
  fabo_9axis.readGyroXYZ(&gyroX,&gyroY,&gyroZ);
  fabo_9axis.readMagnetXYZ(&mx,&my,&mz);
  fabo_9axis.readTemperature(&tempRaw);

    // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
  // atan2 outputs the value of -π to π (radians) - see http://en.wikipedia.org/wiki/Atan2
  // It is then converted from radians to degrees
#ifdef RESTRICT_PITCH // Eq. 25 and 26
  double roll  = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else // Eq. 28 and 29
  double roll  = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  double pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif

  kalmanX.setAngle(roll); // Set starting angle
  kalmanY.setAngle(pitch);
  gyroXangle = roll;
  gyroYangle = pitch;
  compAngleX = roll;
  compAngleY = pitch;

  timer = micros();

}

 void loop(){
  //PITCH CODE
  fabo_9axis.readAccelXYZ(&accX,&accY,&accZ);
  fabo_9axis.readGyroXYZ(&gyroX,&gyroY,&gyroZ);
  fabo_9axis.readMagnetXYZ(&mx,&my,&mz);
  fabo_9axis.readTemperature(&tempRaw);

  double dt = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();

  // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
  // atan2 outputs the value of -π to π (radians) - see http://en.wikipedia.org/wiki/Atan2
  // It is then converted from radians to degrees
#ifdef RESTRICT_PITCH // Eq. 25 and 26
  double roll  = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else // Eq. 28 and 29
  double roll  = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  double pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif

  double gyroXrate = gyroX / 131.0; // Convert to deg/s
  double gyroYrate = gyroY / 131.0; // Convert to deg/s

#ifdef RESTRICT_PITCH
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll);
    compAngleX = roll;
    kalAngleX = roll;
    gyroXangle = roll;
  } else
    kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);
#else
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((pitch < -90 && kalAngleY > 90) || (pitch > 90 && kalAngleY < -90)) {
    kalmanY.setAngle(pitch);
    compAngleY = pitch;
    kalAngleY = pitch;
    gyroYangle = pitch;
  } else
    kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleY) > 90)
    gyroXrate = -gyroXrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt); // Calculate the angle using a Kalman filter
#endif

  gyroXangle += gyroXrate * dt; // Calculate gyro angle without any filter
  gyroYangle += gyroYrate * dt;
  //gyroXangle += kalmanX.getRate() * dt; // Calculate gyro angle using the unbiased rate
  //gyroYangle += kalmanY.getRate() * dt;

  compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll; // Calculate the angle using a Complimentary filter
  compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch;

  // Reset the gyro angle when it has drifted too much
  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;
  //Printing pitch value
  //Serial.println(pitch); 
  float stretch1=analogRead(5);
        int stretch11=region(stretch1);//gives the 3 different regions 3:no stretch to 1:full stretch
        //Serial.println(stretch11);
      
        //Reading of 4 different flexes attached
        float finger1 = analogRead(1);
        float finger2 = analogRead(2);
        float finger3 = analogRead(3);
        float finger4 = analogRead(4);
        
        //getting the each finger region
        int finger11 = fingerStatus1(finger1);
        int finger22 = fingerStatus2(finger2);
        int finger33 = fingerStatus3(finger3);
        int finger44 = fingerStatus4(finger4);
         a[0] = a[1];
   a[1] = a[2];
   a[2] = a[3];
   a[3] = a[4];
   a[4] = pitch;
   if(a[0]<0 && a[1]<0 && a[2]<0 && a[3]<0 && a[4]<0){
    Serial.println("string 1");
     switch(region(stretch1))
        {
          case 1 :if(finger11==2&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("A");
                    BTserial.write('A');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==2){
                    Serial.println("B");
                    BTserial.write('B');
                  }
                  if(finger11==0&&finger22==2&&finger33==2&&finger44==2){//put other hand positions
                    Serial.println("C");
                    BTserial.write('C');
                  }
                  if(finger11==2&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("D");
                    BTserial.write('D');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==0){//open string
                    Serial.println("E");
                    BTserial.write('E');
                  }
                  
                  break;
          case 2 :if(finger11==2&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("F");
                    BTserial.write('F');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==2){
                    Serial.println("G");
                    BTserial.write('G');
                  }
                  if(finger11==0&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("H");
                    BTserial.write('H');
                  }
                  
                  if(finger11==2&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("I");
                    BTserial.write('I');
                    
                  }
                   if(finger11==0&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("J");
                    BTserial.write('J');
                  }
                  break;
          
               
            
        }

    
   }
  else if (a[0]>0 && a[1]>0 && a[2]>0 && a[3]>0 && a[4]>0){
  Serial.println("string 2");
  switch(region(stretch1))
        {
          case 1 :if(finger11==2&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("K");
                    BTserial.write('K');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==2){
                    Serial.println("L");
                    BTserial.write('L');
                  }
                  if(finger11==0&&finger22==2&&finger33==2&&finger44==2){//put other hand positions
                    Serial.println("M");
                    BTserial.write('M');
                  }
                  if(finger11==2&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("N");
                    BTserial.write('N');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==0){//open string
                    Serial.println("O");
                    BTserial.write('O');
                  }
                  
                  break;
          case 2 :if(finger11==2&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("P");
                    BTserial.write('P');
                  }
                  if(finger11==0&&finger22==0&&finger33==0&&finger44==2){
                    Serial.println("Q");
                    BTserial.write('Q');
                  }
                  if(finger11==0&&finger22==2&&finger33==2&&finger44==2){
                    Serial.println("R");
                    BTserial.write('R');
                  }
                  
                  if(finger11==2&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("S");
                    BTserial.write('S');
                  }
                   if(finger11==0&&finger22==0&&finger33==0&&finger44==0){
                    Serial.println("T");
                    BTserial.write('T');
                  }
          
               
            
        }
  
   }
      
  

   
     
  
    
     delay(100);
   }


  //Defined function for fingering
  
  int fingerStatus1(float finger){
    int fingerReturn= 0;
     
    if(finger>=200){
      fingerReturn=0;
      }
     
       if(finger<200)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
    int fingerStatus2(float finger){
    int fingerReturn= 0;
     
    if(finger>=300){
      fingerReturn=0;
      }
      
       if(finger<300)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
int fingerStatus3(float finger){
    int fingerReturn= 0;
     
    if(finger>=480){
      fingerReturn=0;
      }
      
       if(finger<480)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
int fingerStatus4(float finger){
    int fingerReturn= 0;
     
    if(finger>=400){
      fingerReturn=0;
      }
      
       if(finger<400)
       fingerReturn=2;
    
    
    return fingerReturn;
    }

    

  int region(float stretch)
  {
    int regionReturn=0;
    if(stretch<495)
      regionReturn=1;
    else if(stretch>=495)
      regionReturn=2;
   
    return regionReturn;
  }
