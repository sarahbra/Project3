from matplotlib.pyplot import *

from numpy import *


filename = "positions.dat"
arr=loadtxt('positions.dat',delimiter=',')
print arr
print arr[0][:-1]
n = size(arr)/4
x = zeros(n)
y = zeros(n)
for i in range(n):
	x[i] = arr[i][2]
	y[i] = arr[i][3]
	#print x[i], y[i]

plot(x,y)
#legend('noe')
title("Euler Two Body Problem (dt=1e-05, n=100000)")
xlabel("X [AU]")
ylabel("Y [AU]")
axis([-1.5,1.5,-1.5,1.5])
show()
