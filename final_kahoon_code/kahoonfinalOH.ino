#include<Wire.h>
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
const int out = 12;
const int in = 13;
int arrayX;
int arrayY;
int arrayZ;
int count;
void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(out, OUTPUT);
  pinMode(in, INPUT);
}
int cool =0;
void loop () {
  long dur;
  long dis;
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers

  digitalWrite(out, LOW);
  delayMicroseconds(2);

  digitalWrite(out, HIGH);
  delayMicroseconds(10);
  digitalWrite(out, LOW);
  
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  
 

  if (AcX < 0) {
    AcX = -AcX;
  }
  if (AcY < 0) {
    AcY = -AcY;
  }
  if (AcZ < 0) {
    AcZ = -AcZ;
  }



  arrayX = arrayX - AcX;
  arrayY = arrayY - AcY;
  arrayZ = arrayZ - AcZ;


  //if(arrayX >= 2000||arrayX<=0-2000 v ){
  //Serial.print(" change in x \n");

  //}

  if (arrayX >= 2000 || arrayX <= -2000) {

    //  Serial.println(String("the value was")+ true_cm);
    //Serial.print("change in x \n");
   // Serial.print("   ");
    //Serial.print(arrayX);
    count++;
    if (count >= 3) {
      dur = pulseIn(in, HIGH);
      //Serial.print("hit");
      long int true_cm;

  true_cm = 2.54 * dur;
  true_cm = true_cm / 100;
     // Serial.print(count);
     // Serial.print(" \n ");
     //Serial.println("43");
      if (true_cm > 70) {
       // Serial.println(String("away keystroke(nothing)"));
      }
      else if (true_cm < 50) {
        //Serial.println(String("this is the base keysrokes(base)"));
        
      //  Serial.println('d');
        cool = 1;
        count = 0;
      }

    }
    // Serial.print("   ");
    // Serial.print(arrayY);
    // Serial.print("    ");
    //Serial.print(arrayZ);
   // Serial.print("\n");
  }
  else {
    count = 0;
  }  
  if(cool==1){
    Serial.println('d');
    }
   if(cool==0){
    Serial.println('k');
    } 

  delay(100);
  //Serial.print("k");
  arrayX = AcX;
  arrayY = AcY;
  arrayZ = AcZ;
  cool = 0;


}

