import numpy as np
import matplotlib.pyplot as plt

def bezier_curve(control_points, num_points=100):
    t = np.linspace(0, 1, num_points)
    curve = np.zeros((num_points, 2))
    for i in range(num_points):
        curve[i] = (1-t[i])**3 * control_points[0] + \
                   3*(1-t[i])**2 * t[i] * control_points[1] + \
                   3*(1-t[i]) * t[i]**2 * control_points[2] + \
                   t[i]**3 * control_points[3]
    return curve

# define the control points
control_points = np.array([[0, 0], [1, 1], [2, 2], [3, 0]])

# generate the bezier curve
curve = bezier_curve(control_points)

# plot the control points and the curve
plt.plot(control_points[:,0], control_points[:,1], 'ro')
plt.plot(curve[:,0], curve[:,1], 'b')
plt.show()
