/********** NEWTON'S DIVIDED DIFFERENCE INTERPOLATION POLYNOMIAL **********/

/* It may also be noted for calculating the higher order divided differences we have used lower order divided differences. In fact starting from the given zeroth order differences.

     f[x0, x1, x2, x3,......., xn] = ∑_{i=0}_{k} (f(xi)/pi1_{j=0}_{k}(xi - xj))

     p(x) = f(x0) + f[x0, x1](x-x0) +........+ f[x0, x1,...,xn](x-x0)(x-x1).....(x-xn)
 */

/**************** Input: data-set points *************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        150
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void newtonddf(float x[], float y[], int nitems, float xi, float h);
float factorial(int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems;        //Declaration of variables in int
   float      xi, h;                //Declaration of variables in float
   float      x[MAX], y[MAX];       //Declaration of arrays in float
   char       xs[MAX], ys[MAX];     //Declaration of arrays in char

   printf("Enter the value for step length:- ");
   scanf("%f", &h);

   printf("Enter the value of x and y as inputs and then the value of xi.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

   while (1)  //Infinte Loop
   {
      printf("Enter the value of x: ");
      scanf("%s", xs);
      if (*xs >= 'a' && *xs <= 'z')  //Check condition
      {
         break;
      }

      printf("Enter the value of f(x): ");
      scanf("%s", ys);
      if (*ys >= 'a' && *ys <= 'z')  //Check condition
      {
         fprintf(stderr, "These values for f(x) can't be accepted as input.\n");
         exit(2);
      }
      printf("\n");

      x[i] = atof(xs);  //Converting input
      y[i] = atof(ys);   //Converting input

      if (i != 0)
      {
         if (x[i]-x[i-1] != h)
         {
            fprintf(stderr, "The given points are not equi-spaced.\n");
            exit(1);
         }
      }

      i++;  //Incrementing i
      nitems++;  //Incrementing nitems
   }

   printf("Enter the value of at which f should be found:- ");
   scanf("%f", &xi);

   newtonddf(x, y, nitems, xi, h);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void newtonddf(float x[], float y[], int nitems, float xi, float h)
{
   int          i, j, k = 0;           //Declaration of variables in int
   float        pxi = 0, u, val = 1;   //Declaration of variables in float
   float        f[MAX][MAX];           //Decalaration of arrays in float

   u = (xi - x[0])/h;

   for (i = 0; i < nitems; i++)
   {
      f[i][MAXC] = y[i];
   }

   for (i = 1; i < nitems; i++)
   {
      for (j = 0; j < nitems-i; j++)
      {
         f[i+j][i] = f[i+j][i-1] - f[i+j-1][i-1];
      }
   }

   pxi = y[0];
   for (i = 1; i < nitems; i++)
   {
      for (j = 0; j < i; j++)
      {
         val = val * (u-j);
      }
      pxi = pxi + ((val * f[i][i])/(factorial(i)));
      val = 1;
   }
   printf("Value of f(x) at %f is %f\n", xi, pxi);
   return ;
}

float factorial(int n)
{
   double        fac, i;

   if (n == 0)
   {
      return 1;
   }
   else if ((n == 2) || (n == 1))
   {
      return (n*1);
   }

   fac = 1;
   for (i=1; i<n; i++)
   {
      fac = fac * (i+1);
   }

   return fac;
}

