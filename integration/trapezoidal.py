#!/usr/bin/python3.6

def function(x):
    return x*(1-(x*x))

def trapezoidal(a, b, h):
    n = (b-a)/(2*h)
    N = int(2*n)

    px = function(a)
    for i in range(N):
        px += 2*function(a+(i+1)*h)
    px += function(b)
    px = (h*px)/2
    return px

a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))
h = float(input("Enter the value of h: "))

px = trapezoidal(a, b, h)
print("The value of integral is", px)
