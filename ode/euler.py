#!/usr/bin/python3.6

def dybydx(x, y):
    fx = (x + y)
    return fx

def euler(x0, y0, delx, n):
    x = x0
    y = y0
    i = 0
    print("(x, y) at iteration no.", i, "is", (x, y))
    while i < n:
        y = (y+ dybydx(x, y)*delx)
        x = x + delx
        print("(x, y) at iteration no.", i+1, "is", (x, y))
        i = i + 1

x0 = float(input("Enter the value of x0: "))
y0 = float(input("Enter the value of y0: "))
delx = float(input("Enter the value of Δx: "))
n = int(input("Enter the no. of iterations: "))

euler(x0, y0, delx, n)
