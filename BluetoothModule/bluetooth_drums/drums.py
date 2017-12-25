import time
import serial
import keyboard
from threading import Thread


import win32com.client as comclt#provides a lot of modules so better to keep it

ser1 = serial.Serial('COM4',9600)
ser2 = serial.Serial('COM16',9600)
wsh= comclt.Dispatch("WScript.Shell")#used for key press in python.

def firstfunction():
    while(1):
    
         data1 = ser1.readline().decode('ascii');
        
         if(data1[0]=='F'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('c')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('c')
        # data2 = ser2.readline().decode('ascii');
         
        # time.sleep(0.1)
         if(data1[0]=='H'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('s')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('s')
               
         if(data1[0]=='B'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('b')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('b')
                
         if(data1[0]=='N'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('v')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('v')
                

def secondfunction():
    while(1):
    
         data2 = ser2.readline().decode('ascii');

         if(data2[0]=='Q'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('z')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('z')
                
         if(data2[0]=='W'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('g')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('g')
                
         if(data2[0]=='E'):   #making an array is an important task in python
                time.sleep(0.1)
                keyboard.write('d')
                #print(arduinoc);
                time.sleep(0.1)
                keyboard.release('d')

t1 = Thread(target = firstfunction)
t2 = Thread(target = secondfunction)
t1.start()
t2.start()
    
