import pygame as pg
import time
while 1:
	left=serial.Serial("COM22",9600)
	right=serial.Serial("COM22",9600)
	left1=left.read()
	right1=right.read()
	left.flushInput()
	right.flushInput()
	pg.mixer.init()
	pg.init()

	a1Note = pg.mixer.Sound(r"/home/prakhar0590/Downloads/AWESOME.WAV")
	a2Note = pg.mixer.Sound(r"/home/prakhar0590/Downloads/ANGELS_F.WAV")

	pg.mixer.set_num_channels(50)
	if left1=='w'
		a2Note.play() 
	if right1=='r'
		a1Note.play()

	    
	   
