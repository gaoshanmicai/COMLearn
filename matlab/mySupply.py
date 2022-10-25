import matplotlib.pyplot as plt
import numpy as np


sVlot = np.arange(3.4,4.2,0.1)
Amp = [3.05,3.02,2.96,2.88,2.73,2.64,2.51,2.40,2.33]
#Amp =[2.33,2.40,2.51,2.64,2.73,2.88,2.96,3.02,3.05]
Ovlot = [4.62,4.73,4.85,4.94,4.96,4.96,4.96,4.95,4.95]

fig, ax1 = plt.subplots()

color = 'tab:red'
ax1.set_xlabel('Amp (A)')
ax1.set_ylabel('Volt', color=color)
ax1.plot(Amp, sVlot, color=color)
ax1.plot(Amp,Ovlot,'blue')
ax1.tick_params(axis='y', labelcolor=color)

legend = plt.legend(["Vin", "Vout"],title =" Voltage")
plt.grid(color = 'r', linestyle = '--', linewidth = 0.5)

'''
ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

color = 'tab:blue'
ax2.set_ylabel('current', color=color)  # we already handled the x-label with ax1
ax2.plot(sAmp, Ovlot, color=color)
ax2.tick_params(axis='y', labelcolor=color)
'''
fig.tight_layout()  # otherwise the right y-label is slightly clipped
plt.show()