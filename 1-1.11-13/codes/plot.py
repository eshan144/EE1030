import numpy as np
import matplotlib.pyplot as plt

with open("direction_cosines.txt", "r") as f:
    direction_cosines = np.array([float(x) for x in f.read().split()])

l, m, n = direction_cosines

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.quiver(0, 0, 0, l, m, n, color='blue', length=1.0, normalize=True)

ax.set_xlim([-1, 1])
ax.set_ylim([-1, 1])
ax.set_zlim([-1, 1])

ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')
ax.set_title('Direction Cosines of a Line')

ax.quiver(0, 0, 0, 1, 0, 0, color='red', length=1.0, normalize=True)
ax.quiver(0, 0, 0, 0, 1, 0, color='green', length=1.0, normalize=True)
ax.quiver(0, 0, 0, 0, 0, 1, color='orange', length=1.0, normalize=True)

plt.show()

