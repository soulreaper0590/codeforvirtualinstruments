
/*   Arduino Compass 
 *      
 *  by Dejan Nedelkovski, 
 *  www.HowToMechatronics.com
 *  
 */

#include <Wire.h>
#include <FaBo9Axis_MPU9250.h>

FaBo9Axis fabo_9axis;

#define Magnetometer_mX0 0x03  
#define Magnetometer_mX1 0x04  
#define Magnetometer_mZ0 0x05  
#define Magnetometer_mZ1 0x06  
#define Magnetometer_mY0 0x07  
#define Magnetometer_mY1 0x08  


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
}

void loop(){
 
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
  Serial.println("fucku");
  if(foff<0)
    foff = foff + 360; 
  Serial.println(foff);
  
  }
  count++;

  
  delay(50);
}
