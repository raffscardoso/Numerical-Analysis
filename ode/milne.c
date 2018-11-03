/*			MILNE'S METHOD			*/

/*
    A finite-difference method for the solution of the Cauchy problem for systems of first-order ordinary differential equations:

    dy/dx = f(x, y)

    The method uses the finite-difference formula:
    yi - yi-1 = 2hf(xi-1, yi-1).
    xi = x0+ih, i = 0,1,2,3,.....

    The predictor-corrector Milne method uses a pair of finite-difference formulas:
a predictor
    yi = yi-4 + 4h(2y'i-3 - y'i-2 + 2y'i-1)/3, i = 4,5,6,7,....,
and a corrector
    yi = yi-2 + h(y'i-2+4y'i-1+y'i)

*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTATS *********/
#define MAX         15

/********* FUNCTION DECLARATION *********/
float dybydx(float x, float y);
void milnep(float x[], float y[], float delx, int n, float ydash[]);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int          i = 0, n;             //Declaration of variables in int
   float        x[MAX], y[MAX], ydash[MAX]; //Declaration of arrays in float
   float        delx;      //Declaration of variables in float

   printf("Enter the first four consecutive values: \n");
   while (i < 4)
   {
      printf("Enter the value of x%d: ", i);
      scanf("%f", &x[i]);
      printf("Enter the value of y%d: ", i);
      scanf("%f", &y[i]);
      printf("\n");
      i++;
   }

   printf("Enter the value of Δx: ");
   scanf("%f", &delx);

   printf("Upto how many values consecutive points should be computed: ");
   scanf("%d", &n);

   milnep(x, y, delx, n+4, ydash);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void milnep(float x[], float y[], float delx, int n, float ydash[])
{
   int        i = 4, j; //Declaration of variables in int

   for (j = 0; j < 4; j++)
   {
      ydash[j] = dybydx(x[j], y[j]);
   }

   while (i < n)  //Check condition
   {
      y[i] = y[i-4] + (4*delx*(2*ydash[i-3]-ydash[i-2]+2*ydash[i-1]))/3;
      x[i] = x[i-1] + delx;
      ydash[i] = dybydx(x[i], y[i]);
      printf("x%d = %f and y%d = %f\n", i+1, x[i], i+1, y[i]);
      i++;  //Incrementing i
   }

   return ;  //returning void
}

float dybydx(float x, float y)
{
   float        fx;  //Declaration of variables in float

   fx = x + y;  //Equation
   return fx;   //returning float
}
