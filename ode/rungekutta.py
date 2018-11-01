#!/usr/bin/python3.6

def f(x, y):
    fx = (x + y)
    return fx

def rungekuth(x0, y0, delx, n):
    x = x0
    y = y0
    i = 0
    print("(x, y) at iteration no.", i, "is", (x, y))
    while i < n:
        k1 = delx*f(x, y);
        k2 = delx*f(x+delx/2, y+k1/2);
        k3 = delx*f(x+delx/2, y+k2/2);
        k4 = delx*f(x+delx, y+k3);
        dely = (k1+2*k2+2*k3+k4)/6;

        y = y + dely;
        x = x + delx
        print("(x, y) at iteration no.", i+1, "is", (x, y))
        i = i + 1

x0 = float(input("Enter the value of x0: "))
y0 = float(input("Enter the value of y0: "))
delx = float(input("Enter the value of Δx: "))
n = int(input("Enter the no. of iterations: "))

rungekuth(x0, y0, delx, n)
