# Numerical Analysis

This repository contains some of the algorithms for root finding methods and interpolation.

1. birgevieta.c
    The program takes coeffients of the equation, their corresponding powers and an approx. root as the input and computes the root for the given polynomial equation using Birge-Vieta method.
2. graeffe.c
    The program takes coeffients of the equation and their corresponding powers as the input and computes the root for the given polynomial equation using Graeffe's method.
3. descartes.c
    The program takes coeffients and their corresponding powers as the input and computes the sign of the roots for the given polynomial equation using Descartes rule of sign.

*Bi-section method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Bisection method.

*Secant method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Secant method.
    
*Regular Falsi method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Regular Falsi method.

*Newton Raphson method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Newton Raphson method.
    
*Muller method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Muller method.
    
*Chebyshev method:*
    In this directory, there are algorithms for finding roots for any quadratic equation and some of the of the given transcedental equations using Chebyshev method.
    
**Horner's method:**

    This is generally called as synthetic division of the polynomial functions, In this directory,
1. polylinear.c
    The program takes coeffients of the equation, their corresponding powers and a root as the input and computes the root for the given polynomial equation using Horner's method.
2. polyquad.c
    The program takes coeffients of the equation, their corresponding powers and coeffients of the quadratic which is a factor of the polynomial as the input and computes the root for the given polynomial equation using Horner's method.
    
*Ramanujan method:*
    The program takes coeffients of the equation, their corresponding powers as input and computes the smallest real root for the given polynomial equation using Ramanujan's method.

*Cardano method:*
    The program takes coeffients of a cubic equation as inputs and computes a real root and a pair of complex roots, this method is similar to the perfect-square method to quadratic equations, is a standard way to find a real root of a cubic equation and one more thing it works only for the cubic equation which has complex roots and a real root.

**Interpolation**

In this directory, you can find some algorithm for interpolating the given data-points.

*Lagrange interpolation*
    This program takes the data-points as input and computes the lagrange's polynomial for nth order and takes the value at given x and gives the value of f(x).

*Newton divided difference interpolation*
    This program takes the data-points as input and computes the newton divided differences for nth order and takes the value at given x and gives the value of f(x).

*Iterated interpolation*
    This program takes the data-points as input and computes the iterated interpolation for nth order and takes the value at given x and gives the value of f(x).

*Gregory-Newton forward difference interpolation*
    This program takes the data-points as input and computes the newton divided differences in terms of forward differences for nth order and takes the value at given x and gives the value of f(x).

*Gregory-Newton backward difference interpolation*
    This program takes the data-points as input and computes the newton divided differences in terms of backward differences for nth order and takes the value at given x and gives the value of f(x).

**Integration**

In this directory, you can find some algorithm for integration when given an interval and the step length of the sub-intervals.

*Simphson's 1/3 rule*
    This program takes the limits of the interval and computes the integration the given static function using simphson's 1/3 rule.

*Trapezoidal rule*
    This program takes the limits of the interval and computes the integration t
he given static function using trapezoidal's rule.

**Linear-Equations**

In this directory, you can find some algorithm for solving system of equations.

*Gauss-Elimination:*
    This program takes the co-efficients of x,y,z and constant of n system of equation and oredr of the matrix as input and computes the solution by reducing the matrix into a upper triangular matrix.

*Gauss-Jordan Elimination:*
    This program takes the co-efficients of x,y,z and constant of n system of equation and oredr of the matrix as input and computes the solution by reducing the matrix into a diagonal matrix.

*Inverse using Gauss-Jordan Elimination:*
    This program takes the co-efficients of x,y,z of n system of equation and oredr of the matrix as input and finds the inverse of the matrix.

*LU Decomposition:*
    Decomposes the given matrix into lower and upper triangular matrices and finds the solution by backward-subsitution followed by forward-subsitution.

**Ordinary Differential Equations**

In this directory, you can find some algorithms for getting the data-points for some of the Differential Equations.

*Euler Method:*
    It takes two initial points as input and the value of Δx as input and computes the value at x0+i(Δx), where x0 is the initial point by using euler's method.    NOTE: This method is only used for first order differential equations.

*Improved Euler Method:*
    The inputs are same as the euler's method but it takes some more iterations to finalize each value at yi to more accurate results simply it follows as a iterative method.

*Runge-kutta Method:*
    The inputs are same as the euler's method in this it computes the function value at each increment based on the slope at different points of the curve.
