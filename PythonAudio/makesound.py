import wave,math,struct
from winsound import PlaySound,SND_FILENAME
import matplotlib.pyplot as plt
# from playsound import playsound
def generate(T,total,volume,sampwidth,sine=False):
    # T: 周期, total 总长度, 以帧为单位
    volume = min(volume * 2**(sampwidth*8),2**(sampwidth*8) - 1)
    if not sine:
        h = T / 2
        for i in range(total):
            if i % T >= h:
                yield volume
            else:
                yield 0
    else:
        w = 2 * math.pi  / T; r = volume / 2
        for i in range(total):
            # T = 2*pi / w
            yield int(math.sin(w * i) * r + r)

file = 'test.wav'
len_= 0.01 # 秒
frequency = 2700
sampwidth = 2
framerate = 22050
sine=True
volume = 255
# 8位的wav文件的一帧是无符号8位整数, 而16位的一帧是有符号的整数(-32768至32767)。
if sampwidth == 1: # 8位
    lst = list(generate(framerate / frequency, int(framerate*len_),
                    volume,sampwidth,sine))
    data = bytes(lst)
elif sampwidth == 2:
    data = b'' # 16位
    lst = list(generate(framerate/frequency,
                        int(framerate*len_),
                        volume,sampwidth,sine))
    for digit in lst:
        data += struct.pack('<h',digit - 32768)

with wave.open(file,'wb') as f:
    # --snip-- (省略)
    f.setnchannels(1)
    f.setsampwidth(sampwidth)
    f.setframerate(framerate)
    f.writeframes(data)


#PlaySound('test.wav')
# playsound('test.wav')
PlaySound(file,SND_FILENAME)


plt.plot(range(len(lst)),lst)
plt.savefig('wave.png')


with wave.open(file,'rb') as f1:
    sampwidth = f1.getsampwidth()
    framerate = f1.getframerate()
    nframes1=f1.getnframes()
    data1=f1.readframes(nframes1)
LEN =len(data1)
    # print(data1)

with open(file+".c",'w') as f2:
    f2.write("uint8_t sine_wave[%d]={\n"%LEN)
    for f in data1:
        f2.write("0x%02x, "%f)
    f2.write("};\n\n")
# f2.write(data1)
    f2.close()

