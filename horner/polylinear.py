#!/usr/bin/python3.6

from sympy import *
x = Symbol('x')

def polylinear(a, h, n):
    b = list()
    b.append(a[0])
    for i in range(1, n):
        b.append(a[i]+h*b[i-1])
    R = a[n]+h*b[n-1]

    q = 0
    for i in range(n):
        q += b[i]*x**(n-1-i)
    print("Q(x) =", q)
    print("Remainder =", R)

n = int(input("Enter the highest power: "))
print("Enter the co-efficients and it's corresponding powers as input if a corresponding co-efficient is not there then enter ZERO as the co-efficient.")

a = list()
for i in range(n, -1, -1):
    tmp = float(input(f"Enter the co-efficient of x^{i}: "))
    a.append(tmp)

h = float(input("Enter the value of h in (x-h): "))

polylinear(a, h, n)
