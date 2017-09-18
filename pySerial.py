import time
import serial


ser=Serial.serial('COM9',9600)
c2=0
a[3]
while 1:
    magvalues=ser.read()
    c=0;
    for j in range(0,3):
        for i in range (c+1,len(magvalues)):
            if magvalues[i]==' ':
                c2=i
                break
        a[j]=float(magvalues[c,c2])
        c=c2
Xm, Ym, Zm, heading, declination, headingDegrees, headingFiltered=0.0 
PI = 3.1415 
Xm = 2 * a[0] * 0.00092
Ym = 2 * a[1] * 0.00092
Zm = 2 * a[2] * 0.00092
  
heading = arctan2(Ym, Xm)
 
declination = 0.021 
heading += declination
  
if heading <0:
	heading += 2*PI

if heading > 2*PI:
	heading -= 2*PI

headingDegrees = heading * 180/PI 
 
headingFiltered = headingFiltered*0.85 + headingDegrees*0.15
