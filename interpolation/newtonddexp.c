/********** LAGRANGE'S INTERPOLATION POLYNOMIAL **********/

/*
Given a set of k + 1 data points 
       (x_{0},y_{0}),......,(x_{j},y_{j}),.....,(x_{k},y_{k})
       where no two xj x_{j} x_{j} are the same, the interpolation polynomial in the Lagrange form is a linear combination

       p(x) = li(x) * f(xi)
       where li(x) = w(x)/(x-xi)w'(xi)

       w(x) = (x-x0)(x-x1)(x-x2).............(x-xn)
       w'(x) = (xi-x0)(xi-x1)(xi-x2)......(xi-x_{i-1})(xi-x_{i+1})......(xi-xn)
*/

/**************** Input: data-set points *************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        150

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
   int          i = 0, j, k = 1;           //Declaration of variables in int
   float        val=1, val1=0, pxi, val2=1;//Declaration of variables in float
   float        f[MAX], xx[MAX];           //Decalaration of arrays in float

   xx[k] = 1;
   while (k < nitems-1)
   {
      for (i = 0; i < k; i++)
      {
         for (j = 0; j < k; j++)
         {
            if (i == j)
            {
               continue;
            }
            val = val * (x[i]-x[j]);
         }

         val1  = val1 + (y[i] / val);
         printf("%f\n", val1);
         val2 = val2 * (xi - x[i-1]);
         val = 1;
      }
      xx[k] = val2;
      f[k] = val1;
      val1 = 0, val2 = 1;
      k++;
   }

   printf("the value is %f\n", pxi);
   return ;
}
