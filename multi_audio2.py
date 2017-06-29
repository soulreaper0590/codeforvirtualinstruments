import threading
import audiolazy
from audiolazy import AudioIO
Somelist = ["strip_that_down.mp3",	"sound2.wav"]
sound = Somelist
with AudioIO(True) as player:
  t = threading.Thread(target=player.play, args=(sound,), kwargs={'rate':44100})
  t.start()
