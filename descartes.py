#!/usr/bin/python3.6

from operator import xor

def descartes(coeff, expo, n):
    sign1 = list()
    sign2 = list()
    pos = 0
    neg = 0
    for i in range(n):
        if coeff[i] > 0:
            sign1.append(1)
        else:
            sign1.append(0)

        if xor(coeff[i] > 0, expo[i]%2):
            sign2.append(1)
        else:
            sign2.append(0)

    for i in range(1, n):
        if sign1[i-1]-sign1[i] == 1 or sign1[i-1]-sign1[i] == -1:
            pos += 1
        if sign2[i-1]-sign2[i] == 1 or sign2[i-1]-sign2[i] == -1:
            neg += 1
    print("No. of positive roots are", pos)
    print("No .of Negative roots are", neg)


n = int(input("Enter the no. of terms: "))
coeff = list()
expo = list()

for i in range(n):
    tmp = float(input("Enter the co-efficient: "))
    coeff.append(tmp)
    tmp = int(input("Enter its corresponding power: "))
    expo.append(tmp)

descartes(coeff, expo, n)
