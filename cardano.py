#!/usr/bin/python3.6

############### CARDANO'S METHOD ###############
# The Cardano's formula (named after Girolamo Cardano 1501-1576), which is similar to the perfect-square method to quadratic equations, is a standard way to find a real root of a cubic equation.
# This method works only for the cubic equation which has complex roots and a real root.

##### PROGRAM STARTS HERE #####

from math import sqrt

co = list()
for i in range(4):
    print("Enter the co-efficient of x^", i)
    val = float(input(""))
    co.append(val)

Q = (((3*co[3]*co[1])-(co[2]**2))/(9*(co[3]**2)))
R = (((9*co[3]*co[2]*co[1])-(27*(co[3]**2)*co[0])-(2*(co[2]**3)))/(54*(co[3]**3)))

val1 = (R+sqrt((Q**3)+(R**2)))
val2 = (R-sqrt((Q**3)+(R**2)))

if val1 < 0:
    val1 = -val1
    S = pow(val1, 1/3)
    S = -S
else:
    S = pow(val1, 1/3)

if val2 < 0:
    val2 = -val2
    T = pow(val2, 1/3)
    T = -T
else:
    T = pow(val2, 1/3)

real = (-((S+T)/2)-(co[2]/(3*co[3])))
img = ((sqrt(3/4))*(S-T))

x1 = S+T-(co[2]/(3*co[3]))
x2 = complex(real, img)
x3 = complex(real, -img)

print("The solutions for the Equation are: ")
print(x1, x2, x3)
