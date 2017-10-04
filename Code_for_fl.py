import keyboard
import time
import serial
    
Var1=serial.Serial('COM22',9600)
Var2=serial.Serial('COM7',9600)
time.sleep(1)
while 1:
    data1='z'
    data2='z'
    data1=Var1.read()
    data2=Var2.read()
    if data1 == 'a':
	keyboard.press_release("z")
    if data2 == 'b':
	keyboard.press_release("s")
        
