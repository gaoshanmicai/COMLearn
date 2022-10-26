# 所使用到的库函数
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft

# 简单定义一个FFT函数
def myfft(x,t):
    fft_x = fft(x)                                            #  fft计算
    amp_x = abs(fft_x)/len(x)*2                                 # 纵坐标变换
    label_x = np.linspace(0,int(len(x)/2)-1,int(len(x)/2))    # 生成频率坐标
    amp = amp_x[0:int(len(x)/2)]                              # 选取前半段计算结果即可
    # amp[0] = 0                                              # 可选择是否去除直流量信号
    fs =1/( t[2]-t[1])                                        # 计算采样频率
    fre = label_x/len(x)*fs                                   # 频率坐标变换
    pha = np.unwrap(np.angle(fft_x))                          # 计算相位角并去除2pi跃变
    return amp,fre,pha                                        # 返回幅度和频率


t = np.linspace(0,5*np.pi,200)                                # 时间坐标

print(t)

print("the len of t is\n")

print(len(t))
x = np.sin(2*np.pi*t) + (1/2)*np.sin(np.pi*(1/2)*t)  +np.sin(np.pi*t) +np.sin(3*np.pi*t)                                 # 正弦函数

amp,fre,pha= myfft(x,t)                                       # 调用函数

# 绘图
plt.figure()
plt.plot(t,x)
plt.title('Signal')
plt.xlabel('Time / s')
plt.ylabel('Intencity / cd')

plt.figure()
plt.plot(fre,amp)
plt.title('Amplitute-Frequence-Curve')
plt.ylabel('Amplitute / a.u.')
plt.xlabel('Frequence / Hz')
plt.show()
