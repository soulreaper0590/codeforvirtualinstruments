import keyboard
import time
import serial
    
#Var1=serial.Serial('COM22',9600)
import win32com.client as comclt
Var2=serial.Serial('COM8',9600)
wsh= comclt.Dispatch("WScript.Shell")
 
while 1:
    #data1='z'
    #data2='z'
    #data1=Var1.read()
    data2=Var2.readline().decode('ascii');
    '''if data2 == 'a':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")'''
    if (data2[0] == 'b'):
        keyboard.write('s')
        time.sleep(0.5)
        keyboard.release('s')
    '''if data2 == 'c':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")
    if data2 == 'd':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")
    if data2 == 'e':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")
    if data2 == 'f':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")'''
