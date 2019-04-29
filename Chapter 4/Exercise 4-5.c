/*
Add access to library functions like sin, exp and pow.
See <math.h> in Appendix B, section 4.
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
	int i, c, j;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
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
	if (isalpha(c))	{
		j = 0;
		char t[4];

		while (isalpha(t[++j] = c = getch()));
		t[j] = '\0';

		if (strcmp(t, "sin")) //we could had done all the math.h functions but effort
			return 's';
		if (strcmp(t, "cos"))
			return 'c';
		if (strcmp(t, "tan"))
			return 't';
		if (strcmp(t, "e"))
			return 'e';
		printf("error: unsupported function or malformed input\n");
		return '\n';
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
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'c':
				push(cos(pop()));
				break;
			case 't':
				push(tan(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
		}
	}
	return 0;
}