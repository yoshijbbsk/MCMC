# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import numpy as np

data1_axis1,data1_value1=np.loadtxt("output1.txt",unpack=True)
fig = plt.figure(figsize=(14, 6))

ax1 = fig.add_subplot(121)
ax1.plot(data1_axis1, data1_value1,  color="k")
ax1.set_xlim(-100, 1100)
ax1.set_ylim(-0.1, 1.1)
ax1.set_xlabel("trials(MCS)")
ax1.set_ylabel("magnetization")
ax1.set_title('Metropolis')

data2_axis1,data2_value1=np.loadtxt("output2.txt",unpack=True)
ax2 = fig.add_subplot(122)
ax2.plot(data2_axis1, data2_value1,  color="k")
ax2.set_xlim(-100, 1100)
ax2.set_ylim(-0.1, 1.1)
ax2.set_xlabel("trials(MCS)")
ax2.set_ylabel("magnetization")
ax2.set_title('Heat-bath')

plt.show()
