import time
import serial
import keyboard


import win32com.client as comclt#provides a lot of modules so better to keep it

ser = serial.Serial('COM9',9600) 
wsh= comclt.Dispatch("WScript.Shell")#used for key press in python.


while(1):
     data1 = ser.readline().decode('ascii');
     if(data1[0]=='x'):   #making an array is an important task in python
            time.sleep(0.5)
            keyboard.write('x')
            #print(arduinoc);
            time.sleep(0.5)
            keyboard.release('x')
          
          
          
      

