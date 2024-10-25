import numpy as np
import matplotlib.pyplot as plt

# Load area information from the text file
with open("area_exterior.txt", "r") as f:
    area_exterior = float(f.readline().strip())  # Read the first line as a float

print(f"Area exterior to the parabola: {area_exterior}")

# Circle parameters
r = 4  # Radius of the circle
theta = np.linspace(0, 2 * np.pi, 100)  # Full circle

# Circle coordinates
circle_x = r * np.cos(theta)
circle_y = r * np.sin(theta)

# Parabola coordinates
x_parabola = np.linspace(0, 4, 100)
y_parabola_upper = np.sqrt(6 * x_parabola)
y_parabola_lower = -y_parabola_upper  # Lower half of the parabola

# Plotting the circle and the area of the circle
plt.figure(figsize=(12, 6))

# Plot the circle
plt.plot(circle_x, circle_y, label='Circle: $x^2 + y^2 = 16$', color='blue')
plt.plot(circle_x, -circle_y, color='blue')  # Plot the lower half of the circle

# Highlight the interior area of the circle under the parabola
plt.fill_between(x_parabola, 0, y_parabola_upper, color='lightgreen', alpha=0.5, label='Interior Area $A_i$')

# Adding labels and limits
plt.xlim(-5, 5)
plt.ylim(-5, 5)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.title('Circle and Parabola Areas')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')

plt.show()

# Plotting the exterior area
plt.figure(figsize=(12, 6))

# Plot the circle
plt.plot(circle_x, circle_y, label='Circle: $x^2 + y^2 = 16$', color='blue')
plt.plot(circle_x, -circle_y, color='blue')  # Plot the lower half of the circle

# Highlight the exterior area of the circle that is outside the parabola
x_fill = np.linspace(0, r, 100)
y_fill_upper = np.sqrt(6 * x_fill)
y_fill_lower = r * np.sin(np.arccos(x_fill/r))

# Fill the exterior area
plt.fill_between(x_fill, y_fill_upper, y_fill_lower, where=(y_fill_upper > y_fill_lower), color='lightcoral', alpha=0.5, label='Exterior Area $A$')

# Adding labels and limits
plt.xlim(-5, 5)
plt.ylim(-5, 5)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.title('Exterior Area of the Circle')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')

plt.show()

