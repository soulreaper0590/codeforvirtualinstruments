import keyboard
import time
import serial
    
Var1=serial.Serial('COM10',9600)
time.sleep(1)
while 1:
    data='z'
    data=Var1.read()
    if data == 'A':
	    keyboard.press_and_release("z")
    if data == 'B':
	    keyboard.press_and_release("x")
    if data == 'C':
	    keyboard.press_and_release("c")
    if data == 'D':
	    keyboard.press_and_release("v")
    if data == 'E':
	    keyboard.press_and_release("b")
    if data == 'a':
	    keyboard.press_and_release("n")
    
