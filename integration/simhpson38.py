#!/usr/bin/python3.6

def function(x):
    return 1/(3*x+5)

def simhpson(a, b, n):
    h = (b-a)/(3*n)
    N = int(3*n)

    px = function(a)
    for i in range(N-1):
        if (i+1)%3 is 0:
            px += 2*function(a+(i+1)*h)
        else:
            px += 3*function(a+(i+1)*h)
    px += function(b)
    px = (3*h*px)/8
    return px

a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))
n = float(input("Enter no. of intervals: "))

px = simhpson(a, b, n)
print("The value of integral is", px)
