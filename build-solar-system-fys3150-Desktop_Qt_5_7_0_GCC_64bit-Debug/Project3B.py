from matplotlib.pyplot import pylab

filename = "positions.dat"
datalist = pylab.loadtxt(filename)

for data in datalist:
    pylab.plot( data[:,0], data[:,1])

pylab.legend()
pylab.title("Euler")
pylab.xlabel("X")
pylab.ylabel("Y")
