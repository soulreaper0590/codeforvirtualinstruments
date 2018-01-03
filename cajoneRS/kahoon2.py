import time
import serial
import keyboard
from threading import Thread


#import win32com.client as comclt#provides a lot of modules so better to keep it

ser1 = serial.Serial('COM5',9600)
ser2 = serial.Serial('COM9',9600)
#wsh= comclt.Dispatch("WScript.Shell")#used for key press in python.

def firstfunction():
    while(1):
    
         data1 = ser1.readline().decode('ascii');
        
         if(data1[0]=='L'):   #making an array is an important task in python
                #time.sleep(0.05)
                keyboard.write('z')
                #print(arduinoc);
               # time.sleep(0.05)
                keyboard.release('z')
        # data2 = ser2.readline().decode('ascii');
         
        # time.sleep(0.1)
         if(data1[0]=='M'):   #making an array is an important task in python
                #time.sleep(0.05)
                keyboard.write('x')
                #print(arduinoc);
                #time.sleep(0.05)
                keyboard.release('x')
               
                        

def secondfunction():
    while(1):
    
         data2 = ser2.readline().decode('ascii');

         if(data2[0]=='L'):   #making an array is an important task in python
                #time.sleep(0.05)
                keyboard.write('x')
                #print(arduinoc);
                #time.sleep(0.1)
                keyboard.release('x')
                
         if(data2[0]=='M'):   #making an array is an important task in python
                #time.sleep(0.05)
                keyboard.write('x')
                #print(arduinoc);
                #time.sleep(0.05)
                keyboard.release('x')
                
         
t1 = Thread(target = firstfunction)
t2 = Thread(target = secondfunction)
t1.start()
t2.start()
    