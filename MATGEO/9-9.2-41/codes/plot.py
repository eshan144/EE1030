import numpy as np
import matplotlib.pyplot as plt

# Circle parameters
r = np.sqrt(32)
theta = np.linspace(0, 2 * np.pi, 100)  # Full circle

# Circle coordinates
circle_x = r * np.cos(theta)
circle_y = r * np.sin(theta)

# Line coordinates
line_x = np.linspace(0, r, 100)
line_y = line_x  # y = x

# Find the intersection points between the circle and the line
intersection_x = np.linspace(0, r, 100)
intersection_y = np.sqrt(32 - intersection_x**2)

# Plot the area
plt.figure(figsize=(8, 8))

# Highlighting the area below the line y=x and above the x-axis in the first quadrant
plt.fill_between(intersection_x, 0, np.minimum(intersection_y, line_y), 
                 color='lightblue', alpha=0.5, label='Enclosed Area')

# Plot the entire circle
plt.plot(circle_x, circle_y, label='Circle: $x^2 + y^2 = 32$', color='blue')

# Plot the line
plt.plot(line_x, line_y, label='Line: $y = x$', color='red')

# Plot axes
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.xlim(-r - 1, r + 1)  # Extend x-limits to show full circle
plt.ylim(-r - 1, r + 1)  # Extend y-limits to show full circle
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')

plt.show()



