# Code by GVV Sharma
# August 2024
# Released under GNU GPL
# Plotting the distance between points (0, 5) and (-5, 0)

import numpy as np
import matplotlib.pyplot as plt

with open("distance_points.txt", "r") as f:
    distance = float(f.read().strip())

P = np.array([0, 5])
Q = np.array([-5, 0])

plt.figure(figsize=(6, 6))
plt.plot([P[0], Q[0]], [P[1], Q[1]], 'bo-', label="Line PQ")
plt.scatter(P[0], P[1], color='red', label="Point P (0, 5)")
plt.scatter(Q[0], Q[1], color='green', label="Point Q (-5, 0)")

plt.text(-2.5, 2.5, f'Distance = {distance:.2f}', fontsize=12, ha='center')

plt.title('Distance Between Points (0, 5) and (-5, 0)')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True)
plt.gca().set_aspect('equal', adjustable='box')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()

