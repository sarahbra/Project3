from matplotlib.pyplot import *

from numpy import *


filename = "positions.dat"
arr=loadtxt('positions.dat',delimiter=',')
print arr
print arr[0][:-1]
n = size(arr)/3
x = zeros(n)
y = zeros(n)
for i in range(n):
	x[i] = arr[i][0]
	y[i] = arr[i][1]
	print x[i], y[i]

plot(x,y)
legend('noe')
title("Euler")
xlabel("X")
ylabel("Y")
axis([-2,2,-2,2])
show()
