#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        3
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void gausse(float co[MAX][MAX], float con[MAX]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j;               //Declaration of variables in int
   float       co[MAX][MAX], con[MAX]; //Declaration of arrays in float

   //Input section
   while (i < MAX)  //Check condition
   {
      printf("Enter Equation no. %d\n", i+1);
      for (j = 0; j < MAX; j++)
      {
         printf("Enter the co-efficient of x%d:- ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value:- ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }

   gausse(co, con);  //Calling function
   exit(0);
}

void gausse(float co[MAX][MAX], float con[MAX])
{
   int        i, j;      //Declaration of variables in int
   float      sol[MAX];  //Declaration of arrays in float

   for (i = 1; i < MAX; i++)
   {
      for (j = 1; j < MAX; j++)
      {
         co[i][j] = (co[i][j] - ((co[i][0]/co[0][0])*co[0][j]));
      }
      con[i] = (con[i] - ((co[i][0]/co[0][0])*con[0]));
   }

   co[2][2] = (co[2][2] - ((co[2][1]/co[1][1])*co[1][2]));
   con[2] = (con[2] - ((co[2][1]/co[1][1])*con[1]));

   sol[2] = con[2]/co[2][2];

   sol[1] = (con[1]-(co[1][2]*sol[2]))/co[1][1];

   sol[0] = (con[0]-(co[0][1]*sol[1]+co[0][2]*sol[2]))/co[0][0];

   // Printing result
   for (i = 0; i < MAX; i++)
   {
      printf("The value if x%d is %f\n", i+1, sol[i]);
   }

   return ;
}
