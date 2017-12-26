import keyboard
import time
import serial
    
Var1=serial.Serial('COM8',9600)
time.sleep(1)
while 1:
    data=0
    data=Var1.read().decode('ascii');
    print(data)
    if data == 'A':
      keyboard.press('t')
      print ("hell is here friend")
      while 1:
        time.sleep(.1)
        data = Var1.read().decode('ascii');
        print(data)
        print ("cello the best company ever")
        if data != 'A':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('t')
    if data == 'B':
      keyboard.press('u')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'B':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('u')
    if data == 'C':
      keyboard.press('y')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'C':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('y')
    if data == 'D':
      keyboard.press('i')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'D':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('i')
    if data == 'E':
      keyboard.press('p')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'E':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('p')
    if data == 'F':
      keyboard.press('z')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print(data)
        print ("cello the best company ever")
        if data != 'F':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('z')
    if data == 'G':
      keyboard.press('x')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'G':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('x')
    if data == 'H':
      keyboard.press('c')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'H':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('c')
    if data == 'I':
      keyboard.press('v')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'I':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('v')
    if data == 'J':
      keyboard.press('b')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'J':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('b')
   
   
