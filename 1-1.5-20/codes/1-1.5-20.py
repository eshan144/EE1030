# Code by GVV Sharma
# August 2024
# Released under GNU GPL
# Plotting the circle with points generated from C code

import numpy as np
import matplotlib.pyplot as plt

# Load the points from the text file
points = np.loadtxt("circle_points.txt")

# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]

# Define points A, B, and C
A = np.array([-7, 0])
B = np.array([3, 4])
C = np.array([-2, 2])

# Plot the circle
plt.figure()
plt.plot(x, y, label='Circle')  # Plot the circle using points from the file
plt.plot([A[0], B[0]], [A[1], B[1]], label='Diameter AB', linestyle='--')  # Diameter AB
plt.scatter([A[0], B[0], C[0]], [A[1], B[1], C[1]], color=['red', 'blue', 'green'])  # Points A, B, C
plt.text(A[0], A[1], 'A (-7, 0)', fontsize=12, ha='right')  # Label for A
plt.text(B[0], B[1], 'B (3, 4)', fontsize=12, ha='left')    # Label for B
plt.text(C[0], C[1], 'C (-2, 2)', fontsize=12, ha='right')  # Label for C

# Additional plot settings
plt.axhline(0, color='black', linewidth=0.5)  # X-axis
plt.axvline(0, color='black', linewidth=0.5)  # Y-axis
plt.grid(color='gray', linestyle='--', linewidth=0.5)  # Grid
plt.gca().set_aspect('equal', adjustable='box')  # Equal aspect ratio

plt.title('Circle with Diameter AB')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()

