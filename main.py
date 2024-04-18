import matplotlib.pyplot as plt
import numpy as np


data = np.loadtxt("out.txt")
fig, ax = plt.subplots(figsize=(8,6))
img = ax.imshow(data, cmap="viridis", origin="lower")
fig.colorbar(img, ax=ax, label="Hits")
ax.set_title("Hits")
ax.set_xlabel("X index")
ax.set_ylabel("Y index")
ax.grid(True, which="both", linestyle="--", linewidth=0.5, color="black")
fig.savefig("test.png")