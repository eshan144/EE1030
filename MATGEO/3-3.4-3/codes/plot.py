import numpy as np
import matplotlib.pyplot as plt

# Load the square vertices from the text file
points = np.loadtxt("square_points.txt")

# Extract x and y coordinates
x = points[:, 0]
y = points[:, 1]

# Plot the square
plt.plot(x, y, 'bo-', label='Square')
plt.fill(x, y, 'lightblue', alpha=0.5)  # Filling the square

plt.xlim([-1, 4])
plt.ylim([-1, 4])

plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Square of Side 3 cm')
plt.grid(True)
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')

plt.show()

