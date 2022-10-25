import numpy as np
import matplotlib.pyplot as plt
import os
import wave
 
f = wave.open('filename.wav','rb')
params = f.getparams()
nchannels, sampwidth, framerate,nframes = params[:4]

strData = f.readframes(nframes)
waveData = np.fromstring(strData,dtype=np.short)
waveData = waveData * 1.0/max(abs(waveData))
waveData = np.reshape(waveData,[nframes,nchannels]).T 
f.close()
framelength = 0.025 
framesize = framelength*framerate 
 
nfftdict = {}
lists = [32,64,128,256,512,1024]
for i in lists:
    nfftdict[i] = abs(framesize - i)
sortlist = sorted(nfftdict.items(), key=lambda x: x[1])
framesize = int(sortlist[0][0])
 
NFFT = framesize 
overlapSize = 1.0/3 * framesize 
overlapSize = int(round(overlapSize))
spectrum,freqs,ts,fig = plt.specgram(waveData[0],NFFT = NFFT,Fs =framerate,window=np.hanning(M = framesize),noverlap=overlapSize,mode='default',scale_by_freq=True,sides='default',scale='dB',xextent=None)#绘制频谱图
          
plt.ylabel('Frequency')
plt.xlabel('Time')
plt.title("name")
plt.show()