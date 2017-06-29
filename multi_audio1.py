import pyaudio
import wave
sound1 = wave.open("sound3.wav", 'rb')
sound2 = wave.open("sound2.wav", 'rb')

def callback(in_data, frame_count, time_info, status):
    data1 = sound1.readframes(frame_count)
    data2 = sound2.readframes(frame_count)
    decodeddata1 = numpy.fromstring(data1, numpy.int16)
    decodeddata2 = numpy.fromstring(data2, numpy.int16)
    newdata = (decodeddata1 * 0.5 + decodeddata2* 0.5).astype(numpy.int16)
    return (result.tostring(), pyaudio.paContinue)
