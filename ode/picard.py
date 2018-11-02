#!/usr/bin/python3.6

from sympy import *
x = Symbol('x')

def function(y, i):
    tmpy = x + y[i]
    return tmpy
    
def picard(x0, y0, delx, n):
    i = 0
    y = list()
    y.append(y0)
    while i < n:
        tmpy = y0 + integrate(function(y, i), (x, x0, x))
        y.append(tmpy)
        print(tmpy)
        i = i + 1

x0 = float(input("Enter the value of x0: "))
y0 = float(input("Enter the value of y0: "))
delx = float(input("Enter the value of Δx: "))
n = int(input("Enter the no. of iterations: "))

picard(x0, y0, delx, n)
