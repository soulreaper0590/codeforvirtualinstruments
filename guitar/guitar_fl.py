import keyboard
import time
import serial
    

Var1=serial.Serial('COM7',9600)
time.sleep(1)
while 1:
    data='z'
    
    data=Var1.read()
    
    if data == 'Z':
	keyboard.press_release("z")
    if data == 'X':
	keyboard.press_release("x")
    if data == 'C':
	keyboard.press_release("c")
     if data == 'V':
	keyboard.press_release("v")
        

        
   

        
