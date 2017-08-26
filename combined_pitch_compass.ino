#include <Wire.h>
#include <FaBo9Axis_MPU9250.h>
#include <Kalman.h>

FaBo9Axis fabo_9axis;
#define RESTRICT_PITCH

#define Magnetometer_mX0 0x03  
#define Magnetometer_mX1 0x04  
#define Magnetometer_mZ0 0x05  
#define Magnetometer_mZ1 0x06  
#define Magnetometer_mY0 0x07  
#define Magnetometer_mY1 0x08  

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;

/* IMU Data */
float accX, accY, accZ;
float gyroX, gyroY, gyroZ;
float tempRaw;


float gyroXangle, gyroYangle; // Angle calculate using the gyro only
float compAngleX, compAngleY; // Calculated angle using a complementary filter
float kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

uint32_t timer;
int a[10];
float i;


float mX0, mX1, mX_out;
float mY0, mY1, mY_out;
float mZ0, mZ1, mZ_out;

float heading, headingDegrees, headingFiltered, declination;
float pre;
int count= 0;
float Xm,Ym,Zm;

#define Magnetometer 0x1E //I2C 7bit address of HMC5883

void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  Serial.println();

  Serial.println("configuring device.");

  if (fabo_9axis.begin()) {
    Serial.println("configured FaBo 9Axis I2C Brick");
  } else {
    Serial.println("device error");
    while(1);
  }

  fabo_9axis.readAccelXYZ(&accX,&accY,&accZ);
  fabo_9axis.readGyroXYZ(&gyroX,&gyroY,&gyroZ);

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

  
  fabo_9axis.readAccelXYZ(&accX,&accY,&accZ);
  fabo_9axis.readGyroXYZ(&gyroX,&gyroY,&gyroZ);
  //---- X-Axis
  /*Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mX1);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mX0 = Wire.read();
  }*/
  fabo_9axis.readMagnetXYZ(&mX0,&mY0,&mZ0);
  delay(100);
  fabo_9axis.readMagnetXYZ(&mX1,&mY1,&mZ1);
 
  /*Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mX0);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mX1 = Wire.read();
  }
  //---- Y-Axis
  Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mY1);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mY0 = Wire.read();
  }
  Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mY0);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mY1 = Wire.read();
  }
  
  //---- Z-Axis
  Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mZ1);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mZ0 = Wire.read();
  }
  Wire.beginTransmission(Magnetometer); // transmit to device
  Wire.write(Magnetometer_mZ0);
  Wire.endTransmission();
  Wire.requestFrom(Magnetometer,1); 
  if(Wire.available()<=1)   
  {
    mZ1 = Wire.read();
  }*/
  
  //---- X-Axis


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

  /* Print Data */
#if 0 // Set to 1 to activate
  Serial.print(accX); Serial.print("\t");
  Serial.print(accY); Serial.print("\t");
  Serial.print(accZ); Serial.print("\t");
  Serial.print(gyroX); Serial.print("\t");
  Serial.print(gyroY); Serial.print("\t");
  Serial.print(gyroZ); Serial.print("\t");
  Serial.print("\t");
#endif

 /* Serial.print(roll); Serial.print("\t");
  Serial.print(gyroXangle); Serial.print("\t");
  Serial.print(compAngleX); Serial.print("\t");
  Serial.print(kalAngleX); Serial.print("\t");

  Serial.print("\t"); */
 
 // Serial.print(pitch); Serial.print("\n");
 /* Serial.print(gyroYangle); Serial.print("\t");
  Serial.print(compAngleY); Serial.print("\t");
  Serial.print(kalAngleY); Serial.print("\t");*/
  a[0] = a[1];
   a[1] = a[2];
   a[2] = a[3];
   a[3] = a[4];
   a[4] = a[5];
   a[5] = a[6];
   a[6] = a[7];
   a[7] = a[8];
   a[8] = a[9];
   a[9] = pitch;

   if((a[4]-a[0])<-25||(a[4]-a[1])<-25||(a[4]-a[2])<-25||(a[4]-a[3])<-25){
    Serial.println("hola caracola");
    a[0] = pitch;
    a[1] = pitch;
    a[2] = pitch;
    a[3] = pitch;
    

    if((a[9]-a[5])>25||(a[9]-a[6])>25||(a[9]-a[7])>25||(a[9]-a[8])>25){
    Serial.println("up");
    a[5] = pitch;
    a[6] = pitch;
    a[7] = pitch;
    a[8] = pitch;
    }
   }
 






  mX1=mX1;//<<8.00;
  mX_out =mX0+mX1; // Raw data
  // From the datasheet: 0.92 mG/digit
  Xm = mX_out*0.00092; // Gauss unit
  //* Earth magnetic field ranges from 0.25 to 0.65 Gauss, so these are the values that we need to get approximately.

  //---- Y-Axis
  mY1=mY1;//<<8.00;
  mY_out =mY0+mY1;
  Ym = mY_out*0.00092;

  //---- Z-Axis
  mZ1=mZ1;
  mZ_out =mZ0+mZ1;
  Zm = mZ_out*0.00092;
  // ==============================
  //Calculating Heading
  heading = atan2(Ym, Xm);
 
  // Correcting the heading with the declination angle depending on your location
  // You can find your declination angle at: http://www.ngdc.noaa.gov/geomag-web/
  // At my location it's 4.2 degrees => 0.073 rad  1.21° W  ± 0.28°
  declination = 0.021; 
  heading += declination;
  
  // Correcting when signs are reveresed
  if(heading <0) heading += 2*PI;

  // Correcting due to the addition of the declination angle
  if(heading > 2*PI)heading -= 2*PI;

  headingDegrees = heading * 180/PI; // The heading in Degrees unit

  // Smoothing the output angle / Low pass filter 
  headingFiltered = headingFiltered*0.85 + headingDegrees*0.15;

  //Sending the heading value through the Serial Port to Processing IDE
  
  Serial.println(headingFiltered);
  float foff = headingFiltered;
  if(count<50&&count>=40){
  pre = pre + headingFiltered;
  }
  if(count==50){
  pre = pre/(float)10;
  }
  if(count>50){
  foff = foff - pre;
  //Serial.println("fucku");
  if(foff<0)
    foff = foff + 360;
    if(foff>180){
      foff = foff - 360;
      } 

    
 //Serial.println(foff);
  
  }
  count++;
  

  
  delay(10);
}
