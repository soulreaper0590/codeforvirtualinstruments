import serial
import pygame as pg
import time

pg.mixer.init()
pg.init()

a1Note = pg.mixer.Sound(r"lowerone.wav")
a2Note = pg.mixer.Sound(r"upperone.wav")

pg.mixer.set_num_channels(50)

ser = serial.Serial("/dev/ttyACM0", 9600)
p = 0
while 1:
	print ser.readline() 
	a = ser.readline() 
	
	print a[0] + "fuckyou"
	if(a[0]=='4'):
		print "fuck you"
		a2Note.play()
		time.sleep(.4)
	if(a[0]=='2'):
		a1Note.play()
		time.sleep(.4)