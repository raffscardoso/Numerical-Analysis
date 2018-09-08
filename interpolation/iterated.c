/********** ITERARTED INTERPOLATION POLYNOMIAL **********/

/*
This method of computing the interpolation is also called as Aitken's method.
Given a set of k + 1 data points 
        x0  I0(x)
        x1  I1(x)  I0,1(x)
        x2  I2(x)  I0,2(x) I0,1,2(x)
        .   .
        .   .
        .   .
        .   .
        .   .
        xn  In(x)  I0,n(x) I0,1,n(x) . . . . . . . I_(0,1,2,3,..,n)(x)
   In each new elements is computed using the elements in the {same row, preceding column} and {top row, preceding column}.

   Generalizied formula for an element:
      I_(0,1,2,...,j-1,j,i) = | I_(0,1,2,...,j-1,j)   xj-x | /
                              | I_(0,1,2,...,j-1,i)   xi-x |/ (xi - xj)
               for   1 < j <= i
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
void iterated(float x[], float y[], int nitems, float xi);

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

   iterated(x, y, nitems, xi);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void iterated(float x[], float y[], int nitems, float xi)
{
   int          i, j;             //Declaration of variables in int
   float        val1;             //Declaration of variables in float
   float        I[MAX][MAX];      //Decalaration of arrays in float

   for (i = 0; i < nitems; i++)
   {
      I[i][MAXC] = y[i];
   }

   for (i = 1; i < nitems; i++)
   {
      for (j = 0; j < nitems-i; j++)
      {
         val1 = ((I[i-1][i-1]*(x[i+j]-xi)) - (I[i+j][i-1]*(x[i-1]-xi)));
         I[i+j][i] = val1/(x[i+j] - x[i-1]);
      }
   }

   printf("Value of f(x) at %f is %f\n", xi, I[nitems-1][nitems-1]);
   return ;
}
