# Code by GVV Sharma
# August 2024
# Released under GNU GPL
# Plotting the circle with diameter AB, where A and B are points on the circle

import numpy as np
import matplotlib.pyplot as plt

# Input parameters
A = np.array([-7, 0])  # Point A
B = np.array([3, 4])   # Point B
C = np.array([-2, 2])  # Center of the circle

# Calculating the radius
r = np.linalg.norm(A - C)  # Radius of the circle

# Generating the circle
theta = np.linspace(0, 2 * np.pi, 100)
circle_x = C[0] + r * np.cos(theta)
circle_y = C[1] + r * np.sin(theta)

# Plotting the circle, diameter AB, and points A, B, and C
plt.plot(circle_x, circle_y, label='Circle')  # Circle plot
plt.plot([A[0], B[0]], [A[1], B[1]], label='Diameter AB', linestyle='--')  # Diameter plot
plt.scatter([A[0], B[0], C[0]], [A[1], B[1], C[1]], color=['red', 'blue', 'green'])  # Points A, B, C
plt.text(A[0], A[1], 'A (-7, 0)', fontsize=12, ha='right')  # Label for A
plt.text(B[0], B[1], 'B (3, 4)', fontsize=12, ha='left')    # Label for B
plt.text(C[0], C[1], 'C (-2, 2)', fontsize=12, ha='right')  # Label for C

# Plot details
plt.axhline(0, color='black', linewidth=0.5)  # X-axis
plt.axvline(0, color='black', linewidth=0.5)  # Y-axis
plt.grid(color='gray', linestyle='--', linewidth=0.5)  # Grid
plt.gca().set_aspect('equal', adjustable='box')  # Equal aspect ratio

plt.title('Circle with Diameter AB')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()

