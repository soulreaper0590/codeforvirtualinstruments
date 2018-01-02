import keyboard
import time
import serial
    
Var1=serial.Serial('COM15',9600)
time.sleep(1)
while 1:
    data=0
    data=Var1.read().decode('ascii');
    print(data)
    if data == 's':
      keyboard.press('2')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        #print(data)
        
        if data != 's':
            break
      keyboard.release('2')
    if data == 'r':
      keyboard.press('3')
      while 1:
        #time.sleep(.1)
        data= Var1.read().decode('ascii');
        if data != 'r':
            print (data)
            print("this the mistale ")
            break
      keyboard.release('3')
    if data == 'g':
      keyboard.press('r')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        if data != 'g':
            break
      keyboard.release('r')
    if data == 'm':
      keyboard.press('5')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        if data != 'm':
          break
      keyboard.release('5')
    if data == 'e':
      keyboard.press('6')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        if data[0] != 'e':
            break
      keyboard.release('6')
    if data == 'f':
      keyboard.press('7')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print(data)
        if data != 'f':
            break
      keyboard.release('7')
    if data == 'a':
      keyboard.press('i')
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        if data != 'a':
            break
      keyboard.release('i')
    if data == 'b':
      keyboard.press('9')
      while 1:
        #time.sleep(.1)
        data = Var1.readline().decode('ascii');
        if data[0] != 'b':
            break
      keyboard.release('9')
    if data == 'x':
      keyboard.press('<')
      while 1:
        #time.sleep(.1)
        data = Var1.readline().decode('ascii');
        if data[0] != 'x':
            break
      keyboard.release('<')
    if data == 'z':
      keyboard.press('j')
      while 1:
        #time.sleep(.1)
        data = Var1.readline().decode('ascii');
        if data[0] != 'z':
            break
      keyboard.release('j')
    if data == 'y':
      keyboard.press('h')
      while 1:
        #time.sleep(.1)
        data = Var1.readline().decode('ascii');
        if data[0] != 'y':
            break
      keyboard.release('h')
