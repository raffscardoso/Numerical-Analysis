#!/usr/bin/python3.6

def f(x):
    fx = 3*x**2-15*x+7
    return fx

def fd(x):
    fdx = 6*x-15
    return fdx

def fdd(x):
    fddx = 6
    return fddx

def chebyshev(guess):
    i = 0
    while True:
        root = guess-f(guess)/fd(guess)-(f(guess)**2*fd(guess)/(2*fd(guess)**3))
        print(f"Root after iteration {i+1} is {root}.")
        tmp1 = round(root, 9)
        tmp2 = round(guess, 9)

        if tmp1 == tmp2:
            return root
        guess = root
        i = i + 1

guess = float(input("Enter the guess value: "))
root = chebyshev(guess)
print(f"The final root is {root}")
