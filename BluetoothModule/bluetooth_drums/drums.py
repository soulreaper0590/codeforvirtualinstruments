import time
import serial
import keyboard
from threading import Thread


import win32com.client as comclt#provides a lot of modules so better to keep it

ser1 = serial.Serial('COM6',9600)
ser2 = serial.Serial('COM9',9600)
wsh= comclt.Dispatch("WScript.Shell")#used for key press in python.

def firstfunction():
    while(1):
    
         data1 = ser1.readline().decode('ascii');
        
         if(data1[0]=='F'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('c')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('c')
        # data2 = ser2.readline().decode('ascii');
         
        # time.sleep(0.1)
         if(data1[0]=='H'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('o')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('o')
               
         if(data1[0]=='B'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('e')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('e')
                
         if(data1[0]=='N'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('i')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('i')
                

def secondfunction():
    while(1):
    
         data2 = ser2.readline().decode('ascii');

         if(data2[0]=='Q'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('w')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('w')
                
         if(data2[0]=='W'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('h')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('h')
                
         if(data2[0]=='E'):   #making an array is an important task in python
                time.sleep(0.05)
                keyboard.write('t')
                #print(arduinoc);
                time.sleep(0.05)
                keyboard.release('t')

t1 = Thread(target = firstfunction)
t2 = Thread(target = secondfunction)
t1.start()
t2.start()
    

    
