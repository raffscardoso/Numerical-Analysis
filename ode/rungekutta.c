/*			RUNGE-KUTTA METHOD			*/

/*
    In numerical analysis, the Runge–Kutta methods are a family of implicit and explicit iterative methods, which include the well-known routine called the Euler Method, used in temporal discretization for the approximate solutions of ordinary differential equations. These methods were developed around 1900 by the German mathematicians Carl Runge and Martin Kutta.

    The most widely known member of the Runge–Kutta family is generally referred to as "RK4", "classical Runge–Kutta method" or simply as "the Runge–Kutta method".

    Let an initial value problem be specified as follows:
    y˙ = f(t, y), y(t0) = y0.

    Here y is an unknown function (scalar or vector) of time t, which we would like to approximate; we are told that y˙, the rate at which y changes, is a function of t and of y itself. At the initial time t0 the corresponding y value is y0. The function f and the data t0, y0 are given.

    Now pixk a step-size h < 0 and define
        y_{n+1} = yn + (k1+2*k2+2*k3+k4)/6
        t_{n+1} = tn + h
    for n = 0,1,2,3,...., using

    k1 = hf(tn, yn),
    k2 = hf(tn+h/2, yn+k1/2),
    k3 = hf(tn+h/2, yn+K2/2),
    K4 = hf(tn+h, yn+k3),

    Note: the above equations have different but equivalent definitions in different texts.

    Here y_{n+1} is the RK4 approximation of y (t_{n+1}), and the next value ( y_{n+1}) is determined by the present value (yn) plus the weighted average of four increments, where each increment is the product of the size of the interval, h, and an estimated slope specified by function f on the right-hand side of the differential equation.

    k1 is the increment based on the slope at the beginning of the interval, using y (Euler's method); k2 is the increment based on the slope at the midpoint of the interval, using y and k1; k3 is again the increment based on the slope at the midpoint, but now using y and k2; k4 is the increment based on the slope at the end of the interval, using y and k3.

In averaging the four increments, greater weight is given to the increments at the midpoint. If f is independent of y, so that the differential equation is equivalent to a simple integral, then RK4 is Simpson's rule.

*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
float f(float x, float y);
void rungekutta(float x0, float y0, float delx, int n);

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

   rungekutta(x0, y0, delx, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void rungekutta(float x0, float y0, float delx, int n)
{
   int        i = 0;  //Declaration of variables in int
   float      x, y, k1, k2, k3, k4, dely; //Declaration of variables in float

   x = x0, y = y0;
   printf("x%d = %f and y%d = %f\n", i, x0, i, y0);
   while (i < n)  //Check condition
   {
      k1 = delx*f(x, y);              //Finding ki values
      k2 = delx*f(x+delx/2, y+k1/2);
      k3 = delx*f(x+delx/2, y+k2/2);
      k4 = delx*f(x+delx, y+k3);

      dely = (k1+2*k2+2*k3+k4)/6;   //Calculating dely

      y = y + dely;
      x = x + delx;
      printf("x%d = %f and y%d = %f\n", i+1, x, i+1, y);
      i++;  //Incrementing i
   }

   return ;  //returning void
}

float f(float x, float y)
{
   float        fx;  //Declaration of variables in float

   fx = x + y;  //Equation
   return fx;   //returning float
}
