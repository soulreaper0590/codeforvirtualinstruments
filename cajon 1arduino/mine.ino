#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
//const int out=12;
//const int in=13;
int arrayX;
int arrayY;
int arrayZ;
int count;
int pre = 0;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  //pinMode(out,OUTPUT);
  //pinMode(in,INPUT);
}
void loop ()
{
  //long dur;
  //long dis;
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers

  //digitalWrite(out,LOW);
  //delayMicroseconds(2);

 // digitalWrite(out,HIGH);
  //delayMicroseconds(10);
  //digitalWrite(out,LOW);
 // dur=pulseIn(in,HIGH);  
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  //long int true_cm;

  //true_cm = 2.54*dur;
  //true_cm = true_cm/100;
  //if(true_cm>50){
    //Serial.println(String("away keystroke(nothing)"));
  //}
  //else if(true_cm<38){
    //Serial.println(String("this is the base keysrokes(base)"));
  //}
 

    if(AcX<0){
      AcX = -AcX;
    }
    if(AcY<0){
      AcY = -AcY;
    }
    if(AcZ<0){
      AcZ = -AcZ;
    }



  arrayX = arrayX - AcX;
  arrayY = arrayY - AcY;
  arrayZ = arrayZ - AcZ;


  //if(arrayX >= 2000||arrayX<=0-2000){
  //Serial.print(" change in x \n");

  //}

  if(arrayX>= 4000||arrayX<=-4000)
  {

    //  Serial.println(String("the value was")+ true_cm);
   // Serial.print("change in x \n");
    //Serial.print("   "); 
    //Serial.print(arrayX);
    count++;
    if (count >= 3)
    {
      //Serial.print("hit");
      Serial.print('x');
      //pre=1;
      //Serial.print(" \n ");
    }
    // Serial.print("   "); 
    // Serial.print(arrayY);
    // Serial.print("    "); 
    //Serial.print(arrayZ);
    //Serial.print("\n");
   
   // Serial.println('d');
  //}
  //else{
   // count = 0;
  //}
//if(pre==0){
  
  //Serial.println('d');
  }
  delay(100);
  //Serial.print("k");
  arrayX = AcX;
  arrayY = AcY;
  arrayZ = AcZ;
  //pre = 0;


}
