import keyboard
import time
import serial
    
Var1=serial.Serial('COM19',9600)
time.sleep(1)
while 1:
  data=0
  data=Var1.read().decode('ascii');
  print("out of all boundations")
  print(data)
  if data == 'A':
    keyboard.press('w')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
        #print(data)
      print ("cello the best company ever")
      if data != 'A':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('w')
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
  if data == '2':
    keyboard.press('n')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != '2':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('n')
  if data == 'k':
    keyboard.press('y')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'k':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('y')
  if data == 'g':
    keyboard.press('e')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'g':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('e')
  if data == 'h':
    keyboard.press('t')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'h':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('t')
  if data == 'i':
    keyboard.press('5')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'i':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('5')
  if data == 'j':
    keyboard.press('e')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'j':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('e')
  if data == '1':
    keyboard.press('w')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != '1':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('w')
  if data == 'x':
    keyboard.press('r')
    print ("hell is here friend")
    while 1:
            #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'x':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('r')
  if data == 'a':
    keyboard.press('o')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
        #print(data)
      print ("cello the best company ever")
      if data != 'a':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('o')
  if data == 'b':
    keyboard.press('p')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello then best company ever")
      if data != 'b':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('p')
  if data == 'c':
      keyboard.press('i')
      print ("hell is here friend")
      while 1:
        #time.sleep(.1)
        data = Var1.read().decode('ascii');
        print ("cello the best company ever")
        if data != 'c':
          print ("cello doesnt loook so good now huh")
          break
      keyboard.release('i')
  if data == 'd':
    keyboard.press('7')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'd':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('7')
  if data == 'e':
    keyboard.press('y')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'e':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('y')
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
    keyboard.press('p')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'G':
          print ("cello doesnt loook so good now huh")
          break
    keyboard.release('p')
  if data == 'H':
    keyboard.press(']')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'H':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release(']')
  if data == 'I':
    keyboard.press('=')
    print ("hell is here friend")
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'I':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('=')
  if data == 'J':
    keyboard.press('[')
    while 1:
        #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'J':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('[')
  if data == 'E':
    keyboard.press('o')
    print ("hell is here friend")
    while 1:
            #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'E':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('o')
  if data == 'X':
    keyboard.press('r')
    print ("hell is here friend")
    while 1:
            #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != 'X':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('r')
  if data == '3':
    keyboard.press('7')
    print ("hell is here friend")
    while 1:
            #time.sleep(.1)
      data = Var1.read().decode('ascii');
      print ("cello the best company ever")
      if data != '3':
        print ("cello doesnt loook so good now huh")
        break
    keyboard.release('7')
   
   