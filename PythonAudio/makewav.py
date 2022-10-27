import wave,math,struct
from winsound import PlaySound,SND_FILENAME
import matplotlib.pyplot as plt


file ='art_of_gard_448K'
with wave.open(file+'.bin','rb') as f1:
    sampwidth = f1.getsampwidth()
    framerate = f1.getframerate()
    nframes1=f1.getnframes()
    data1=f1.readframes(nframes1)
LEN =len(data1) 

i=0
with open(file +".c",'w') as f2:
    f2.write("#include"+"\""+file+".h"+"\" \n\n")
    f2.write("uint8_t "+file+"[%d]={\n"%LEN)
    for f in data1:
        f2.write("0x%02X"%f)
        f2.write(",")
        i=i+1
        if i%16 == 0:
            f2.write("\n")
    f2.write("};\n\n")
# f2.write(data1)
    f2.close()