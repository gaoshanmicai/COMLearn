import matplotlib.pyplot as plt
import numpy as np
import time
from math import *
 
#? python中plot实现即时数据动态显示方法,需要保存历史数据
 
plt.ion() #* 开启interactive mode 成功的关键函数
plt.figure(1)
t = [0] # 起始点x
t_now = 0 # x实际值
m = [sin(t_now)] # 起始点y
i=0; 
while True:
    plt.clf() #清空画布上的所有内容
    t_now = i*0.1
    i=i+1
    t.append(t_now)#模拟数据增量流入，保存历史数据
    m.append(sin(t_now))#模拟数据增量流入，展示
    plt.plot(t,m,'-r') # r(代表红色) r+  r  -r   g(绿色)  
    plt.pause(0.01)