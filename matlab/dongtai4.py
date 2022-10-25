import matplotlib.pyplot as plt
import numpy as np
import time
from math import *
 
#  无需保存数据(多条线)
 
plt.ion() #开启interactive mode 成功的关键函数
plt.figure(1)
t = np.linspace(0, 20, 100) #* 等差数列，从0到20生成100个数据
 
for i in range(200):
    y = np.sin(t*i/10.0)
    plt.plot(t, y) # 一条轨迹
    plt.pause(0.01)