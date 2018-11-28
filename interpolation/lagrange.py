#!/usr/bin/python3.6

def lagrange(xp, yp, n, x):
    w = 1
    px = 0
    tmp = 1
    l = list()
    for i in range(n):
        w *= (x-xp[i])
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            tmp = tmp * (xp[i]-xp[j])
        l.append(w/((x-xp[i])*tmp))
        tmp = 1
        px += (l[i]*yp[i])
    return px

n = int(input("Enter the number of data-points: "))
xp = list()
yp = list()
x = float(input("Enter the value of x in p(x): "))

for i in range(n):
    tmp = float(input("Enter x{}: ".format(i+1)))
    xp.append(tmp)
    tmp = float(input("Enter y{}: ".format(i+1)))
    yp.append(tmp)

fx = lagrange(xp, yp, n, x)
print(f"P({x}) at {x} is {fx}.")
