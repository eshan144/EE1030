# Code by GVV Sharma
# August 2024
# Released under GNU GPL
# Plotting the internal and external division of a line segment PQ

import numpy as np
import matplotlib.pyplot as plt

# Load the division points from the text file
points = np.loadtxt("division_points.txt")

# Extracting the internal and external division points
R_internal = points[0]  # Internal division point
R_external = points[1]  # External division point

# Define points P and Q
P = np.array([3, -2])   # Point P
Q = np.array([1, 1])    # Point Q

plt.figure(figsize=(10, 5))

# Plotting Internal Division
plt.subplot(1, 2, 1)
plt.plot([P[0], Q[0]], [P[1], Q[1]], 'bo-', label="Line PQ")
plt.plot(R_internal[0], R_internal[1], 'ro', label="Internal Division R")
plt.text(P[0], P[1], 'P', fontsize=12, ha='right')
plt.text(Q[0], Q[1], 'Q', fontsize=12, ha='right')
plt.text(R_internal[0], R_internal[1], 'R', fontsize=12, ha='right')
plt.title('Internal Division of Line Segment')
plt.grid(True)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.legend()

# Plotting External Division
plt.subplot(1, 2, 2)
plt.plot([P[0], Q[0]], [P[1], Q[1]], 'bo-', label="Line PQ")
plt.plot(R_external[0], R_external[1], 'ro', label="External Division R")
plt.text(P[0], P[1], 'P', fontsize=12, ha='right')
plt.text(Q[0], Q[1], 'Q', fontsize=12, ha='right')
plt.text(R_external[0], R_external[1], 'R', fontsize=12, ha='right')
plt.title('External Division of Line Segment')
plt.grid(True)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.legend()

plt.tight_layout()
plt.show()

