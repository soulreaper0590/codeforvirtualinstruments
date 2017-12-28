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
      keyboard.press('y')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        #print(data)
        print ("cello the best company ever")
        if data != 'A':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('y')
    if data == 'B':
      keyboard.press('i')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'B':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('i')
    if data == 'C':
      keyboard.press('o')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'C':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('o')
    if data == 'D':
      keyboard.press('p')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'D':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('p')
    if data == 'E':
      keyboard.press('[')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'E':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('[')
    if data == 'K':
      keyboard.press('7')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print(data)
        print ("cello the best company ever")
        if data != 'K':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('7')
    if data == 'G':
      keyboard.press('q')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'G':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('q')
    if data == 'H':
      keyboard.press('w')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'H':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('w')
    if data == 'I':
      keyboard.press('r')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'I':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('r')
    if data == 'J':
      keyboard.press('t')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'J':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('t')
   
   
