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
    
        


            
        
    
