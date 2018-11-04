#!/usr/bin/python3.6

def dybydx(x, y):
    fx = (x + y)
    return fx

def milnep(x, y, delx, ydash, n):
    for i in range(4):
        ydash.append(dybydx(x[i], y[i]))

    i = 4
    while i < n:
        tmp = y[i-4] + (4*delx*(2*ydash[i-3]-ydash[i-2]+2*ydash[i-1])/3)
        y.append(tmp)
        x.append(x[i-1] + delx)
        ydash.append(dybydx(x[i], y[i]))
        print("x%i = %f and y%i = %f."% (i, x[i], i, y[i]))
        i = i + 1

def milnec(x, y, delx, ydash, n):
    print("\nBy corrector's method: ")
    i = 4
    while i < n:
        ycheck = y[i-2] + delx*(ydash[i-2]+4*ydash[i-1]+ydash[i])/3
        print("y%i = %f" % (i, ycheck))
        i = i + 1

x = list()
y = list()
ydash = list()

for i in range(4):
    tmp = float(input("Enter the value of x%i: "% i))
    x.append(tmp)
    tmp = float(input("Enter the value of y%i: "% i))
    y.append(tmp)

delx = float(input("Enter the value of Δx: "))
n = int(input("Enter the no. of iterations: ")) + 4

milnep(x, y, delx, ydash, n)
milnec(x, y, delx, ydash, n)
