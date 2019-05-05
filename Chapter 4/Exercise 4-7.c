/*
Write a routine ungets(s) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch?
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define VAR '_'


int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];

void push(double f)	{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);

}

double pop(void)	{
	if (sp > 0)
		return val[--sp];
	else 	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

void peek(void)	{
	if (sp > 0)	{
		printf("%g\n", val[sp]);
	}
	else 	{
		printf("error: stack empty\n");
	}
}

void swap(void)	{
	if (sp > 1)	{ 
		double tmp;
		tmp = val[sp];
		val[sp] = val[sp-1];
		val[sp-1] = tmp;
	}
	else 	{
		printf("error: not enough elements in stack\n");
	}
}

void clear(void)	{
	sp = 0; //should be enough to simply set the pointer to 0, old values will be overwritten.
}

void duplicate(void)	{
	if (sp < MAXVAL -1)	{
		push(val[sp]);
	}
	else 	{
		printf("error: stack full\n");
	}
}

char variable = ' '; //initially as space such that malformed use of '=' won't cause segfaults


int asignment = 0; //hacky way to not push a variable to stack before it's been defined

int getop(char s[])	{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
		return c;
	i = 0;

	if (isalpha(c))	{
		while (isalpha(s[++i] = c = getch()));
		s[i] = '\0';

		if (i == 1)	{	//s is a variable
			variable = s[0];
			if ((c=getch()) == '=')
				asignment = 1;
			ungetch(c);
			return VAR;
		}

		if (strcmp(s, "sin")) //we could had done all the math.h functions but, effort
			return 1;
		if (strcmp(s, "cos"))
			return 2;
		if (strcmp(s, "tan"))
			return 3;
		if (strcmp(s, "exp"))
			return 4;

		printf("error: unsupported function or malformed input\n");
		return '\n';
	}

	if (c == '-') 	{
		s[i] = c;
		if ((c = getch()) == ' ')	{
			return '-';
		}
		else
			s[++i] = c;
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)	{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])	{
	int i;

	for (i=0; s[i] != '\0'; ++i)
		ungetchr(s[i]);
}
/*
 ungets has no need to know about buf and bufp, as implementing the function
 using these would do the job that ungetch already does, thus complicating
 the proram as a whole rather than keeping it modular with each function doing
 one specific and unique job.
 only if ungets could be written in a more efficient and faster way by directly
 accessing buf and bufp should it be done that way, but as far as I can tell,
 it makes no difference in terms of efficiancy.
 */

double variables[26];

void define(char var, double n)	{
	var = tolower(var);
	if (var >= 97 && var <= 122)
		variables[tolower(var)-97] = n;
	else 
		printf("error: variable symbol out of range\n");
}

double variableLookUp(char var)	{
	if (var >= 97 && var <= 122)
		return variables[tolower(var)-97];
	else
		printf("error: variable symbol out of range\n");
	return 0.0;
}

int main()	{
	int type;
	double op2, lastPrinted;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)	{
		switch (type)	{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				if (op2 != 0.0)	{
					op2 = pop();
					push(pop() / op2);
				}
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)	{
					push(fmod(pop(), op2));
				}
				else
					printf("error: zero divisor\n");
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case 1: //such that variables can be used, using non-printable characters for math functions
				push(sin(pop()));
				break;
			case 2:
				push(cos(pop()));
				break;
			case 3:
				push(tan(pop()));
				break;
			case 4:
				push(exp(pop()));
				break;
			case '=':
				define(variable, pop());
				break;
			case VAR:
				if (asignment == 0)	
					push(variableLookUp(variable));
				else
					asignment = 0;
				break;
				
			case '\n':
				lastPrinted = pop();
				printf("\t%.8g\n", lastPrinted);
				break;
		}
	}
	return 0;
}
