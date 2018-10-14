/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void jacobi(float co[MAX][MAX], float con[MAX], float x[MAX], int n);
void diadomatrix(float matrix[MAX][MAX], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;       //Declaration of variables in int
   float       con[MAX], x[MAX];  //Declaration of arrays in float
   float       co[MAX][MAX];      //Declaration of 2d-arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");  //Taking order of the matrix
   scanf("%d", &n);

   while (i < n)  //Check condition
   {
      printf("Enter Equation no. %d\n", i+1);
      for (j = 0; j < n; j++)
      {
         printf("Enter the co-efficient of x%d: ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value: ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }
   diadomatrix(co, n);

   printf("Enter the guess values: \n");
   for (i = 0; i < n; i++)
   {
      printf("Enter value%d: ", i+1);
      scanf("%f", &x[i]);
   }

   jacobi(co, con, x, n);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void jacobi(float co[MAX][MAX], float con[MAX], float x[MAX], int n)
{
   int        i, j, check = 0, k = 0;
   float      val1 = 0;
   float      sol[MAX];

   while (1)
   {
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < n; j++)
         {
            if (i == j)
            {
               continue;
            }
            val1 += co[i][j]*x[j];
         }

         sol[i] = (con[i]-val1)/co[i][i];
         val1 = 0;

         if (floorf(sol[i]*1000000) == floorf(x[i]*1000000))
         {
            check = check + 1;
         }
      }

      if (check == n)
      {
         break;
      }

      for (i = 0; i < n; i++)
      {
         x[i] = sol[i];
      }

      k++;
   }

   printf("The solutions of the equations after %d iterations are: \n", k);
   for (i = 0; i < n; i++)
   {
      printf("Value of x%d is %f\n", i+1, sol[i]);
   }

   return ;
}

void diadomatrix(float matrix[MAX][MAX], int n)
{
   int        i, j, dd = 0, dd1 = 0;
   float      val = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i == j)
         {
            continue;
         }

         val += fabsf(matrix[i][j]);
      }
      if (fabsf(matrix[i][i]) > val)
      {
         dd = dd + 1;
         dd1 = dd1 + 1;
      }
      else if (fabs(matrix[i][i]) == val)
      {
         dd1 = dd1 + 1;
      }
      val = 0;
   }

   if (dd != n && dd1 != n)
   {
      printf("Roots doesn't converge by this method, they diverge instead.\n");
      exit(1);
   }

   return ;
}

