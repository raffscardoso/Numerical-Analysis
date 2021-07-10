#!/usr/bin/python3

import numpy as np

def gaussjor(co):
    for k in range(n):
        for i in range(n):
            if i == k:
                continue
            val = co[i][k]/co[k][k]
            for j in range(n+1):
                co[i][j] = (co[i][j]-val*co[k][j])

    for i in range(n):
        if co[i][j] == 0:
            print("The given system of equations have no or infinte soltions.")
            quit()

    for i in range(n):
        sol = co[i][n]/co[i][i]
        print("Value of x{} is {}".format(i+1, sol))
    return

n = int(input("Enter the order of matrix: "))
tmp = [[0 for i in range(n)] for i in range(n)]

for i in range(n):
    print("Enter equation no.{}".format(i+1))
    for j in range(n):
        tmp[i][j] = float(input("Enter the co-efficient of x{}: ".format(j+1)))
    val = float(input("Enter the value: "))
    tmp[i].append(val)
    print("")
co = np.array(tmp)

gaussjor(co)
