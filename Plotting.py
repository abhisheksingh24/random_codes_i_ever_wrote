import numpy as np
import pylab as pl
import math

dots = 1000000
# Make an array of x values

low = 1.0
high = 9.0

step = (high-low)/dots

x = np.arange(low+step, high, step)

c = 1.0
# Make an array of y values for each x value
y1 = [math.sqrt(16.0 - math.pow(i-5.0, 2)) + 5.0 for i in x]
y2 = [-1.0*math.sqrt(16.0 - math.pow(i-5.0, 2)) + 5.0 for i in x]
#y = y1+y2

#x = [i for i in x for _ in range(2)]
#print(len(x), " ", len(y))
# use pylab to plot x and y
pl.plot(x, y1, 'r+')
pl.plot(x, y2, 'r+')
# give plot a title
pl.title('Plot of y vs. x')
# make axis labels
pl.xlabel('x axis')
pl.ylabel('y axis')
# set axis limits
#pl.xlim(0.0, 0.0001)
#pl.ylim(0.0, 1.0)
# show the plot on the screen
pl.show()

