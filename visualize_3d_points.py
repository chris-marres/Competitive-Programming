#imports
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def cuboid_data(center, size):
    # suppose axis direction: x: to left; y: to inside; z: to upper
    # get the (left, outside, bottom) point
    o = [a - b / 2 for a, b in zip(center, size)]
    # get the length, width, and height
    l, w, h = size
    x = [[o[0], o[0] + l, o[0] + l, o[0], o[0]],  # x coordinate of points in bottom surface
         [o[0], o[0] + l, o[0] + l, o[0], o[0]],  # x coordinate of points in upper surface
         [o[0], o[0] + l, o[0] + l, o[0], o[0]],  # x coordinate of points in outside surface
         [o[0], o[0] + l, o[0] + l, o[0], o[0]]]  # x coordinate of points in inside surface
    y = [[o[1], o[1], o[1] + w, o[1] + w, o[1]],  # y coordinate of points in bottom surface
         [o[1], o[1], o[1] + w, o[1] + w, o[1]],  # y coordinate of points in upper surface
         [o[1], o[1], o[1], o[1], o[1]],          # y coordinate of points in outside surface
         [o[1] + w, o[1] + w, o[1] + w, o[1] + w, o[1] + w]]    # y coordinate of points in inside surface
    z = [[o[2], o[2], o[2], o[2], o[2]],                        # z coordinate of points in bottom surface
         [o[2] + h, o[2] + h, o[2] + h, o[2] + h, o[2] + h],    # z coordinate of points in upper surface
         [o[2], o[2], o[2] + h, o[2] + h, o[2]],                # z coordinate of points in outside surface
         [o[2], o[2], o[2] + h, o[2] + h, o[2]]]                # z coordinate of points in inside surface

    return np.array(x), np.array(y), np.array(z)

def get_fix_mins_maxs(mins, maxs):
    deltas = (maxs - mins) / 12.
    mins = mins + deltas / 4.
    maxs = maxs - deltas / 4.
    
    return [mins, maxs]
    
minmax = get_fix_mins_maxs(0, 100)

# first create a list of random 3d points. 100 points with x,y,z in range 0-100
points = np.random.randint(0,100,(50,3))

"""
# create a list of 3d points with every intiger point in range {0-100, 0-100, 0-100} and step 10
x = np.arange(0, 100, 10)
y = np.arange(0, 100, 10)
z = np.arange(0, 100, 10)
points = np.array(np.meshgrid(x, y, z)).T.reshape(-1,3)

# keep only the point in x range 40-60
points = points[(points[:,0] >= 40) & (points[:,0] <= 60)]

# sort points with a < b, if a.x < b.x, if a.x == b.x, a.y < b.y, if a.x == b.x and a.y == b.y, a.z < b.z
points = points[np.lexsort((points[:,2], points[:,1], points[:,0]))]
# sort by x
points = points[points[:,0].argsort()]
# sort by y
points = points[points[:,1].argsort()]
# sort by z
points = points[points[:,2].argsort()]

points = points[50:77]
"""

# create a scatter plot
fig = plt.figure()
plt.tight_layout()
ax = fig.add_subplot(111, projection='3d')
ax.grid(False)
ax.scatter(points[:,0], points[:,1], points[:,2], c='black', marker='o', s=10)

# Set each axis limits
ax.set_xlim(minmax)
ax.set_ylim(minmax) 
ax.set_zlim(minmax) 

# add a colored cuboid surface with a x range of 20-40, y range of 0-100 and z range of 0-100
x, y, z = cuboid_data([50, 50, 50], [20, 100, 100])
ax.plot_surface(x, y, z, color='red', alpha=0.1)
# add edjes to the cuboid
ax.plot_wireframe(x, y, z, color='red', alpha=0.2)



plt.savefig('3d_scatter.png')


