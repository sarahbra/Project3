from matplotlib.pyplot import *

from numpy import *


filename = "positions.dat"
arr=loadtxt(filename,delimiter=',')
#print arr
#print arr[0][:-1]
n = size(arr)/6
x = zeros(n)
y = zeros(n)
for i in range(n):
	x[i] = arr[i][2]
	y[i] = arr[i][3]
	#print x[i], y[i]

plot(x,y)
#legend('noe')
title("3-body problem Earth-Jupiter (dt=1e-05, n=300000, mass 1000 times larger)")
xlabel("X [AU]")
ylabel("Y [AU]")
axis([-1.5,1.5,-1.5,1.5])
show()
