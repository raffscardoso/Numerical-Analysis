#!/usr/bin/python3.6

import math

def f(x):
    fx = 3*x**2-15*x+7
    return fx

def secant(a, b):
    while True:
        fa = f(a)
        fb = f(b)
        root = (a*fb-b*fa)/(fb-fa)

        tmp1 = round(b, 9)
        tmp2 = round(root, 9)
        if tmp1 == tmp2:
            print("The root of the given equation is %f"% root)
            return
        a = b
        b = root

a = float(input("Enter the first root: "))
b = float(input("Enter the second root: "))

secant(a, b)
