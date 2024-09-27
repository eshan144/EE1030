import numpy as np
import matplotlib.pyplot as plt

# Function to calculate y-values for the line
def line_y(a, b, c, x):
    return -(a * x + c) / b

# Read line coefficients from the file
with open('line_coefficients.txt', 'r') as f:
    lines = f.readlines()

# Extract the coefficients from the file
a1, b1, c1 = map(float, lines[1].strip().split())
a2, b2, c2 = map(float, lines[3].strip().split())

# Generate x values for plotting
x_values = np.linspace(-10, 10, 400)

# Calculate y values for both lines
y_values_1 = line_y(a1, b1, c1, x_values)
y_values_2 = line_y(a2, b2, c2, x_values)

# Check the relationship between the lines
def check_line_relationship(a1, b1, c1, a2, b2, c2):
    ratio_a = a1 / a2
    ratio_b = b1 / b2
    
    if ratio_a == ratio_b:
        ratio_c = c1 / c2
        if ratio_a == ratio_c:
            return "coincident"
        else:
            return "parallel"
    else:
        return "intersecting"

# Determine the type of lines
line_type = check_line_relationship(a1, b1, c1, a2, b2, c2)

# Plot the lines
plt.figure(figsize=(6, 6))
plt.plot(x_values, y_values_1, label="Line 1: x - 2y + 3 = 0")
plt.plot(x_values, y_values_2, label="Line 2: 2x - 4y = 5")

plt.title(f'Type of Lines: {line_type.capitalize()}')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(True)
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()

