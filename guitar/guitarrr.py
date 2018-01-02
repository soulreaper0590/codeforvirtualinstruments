import keyboard
import time
import serial
    
#Var1=serial.Serial('COM22',9600)
#import win32com.client as comclt
Var2=serial.Serial('COM19',9600)
#wsh= comclt.Dispatch("WScript.Shell")
 
while 1:
    #data1='z'
    #data2='z'
    #data1=Var1.read()
    data2=Var2.readline().decode('ascii');
    '''if data2 == 'a':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")'''
    if (data2[0] == 'f'):
        keyboard.write('r,y,i')
        keyboard.release('r,y,i')
    if data2[0] == 'F':
        keyboard.press("e,y,i")
        keyboard.release("e,y,i")
    if data2[0] == 'd':
        keyboard.press("w,r,y")
        keyboard.release("w,r,y")
    if data2[0] == 'C':
        keyboard.press("q,e,t")
        keyboard.release("q,e,t")
    if data2[0] == 'B':
        keyboard.press("w,r,7")
        keyboard.release("w,r,7")
    if data2[0] == 'A':
        keyboard.press("e,y,9")
        keyboard.release("e,y,9")
    '''if data2 == 'f':
        keyboard.press("z")
        time.sleep(5)
        keyboard.release("z")'''

        
   

        