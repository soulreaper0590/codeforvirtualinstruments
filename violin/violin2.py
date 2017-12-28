import keyboard
import time
import serial
    
Var1=serial.Serial('COM17',9600)
time.sleep(1)
while 1:
    data=0
    data=Var1.read().decode('ascii');
    print(data)
    if data == 'A':
      keyboard.press('n')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        #print(data)
        print ("cello the best company ever")
        if data != 'A':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('n')
    if data == 'B':
      keyboard.press('e')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello then best company ever")
        if data != 'B':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('e')
    if data == 'C':
      keyboard.press(',')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'C':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release(',')
    if data == 'D':
      keyboard.press('j')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'D':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('j')
    if data == 'E':
      keyboard.press('w')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'E':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('w')
    if data == 'K':
      keyboard.press('y')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print(data)
        print ("cello the best company ever")
        if data != 'K':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('y')
    if data == 'G':
      keyboard.press('r')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'G':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('r')
    if data == 'H':
      keyboard.press('t')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'H':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('t')
    if data == 'I':
      keyboard.press('5')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'I':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('5')
    if data == 'J':
      keyboard.press('e')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'J':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('e')
   
   
