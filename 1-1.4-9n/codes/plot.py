import numpy as np
import matplotlib.pyplot as plt

P = np.array([3, -2])
Q = np.array([1, 1])

m_internal = 1
n_internal = 2

m_external = 2
n_external = 1

R_internal = (m_internal * P + n_internal * Q) / (m_internal + n_internal)
R_external = (m_external * Q - n_external * P) / (m_external - n_external)

plt.figure(figsize=(10, 5))

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


