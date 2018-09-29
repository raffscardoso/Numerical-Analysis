#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

/********* DEFINED CONSTANTS *********/
#define MAX        4

/********* FUNCTION DECLARATION *********/
void cardano(float co[]);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int                j;
   float              co[MAX];

   for (j = 0; j < MAX; j++)
   {
      printf("Enter the co-efficient of x^%d: ", j);
      scanf("%f", &co[j]);
   }

   cardano(co);
   exit(0);
}

void cardano(float co[])
{
   float           Q, R, S, T, val1, val2, real, img, x1;
   float complex   x2, x3;

   Q = (((3*co[3]*co[1])-(powf(co[2], 2)))/(9*(powf(co[3], 2))));
   R = (((9*co[3]*co[2]*co[1])-(27*(powf(co[3], 2))*co[0])-(2*(powf(co[2], 3))))/(54*(powf(co[3], 3))));

   val1 = (R+sqrtf((Q*Q*Q)+(R*R)));
   val2 = (R-sqrtf((Q*Q*Q)+(R*R)));

   if (val1 < 0)
   {
      val1 = -val1;
      S = cbrtf(val1);
      S = -S;
   }
   else
   {
      S = cbrtf(val1);
   }

   if (val2 < 0)
   {
      val2 = -val2;
      T = cbrtf(val2);
      T = -T;
   }
   else
   {
      T = cbrtf(val2);
   }

   real = (-((S+T)/2)-(co[2]/(3*co[3])));
   img = ((sqrtf(3.0/4.0))*(S-T));

   x1 = S+T-(co[2]/(3*co[3]));
   x2 = real + img*I;
   x3 = conjf(x2);

   printf("The solutions for the Equation are:\n");
   printf("%f\n", x1);
   printf("%f+(%fJ)\n", creal(x2), cimag(x2));
   printf("%f+(%fJ)\n", creal(x3), cimag(x3));

   return ;
}
