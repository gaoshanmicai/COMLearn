
import matplotlib.pyplot as plt
import numpy as np
import time
from math import *
 
#? 无需保存数据
 
plt.ion() #开启interactive mode 成功的关键函数
plt.figure(1)
t = [0]
t_now = 0
m = [sin(t_now)]
 
for i in range(500):
	# plt.clf() # 清空画布上的所有内容。此处不能调用此函数，不然之前画出的点，将会被清空。
    t_now = i*0.1
    
    plt.plot(t_now,sin(t_now),'.') # 第次对画布添加一个点，覆盖式的。
 
    plt.pause(0.001) 