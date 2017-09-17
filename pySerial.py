import time
import serial


ser=Serial.serial('COM13',9600)
int c2=0
float a[3]
while 1:
    magvalues=ser.read()
    int c=0;
    for(int j=0;j<3;j++)
        for(int i=c+1;i<len(magvalues);i++):
            if(magvalues[i]=' ')
                c2=i
                break
        a[j]=float(magvalues[c,c2])
        c=c2
float Xm, Ym, Zm, heading, declination, headingDegrees, headingFiltered   
float PI = 3.1415 
Xm = 2 * a[0] * 0.00092
Ym = 2 * a[1] * 0.00092
Zm = 2 * a[2] * 0.00092
  
heading = arctan2(Ym, Xm)
 
declination = 0.021 
heading += declination
  
if(heading <0) 
	heading += 2*PI

if(heading > 2*PI)
	heading -= 2*PI

headingDegrees = heading * 180/PI 
 
headingFiltered = headingFiltered*0.85 + headingDegrees*0.15
    
        


            
        
    