import keyboard
import time
import serial
    
Var=serial.Serial('COM22',9600)
time.sleep(1)
while 1:
    data='z'
    data=Var1.read()
    if data == 'G':
	keyboard.press_release("z")
    if data == 'C':
	keyboard.press_release("x")
    if data == 'D':
	keyboard.press_release("c")
    if data == 'F':
	keyboard.press_release("v")
    if data == 'E':
	keyboard.press_release("b")
    if data == 'A':
	keyboard.press_release("n")
    
