#!/usr/bin/python3.6

import math

def dybydx(x, y):
    fx = (x + y)
    return fx

def imeuler(x0, y0, delx, n):
    x = list()
    y = list()
    x.append(x0)
    y.append(y0)

    i = 0
    print("x0 = %f and y0 = %f"% (x[i], y[i]))
    while i < n:
        tmpy = y[i] + dybydx(x[i], y[i])*delx
        x.append(x[i]+delx)
        while True:
            tmpyy = tmpy
            tmpy = y[i] + ((dybydx(x[i], y[i])+dybydx(x[i+1], tmpy))/2)*delx

            tmp1 = round(tmpy, 6)
            tmp2 = round(tmpyy, 6)
            if tmp1 == tmp2:
                y.append(tmpy)
                print("x%i = %f and y%i = %f"% (i+1, x[i+1], i+1, y[i+1]))
                i = i + 1
                break

x0 = float(input("Enter the value of x0: "))
y0 = float(input("Enter the value of y0: "))
delx = float(input("Enter the value of Δx: "))
n = int(input("Enter the no. of iterations: "))

imeuler(x0, y0, delx, n)
