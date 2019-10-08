/* Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or operand is a seperate
 * argument. For example,
 * 
 * 		expr 2 3 4 + *
 *
 * evaluates 2 x (3+4)
 */

#include <stdio.h>
#define BUFFER 1000

double nums[BUFFER];
int nump = 0;

double atof(char *num)	{

	double n=0;

	while (*++num && *num != '.')	{
		n = n*10 + (*num - '0');
	}

	if (!*num)	{
		int c = 0, i = 0;
		while (*++num)	{
			i = i*10 + (*num - '0');
			c++;
		}
		while (c > 0)	{
			i /= 10;	
		}
		
		n+=i;
	}

	return n;
}

double pop()	{
	return nums[nump--];
}

void push(double n)	{
	nums[nump++] = n;
}

void expr(char operator)	{
	
	double a,b;

	a = pop();
	b = pop();

	switch (operator)	{
		case '+':
			push(a+b);
			break;
		case '-':
			push(a-b);
			break;
		case '/':
			push(a/b);
			break;
		case '*':
			push(a*b);
			break;
	}

}


int main(int argc, char *argv[])	{

	int i;

	for (i=1; argc-i > 1; ++i)	{
		if ('0' > *argv[i] > '9')	{
			push(atof(argv[i]));
		}
		else	{
			expr(*argv[i]);
		}
	}

	printf("%f\n", nums[0]);

	return 0;
}
