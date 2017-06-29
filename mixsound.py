import pygame as pg
import time

pg.mixer.init()
pg.init()

a1Note = pg.mixer.Sound(r"sit_still_look_pritty.wav")
a2Note = pg.mixer.Sound(r"sound2.wav")

pg.mixer.set_num_channels(50)
a2Note.play() 
a1Note.play()
time.sleep(5)
    
   
