'''
from mpl_toolkits.mplot3d import Axes3D
import mpl_toolkits.mplot3d.art3d as art3d
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Circle
from tkinter import *
'''
#0.5*x^4+0.5y^4

'''

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Scatter graph
N = 100
X = np.random.uniform(-1, 1, N)
Y = np.random.uniform(-1, 1, N)
Z = np.random.uniform(-2, 2, N)
ax.scatter(X, Y, Z)

# Cylinder
x=np.linspace(-1, 1, 100)
z=np.linspace(-2, 2, 100)
Xc, Zc=np.meshgrid(x, z)
Yc = np.sqrt(1-Xc**2)

# Draw parameters
rstride = 20
cstride = 10
ax.plot_surface(Xc, Yc, Zc, alpha=0.2, rstride=rstride, cstride=cstride)
ax.plot_surface(Xc, -Yc, Zc, alpha=0.2, rstride=rstride, cstride=cstride)

ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
plt.show()
'''
# Create the data.

import numpy as np
#import Tkinter
from mayavi import mlab
'''
x1,y1,z1 = (-1.5,2,0)
x2,y2,z2 = (1.5,2,0)
x3,y3,z3 = (-2.5,0,0)
x4,y4,z4 = (-1.5,-2,0)
x5,y5,z5 = (1.5,-2,0)
x6,y6,z6 = (2.5,0,0)

x7,y7,z7 = (-1.5,2,12)
x8,y8,z8 = (1.5,2,12)
x9,y9,z9 = (-2.5,0,12)
x10,y10,z10 = (-1.5,-2,12)
x11,y11,z11 = (1.5,-2,12)
x12,y12,z12 = (2.5,0,12)

box_points = np.array([[x1,y1,z1],[x2,y2,z2],[x3,y3,z3],[x4,y4,z4],[x5,y5,z5],[x6,y6,z6],[x7,y7,z7,],[x8,y8,z8],[x9,y9,z9],[x10,y10,z10],[x11,y11,z11],[x12,y12,z12]])
mlab.points3d(box_points[:, 0], box_points[:, 1], box_points[:, 2],
                     mode="axes", color=(1, 0, 0))

mlab.mesh([[x1, x2],[x3, x4],[x5, x6],[x7, x8],[x9, x10],[x11, x12]],  # | => x coordinate

                [[y1, y2],[y3, y4],[y5, y6],[y7, y8],[y9, y10],[y11, y12]],  # | => y coordinate

                 [[z1, z2],[z3, z4],[z5, z6],[z7, z8],[z9, z10],[z11, z12]],  # | => z coordinate

                 color=(0, 0, 0))  # black

mlab.mesh([[x1, x3], [x7, x9]],
                 [[y1, y3], [y7, y9]],
                 [[z1, z3], [z7, z9]],
                 color=(1, 0, 0))  # red

mlab.mesh([[x3, x4], [x9, x10]],
                 [[y3, y4], [y9, y10]],
                 [[z3, z4], [z9, z10]],
                 color=(0, 0, 1))  # blue

mlab.mesh([[x4, x5], [x10, x11]],
                 [[y4, y5], [y10, y11]],
                 [[z4, z5], [z10, z11]],
                 color=(1, 1, 0))  # yellow

mlab.mesh([[x5, x6], [x11, x12]],
                 [[y5, y6], [y11, y12]],
                 [[z5, z6], [z11, z12]],
                 color=(1, 1, 1))  # white

mlab.mesh([[x6, x2], [x12, x8]],
                 [[y6, y2], [y12, y8]],
                 [[z6, z2], [z12, z8]],
                 color=(1, 0, 1))  # pink

mlab.mesh([[x2, x1], [x8, x7]],
                 [[y2, y1], [y8, y7]],
                 [[z2, z1], [z8, z7]],
                 color=(1, 1, 0))  # yellow


#test con modelo ply

'''
vaso = 'Hexagonal.ply';

mlab.pipeline.surface(mlab.pipeline.open(vaso))

mlab.show()

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

us = np.linspace(0, 2 * np.pi, 7)
zs = np.linspace(0, 10, 2)

us, zs = np.meshgrid(us, zs)

xs = 10 * np.cos(us)
ys = 10 * np.sin(us)
ax.plot_surface(xs, ys, zs, color='b')

plt.show()
plt.savefig("hexagon.png")