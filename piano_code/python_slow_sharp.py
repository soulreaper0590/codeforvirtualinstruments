import keyboard
import time
import serial
    
Var1=serial.Serial('COM12',9600)
time.sleep(1)
while 1:
    data=0
    data=Var1.read()
    print(data)
    if data == b'A':
      keyboard.press('z')
      print ("hell is here friend")
      while 1:
        time.sleep(2)
        data = Var1.read()
        print ("cello the best company ever")
        if data != b'A':
            print ("cello doesnt loook so good now huh")
            break
      keyboard.release('z')
