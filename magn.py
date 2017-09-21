import time
import math
import serial
while 1:
	ser=serial.Serial('/dev/ttyACM0',9600)
	c2=0
	magvalues=ser.read()
	ser.flushInput()
	c=0;
	a=(0,0,0)
	for j in range(0,3):
	    for i in range (c+1,len(magvalues)):
	        if magvalues[i]==" ":	
	            c2=i
	            break
	        a[j]=int(magvalues[c:c2])
	    	c=c2+1
	PI = 3.1415 
	Xm = 2*a[0]*0.00092
	Ym = 2*a[1]*0.00092
	Zm = 2*a[2]*0.00092
	  
	heading=math.atan2(Ym,Xm)
	 
	declination = 0.021 
	heading += declination
	  
	if heading <0:
		heading += 2*PI

	if heading > 2*PI:
		heading -= 2*PI

	headingDegrees = heading * 180/PI 
	headingFiltered =0
	headingFiltered = headingFiltered*0.85 + headingDegrees*0.15

	print headingFiltered
