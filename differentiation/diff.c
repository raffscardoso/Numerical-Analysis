#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX         15

/********* FUNCTION DECLARATION *********/
float factorial(int n);
void diff(int n, float alpha[]);
void gaussjor(float co[][MAX+1], float con[], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        n;
   float      alpha[MAX];

   printf("Enter the order of the equation: ");
   scanf("%d", &n);

   diff(n, alpha);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void diff(int n, float alpha[])
{
   int        i, k = -n;
   float      matrix[MAX][MAX+1];

   while (k != n+1)
   {
      alpha[k+n] = 0;
      if (k == 0)
      {
         alpha[k+n] = factorial(n);
      }

      for (i = 0; i < 2*n+1; i++)
      {
         matrix[i][k+n] = powf(k, i)/factorial(i);
      }
      k++;
   }

   gaussjor(matrix, alpha, 2*n+1);
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

void gaussjor(float co[][MAX+1], float con[], int n)
{
   int        i, j, k = 0; //Declaration of variables in int
   float      sol[MAX];    //Declaration of arrays in float
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
      printf("Value of α_{%d}is %f\n", i-n/2, sol[i]/factorial(n/2));
   }
   return ;
}
