#!/usr/bin/python3.6

from sympy import *
x = Symbol('x')

def polyquad(a, p, q, n):
    b = list()
    b.append(a[0])
    b.append(a[1]-p*b[0])
    for i in range(2, n-1):
        b.append(a[i]-p*b[i-1]-q*b[i-2])
    R = a[n-1]-p*b[n-2]-q*b[n-3]
    S = a[n]-q*b[n-2]

    q = 0
    for i in range(n-1):
        q += b[i]*x**(n-2-i)
    print("Q(x) =", q)
    print("R(x) =", R*x+S)

n = int(input("Enter the highest power: "))
print("Enter the co-efficients and it's corresponding powers as input if a corresponding co-efficient is not there then enter ZERO as the co-efficient.")

a = list()
for i in range(n, -1, -1):
    tmp = float(input(f"Enter the co-efficient of x^{i}: "))
    a.append(tmp)

p = float(input("Enter the value of p in x**2 + px + q: "))
q = float(input("Enter the value of q in x**2 + px + q: "))

polyquad(a, p, q, n)
