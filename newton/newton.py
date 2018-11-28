#!/usr/bin/python3.6

def f(x):
    fx = 3*x**2-15*x+7
    return fx

def fd(x):
    fdx = 6*x-15
    return fdx

def newton(guess):
    i = 0
    while True:
        root = guess - (f(guess)/fd(guess))
        print(f"Root after iteration {i+1} is {root}.")
        tmp1 = round(guess, 9)
        tmp2 = round(root, 9)

        if tmp1 == tmp2:
            return root
        guess = root
        i = i + 1

guess = float(input("Enter the guess value: "))
root = newton(guess)
print(f"The final root is {root}")
