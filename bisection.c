#include<stdio.h>
#include<conio.h>
#include<math.h>
/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/
#define f(x) x*exp(x)-2

void main()
{
	 float x0, x1, x2, f0, f1, f2, e=0.0001;
	 int step = 1;
	 /* Inputs */
	 up:
	 printf("\nEnter two initial guesses for xe^x-2\n");
	 scanf("%f%f", &x0, &x1);
	 /* Calculating Functional Value */
	 f0 = f(x0);
	 f1 = f(x1);
	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }
   /* Implementing Bisection Method */
	 printf("\nStep\t\tx1\t\tf1\t\tx2\t\tf2\t\tx0\t\tf0\n");
	 do
	 {
		  x2 = (x0 + x1)/2;
		  f2 = f(x2);
		
		  printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",step, x0,f0, x1,f1, x2, f2);
		
		  if( f0 * f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	 }while(fabs(f2)>e);
	 printf("\nRoot is: %f", x2);
}
