/*			LU DECOMPOSITION			*/

/*
LU decomposition of a matrix is the factorization of a given square matrix into two triangular matrices, one upper triangular matrix and one lower triangular matrix, such that the product of these two matrices gives the original matrix.

This method of factorizing a matrix as a product of two triangular matrices has various applications such as solution of a system of equations, which itself is an integral part of many applications such as finding current in a circuit and solution of discrete dynamical system problems; finding the inverse of a matrix and finding the determinant of the matrix.

Basically, the L U decomposition method comes handy whenever it is possible to model the problem to be solved into matrix form. Conversion to the matrix form and solving with triangular matrices makes it easy to do calculations in the process of finding the solution.

A square matrix A can be decomposed into two square matrices L and U such that A = LU where L is an lower triangular matrix formed as a result of applying Gauss Elimination Method on A; and U is a upper triangular matrix with diagonal elements being equal to 1.
*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void ludecomp(float co[MAX][MAX], float con[MAX], int n);
void backsub(float sol[MAX], float co[MAX][MAX], int n, float con[MAX]);
void forsub(float sol[MAX], float co[MAX][MAX], int n, float z[MAX]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;             //Declaration of variables in int
   float       co[MAX][MAX], con[MAX]; //Declaration of arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");
   scanf("%d", &n);

   while (i < n)  //Check condition
   {
      printf("Enter Equation no. %d\n", i+1);
      for (j = 0; j < n; j++)
      {
         printf("Enter the co-efficient of x%d:- ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value:- ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }

   ludecomp(co, con, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void ludecomp(float co[MAX][MAX], float con[MAX], int n)
{
   int          i, j, k, m;               //Decalartion of variables in int
   float        val1 = 0, val2 = 0;       //Decalaration of variables in float
   float        u[MAX][MAX], l[MAX][MAX]; //Decalaration of 2d-arrays in float
   float        sol[MAX];                 //Declaration of arrays in float

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i == j)
         {
            u[i][j] = 1;
         }
         else if (i < j)
         {
            l[i][j] = 0;
         }
         else if (i > j)
         {
            u[i][j] = 0;
         }
      }
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i >= j)
         {
            for (k = 0; k <= j-1; k++)
            {
               val1 += l[i][k]*u[k][j];
            }
            l[i][j] = (co[i][j] - val1);
            val1 = 0;
         }
         else if (i < j)
         {
            for (m = 0; m <= i-1; m++)
            {
               val2 += l[i][m]*u[m][j];
            }
            u[i][j] = (co[i][j] - val2)/l[i][i];
            val2 = 0;
         }
      }
   }

   forsub(sol, l, n, con);
   backsub(sol, u, n, sol);

   printf("The solutions of the Equation are:-\n");
   for (i = 0; i < n; i++)
   {
      printf("Value of x%d is %f\n", i+1, sol[i]);
   }
   return ;
}

void backsub(float sol[MAX], float co[MAX][MAX], int n, float con[MAX])
{
   int        i, j;
   float      val = 0;

   sol[n-1] = con[n-1]/co[n-1][n-1];
   for (i = n-2; i >= 0; i--)
   {
      for (j = i+1; j < n; j++)
      {
         val += co[i][j]*sol[j];
      }
      sol[i] = (con[i]-val)/co[i][i];
      val = 0;
   }

   return ;
}

void forsub(float sol[MAX], float co[MAX][MAX], int n, float z[MAX])
{
   int        i, j;
   float      val = 0;

   sol[0] = z[0]/co[0][0];
   for (i = 1; i < n; i++)
   {
      for (j = 0; j < i; j++)
      {
         val += co[i][j]*sol[j];
      }
      sol[i] = (z[i]-val)/co[i][i];
      val = 0;
   }

   return ;
}
