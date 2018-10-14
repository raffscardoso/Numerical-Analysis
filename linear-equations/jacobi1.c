/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void jacobi(float co[][MAX], float con[], float x[], int n);
void gaussjori(float co[MAX][MAX], float ai[MAX][MAX], int n);
void matrixm1(float matrix[MAX][MAX], float con[MAX], int n, float mat[MAX]);
void matrixm(float matrix[][MAX], float con[][MAX], int n, float mat[][MAX]);
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
         printf("Enter the co-efficient of x%d:- ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value:- ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }

   diadomatrix(co, n);

   printf("Enter the guess matrix: \n");
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
   int        i, j, check = 0;
   float      C[MAX], sol[MAX], tmp[MAX];
   float      l_u[MAX][MAX], d[MAX][MAX], T[MAX][MAX], di[MAX][MAX];

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (i == j)
         {
            d[i][j] = co[i][j];
         }
         else
         {
            l_u[i][j] = co[i][j];
         }
      }
   }

   gaussjori(d, di, n);

   matrixm1(di, con, n, C);
   matrixm(di, l_u, n, T);

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         T[i][j] = -T[i][j];
      }
   }

   while (1)
   {
      matrixm1(T, x, n, tmp);

      for (i = 0; i < n; i++)
      {
         sol[i] = tmp[i] + C[i];
         if (floor(sol[i]*1000000) == floor(x[i]*1000000))
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
      check = 0;
   }

   for (i = 0; i < n; i++)
   {
      printf("value of x%d is %f\n", i+1, sol[i]);
   }

   return ;
}

void gaussjori(float co[MAX][MAX], float li[MAX][MAX], int n)
{
   int        i, j, k = 0;  //Declaration of variables in int
   float      val;          //Declaration of variables in float
   float      ai[MAX][MAX]; //Declaration of 2d-arrays in float

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         ai[i][j] = 0;
         if (i == j)
         {
            ai[i][j] = 1;  //Initializing a identity matrix
         }
      }
   }

   while (k < n)  //Check condition
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)  //check condition
         {
            continue;  //Skipping the iteration
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]); //Applying row transformations
            ai[i][j] = (ai[i][j]-val*ai[k][j]); //Applying row transformations
         }
      }
      k++;  //Incremnting k
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
      for (j = 0; j < n; j++)
      {
         li[i][j] = (ai[i][j]/co[i][i]);  //Normalizing
      }
   }
   return ;
}

void matrixm1(float matrix[MAX][MAX], float con[MAX], int n, float mat[MAX])
{
   int        i, j, q;
   float      ele;
   float      val = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < 1; j++)
      {
         for (q = 0; q < n; q++)
         {
            ele = matrix[i][q] * con[q];
            val += ele;
         }
         mat[i] = val;
         val = 0;
      }
   }

   return ;
}

void matrixm(float matrix[][MAX], float con[][MAX], int n, float mat[][MAX])
{
   int        i, j, q;
   float      ele;
   float      val = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         for (q = 0; q < n; q++)
         {
            ele = matrix[i][q] * con[q][j];
            val += ele;
         }
         mat[i][j] = val;
         val = 0;
      }
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
