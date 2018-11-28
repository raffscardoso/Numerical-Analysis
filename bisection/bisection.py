#!/usr/bin/python3.6

def f(x):
    fx = 3*x**2-15*x+7
    return fx

def bisection(a, b):
    i = 0
    if f(a)*f(b) > 0:
        return None
    while True:
        m = (a+b)/2
        print(f"Root after iteration {i} is {m}")
        if f(a)*f(m) < 0:
            b = m
        elif f(b)*f(m) < 0:
            a = m

        tmp1 = round(a, 9)
        tmp2 = round(b, 9)
        if tmp1 == tmp2:
            return b
        i = i + 1

a = float(input("Enter the lower limit of the interval: "))
b = float(input("Enter the upper limit of the interval: "))

root = bisection(a, b)
print(f"The correct root is {root}")
