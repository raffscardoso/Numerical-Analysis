/*			IMPROVED EULER'S METHOD			*/
/*
    In mathematics and computational science, the Euler method (also called forward Euler method) is a first-order numerical procedure for solving ordinary differential equations (ODEs) with a given initial value. It is the most basic explicit method for numerical integration of ordinary differential equations and is the simplest Runge–Kutta method.

    The Euler method is a first-order method, which means that the local error (error per step) is proportional to the square of the step size, and the global error (error at a given time) is proportional to the step size. The Euler method often serves as the basis to construct more complex methods, e.g., predictor–corrector method. 

The Euler method can be derived in a number of ways. Firstly, there is the geometrical description above.
Another possibility is to consider the Taylor expansion of the function y around t0: 

    y(t0+h) = y(t0)+hy′(t0)+(h^2y′′(t0))/2 + O(h^3)
The differential equation states that y′ = f(t, y). If this is substituted in the Taylor expansion and the quadratic and higher-order terms are ignored, the Euler method arises. The Taylor expansion is used below to analyze the error committed by the Euler method, and it can be extended to produce Runge–Kutta methods.

A closely related derivation is to substitute the forward finite difference formula for the derivative,

    y′(t0) ≈ (y(t0+h)-y(t0))/h
in the differential equation y′ = f(t,y). Again, this yields the Euler method. A similar computation leads to the midpoint rule and the backward Euler method.

Finally, one can integrate the differential equation from t0 to t0+h and apply the fundamental theorem of calculus to get: 

    y(t0+h)-y(t0) = ∫f(t, y(t))dt from t0+h to t0

    Now approximate the integral by the left-hand rectangle method (with only one rectangle):

    ∫f(t, y(t))dt from t0+h to t0 ≈ hf(t0, y(t0)).

    Combining both equations, one finds again the Euler method. This line of thought can be continued to arrive at various linear multistep methods.

*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        50

/********* FUNCTION DECLARATION *********/
float dybydx(float x, float y);
void imeuler(float x0, float y0, float delx, int n);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        x0, y0, delx, n;  //Declaration of variables in float

   if (argc != 5)  //Check condition
   {
      fprintf(stderr, "Usage: %s <x0> <y0> <Δx> <no of loops>\n", argv[0]);
      exit(1);
   }

   x0 = atof(argv[1]);  // Input Section
   y0 = atof(argv[2]);
   delx = atof(argv[3]);
   n = atoi(argv[4]);

   imeuler(x0, y0, delx, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void imeuler(float x0, float y0, float delx, int n)
{
   int        i = 0;           //Declaration of variables in int
   float      tmpyy, tmpy;     //Declaration of variables in float
   float      x[MAX], y[MAX];  //Declaration of arrays in float

   x[i] = x0, y[i] = y0;
   printf("x%d = %f and y%d = %f\n", i, x0, i, y0);

   while (i < n)
   {
      tmpy = y[i] + dybydx(x[i], y[i])*delx;
      x[i+1] = x[i]+delx;
      printf("x%d = %f and ", i+1, x[i+1]);
      while (1)
      {
         tmpyy = tmpy;
         tmpy = y[i] + ((dybydx(x[i], y[i])+dybydx(x[i+1], tmpy))/2)*delx;

         if (floorf(tmpy*1000000) == floorf(tmpyy*1000000))
         {
            y[i+1] = tmpy;
            printf("y%d = %f\n", i+1, y[i+1]);
            break;
         }
      }

      i++;
   }
   return ;  //returning void
}

float dybydx(float x, float y)
{
   float        fx;  //Declaration of variables in float

   fx = x + y;  //Equation
   return fx;  //returning float
}
