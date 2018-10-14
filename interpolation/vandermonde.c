/**************** Input: data-set point *************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15

/********* FUNCTION DECLARATION *********/
void vandermonde(float x[], float y[], int nitems, float xi);
void gaussjor(float co[][MAX+1], float con[], int n, float sol[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0;    //Declaration of variables in int
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

   vandermonde(x, y, nitems, xi);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void vandermonde(float x[], float y[], int nitems, float xi)
{
   int          i, j;              //Declaration of variables in int
   float        pxi = 0;           //Declaration of variables in float
   float        c[MAX];            //Declaration of arrays in float
   float        matrix[MAX][MAX+1];  //Decalaration of 2d-arrays in float

   for (i = 0; i < nitems; i++)
   {
      for (j = nitems-1; j >= 0; j--)
      {
         matrix[i][(nitems-1)-j] = powf(x[i], j);
      }
   }

   gaussjor(matrix, y, nitems, c);

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < nitems; j++)
      {
         printf("%f ", matrix[i][j]);
      }
      printf("\n");
   }
   for (i = 0; i < nitems; i++)
   {
      pxi += c[i]*powf(xi, (nitems-1)-i);
   }
   printf("Value of f(x) at %f is %f.\n", xi, pxi);

   return ;
}

void gaussjor(float co[][MAX+1], float con[], int n, float sol[])
{
   int        i, j, k = 0; //Declaration of variables in int
   float      val;         //Declaation of variables in float

   for (i = 0; i < n; i++)
   {
      co[i][n] = con[i];  //Creating argumnted matrix
   }

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)
         {
            continue; //Skipping the loop
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
         }
      }
      k++;  //Incrementing k
   }

   for (i = 0; i < n; i++)
   {
      if (co[i][i] == 0)
      {
         printf("The given system of equations have no ");
         printf("or infinitely many solutions.\n");
         exit(1);
      }
   }

   for (i = 0; i < n; i++)
   {
      sol[i] = co[i][n]/co[i][i];
   }
   return ;
}
