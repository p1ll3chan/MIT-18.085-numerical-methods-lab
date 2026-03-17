import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("output.txt")

x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.xlabel("Mass index")
plt.ylabel("Displacement")
plt.title("Mass-Spring Displacement")
plt.show()
