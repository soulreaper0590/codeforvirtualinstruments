import keyboard
import time
import serial
    
Var1=serial.Serial('COM10',9600)
time.sleep(1)
while 1:
    data=0
    data=Var1.read()
    if data == 'A':
      keyboard.press('z')
      while data=='A':
        data = Var1.read()
        time.sleep(.1)
      keyboard.realease('z')
    if data == 'B':
	    keyboard.press('x')
	    while data=='B':
	      data = Var1.read()
	      time.sleep(.1)
	    keyboard.realease('x')
    if data == 'C':
	    keyboard.press('c')
	    while data=='B':
	      data = Var1.read()
	      time.sleep(.1)
	    keyboard.realease('c')
    if data == 'D':
	    keyboard.press('v')
	    while data=='B':
	      data = Var1.read()
	      time.sleep(.1)
	    keyboard.realease('v')
    if data == 'E':
	    keyboard.press('b')
	    while data=='B':
	      data = Var1.read()
	      time.sleep(.1)
	    keyboard.realease('b')
    
