import numpy as np
import matplotlib.pyplot as plt

# Create some mock data
t = np.arange(0.1, 5.0, 0.1)
data2 = [0.342417,0.336381,0.346076,0.348499,0.345646]
data1 = [52.42,52.61,52.43,52.18,52.40]
Power =[17.9495,17.6970,18.1448,18.1847,18.1119]

fig, ax1 = plt.subplots()

color = 'tab:red'
ax1.set_xlabel('time (s)')
ax1.set_ylabel('volt', color=color)
ax1.plot(t, data1, color=color)
ax1.tick_params(axis='y', labelcolor=color)

ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

color = 'tab:blue'
ax2.set_ylabel('current', color=color)  # we already handled the x-label with ax1
ax2.plot(t, data2, color=color)
ax2.tick_params(axis='y', labelcolor=color)

fig.tight_layout()  # otherwise the right y-label is slightly clipped
plt.show()