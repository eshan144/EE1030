import numpy as np
import matplotlib.pyplot as plt

# Points
A = np.array([-7, 0])
B = np.array([3, 4])
O = np.array([-2, 2])

# Radius of the circle (distance from O to B)
radius = np.linalg.norm(B - O)

# Circle
theta = np.linspace(0, 2*np.pi, 300)
x_circle = O[0] + radius * np.cos(theta)
y_circle = O[1] + radius * np.sin(theta)

# Plot
plt.figure()
plt.plot(x_circle, y_circle, label='Circle')
plt.scatter([A[0], B[0], O[0]], [A[1], B[1], O[1]], color=['red', 'blue', 'green'])

# Annotate Points
plt.text(A[0], A[1], 'A(-7, 0)', fontsize=12, ha='right')
plt.text(B[0], B[1], 'B(3, 4)', fontsize=12, ha='right')
plt.text(O[0], O[1], 'O(-2, 2)', fontsize=12, ha='right')

# Plot the diameter AB
plt.plot([A[0], B[0]], [A[1], B[1]], 'k--', label='Diameter AB')

# Set limits and aspect ratio
plt.xlim(-10, 5)
plt.ylim(-3, 7)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid()
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

plt.legend()
plt.title('Circle with Diameter AB')
plt.savefig('circle_plot.png')
plt.show()

