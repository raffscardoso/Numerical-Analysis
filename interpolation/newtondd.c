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
void newtondd(float x[], float y[], int nitems, float xi);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems;        //Declaration of variables in int
   float      xi;                   //Declaration of variables in float
   float      x[MAX], y[MAX];       //Declaration of arrays in float
   char       xs[MAX], ys[MAX];     //Declaration of arrays in char

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

      i++;  //Incrementing i
      nitems++;  //Incrementing nitems
   }

   printf("Enter the value of at which f should be found:- ");
   scanf("%f", &xi);

   newtondd(x, y, nitems, xi);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void newtondd(float x[], float y[], int nitems, float xi)
{
   int          i, j, k = 0;               //Declaration of variables in int
   float        val = 1, pxi = 0;          //Declaration of variables in float
   float        f[MAX][MAX], xx[MAX];      //Decalaration of arrays in float

   for (i = 0; i < nitems; i++)
   {
      f[i][MAXC] = y[i];
   }

   for (i = 1; i < nitems; i++)
   {
      for (j = 0; j < nitems-i; j++)
      {
         f[j+i][i] = (f[j+i][i-1] - f[j+i-1][i-1])/(x[j+i] - x[k+0]);
         k = k + 1;
      }
      k = 0;
   }

   xx[0] = 1;
   for (i = 1; i < nitems; i++)
   {
      for (j = 0; j < i; j++)
      {
         val = val * (xi - x[j]);
      }
      xx[i] = val;
      val = 1;
   }

   for (i = 0; i < nitems; i++)
   {
      pxi = pxi + (f[i][i] * xx[i]);
   }
   printf("Value of f(x) at %f is %f\n", xi, pxi);
   return ;
}
