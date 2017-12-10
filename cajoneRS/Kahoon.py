import keyboard
import time
import serial
    
Var1 = serial.Serial('COM13',9600)
Var2 = serial.Serial('COM14',9600)

 
while 1:
    #data1='z'
    #data2='z'
    data1=Var1.readline().decode('ascii');
    data2=Var2.readline().decode('ascii');
    if data1[0] == 'L':
        keyboard.write('z')
        time.sleep(5)
        keyboard.release('z')
    if data1[0] == 'M':
        keyboard.press("x")
        time.sleep(5)
        keyboard.release("x")
    if data2[0] == 'L':
        keyboard.press("c")
        time.sleep(5)
        keyboard.release("c")
    if data2[0] == 'M':
        keyboard.press("v")
        time.sleep(5)
        keyboard.release("v")
  