/*
Add commands to print the top element of the stack without popping,
to duplicate it, and to swap the top two elements. Add a command to
clear the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100


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

int getop(char s[])	{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;

	if (c == '-') 	{
		s[i] = c;
		if (!isdigit(c = getch()))	{
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
	printf("%s\n", s);
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

int main()	{
	int type;
	double op2;
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
			case '\n':
				printf("\t%.8g\n", pop());
				break;
		}
	}
	return 0;
}