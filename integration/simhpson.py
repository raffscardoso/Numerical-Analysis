#!/usr/bin/python3.6

def function(x):
    return x*(1-(x*x))

def simhpson(a, b, h):
    n = (b-a)/(2*h)
    N = int(2*n)

    px = function(a)
    for i in range(N):
        if i%2 is 1:
            px += 4*function(a+(i+1)*h)
        else:
            px += 2*function(a+(i+1)*h)
    px += function(b)
    px = (h*px)/3
    return px

a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))
h = float(input("Enter the value of h: "))

px = simhpson(a, b, h)
print("The value of integral is", px)
