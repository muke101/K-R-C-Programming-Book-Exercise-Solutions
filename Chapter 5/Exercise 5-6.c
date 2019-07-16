/*
 * Rewrite appropiate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilites include getline
 * (Chapters 1 and 4), atoi, itoa, and their varients (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define BUFFER 1000

// getline: read a line into s, return length
int getline2(char *s, int lim)	{

	int i, c;

	for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		*s++ = c;
	
	*s = '\0';

	return i;

}

// reverse: reverse the character string s
char *reverse(char *s)	{

	int i, strlen;
	char tmp, *sStart = s;

	while (*++s);

	s--; //don't reverse the null character!
	strlen = s - sStart;
	strlen = strlen % 2 == 0 ? strlen : strlen+1; //deal with odd length strings
	for (i=0; i < strlen/2; ++i)	{
		tmp = *(sStart+i);
		*(sStart+i) = *(s-i);
		*(s-i) = tmp;
	}
	
	return sStart;
}

// atof: convert s to float
double atof(char *s)	{
	
	double n;

	for (; isspace(*s) || *s == '\t'; ++s);
	
	for (n=0; isdigit(*s); ++s)
		n = n * 10 + (*s - '0');

	if (*s++ == '.')	{
		int i, d;
		for (i=0, d=0; isdigit(*s); ++i, ++s)
			d = d * 10 + (*s - '0');
		n+=(d/pow(10,i));
	}

	return n;
}

// itoa: convert n to characters in s
char *itoa(int n, char *s)	{

	int sign;
	char *sStart = s;

	if ((sign = n) < 0)
		n = -n;
	
	do	{
		*++s = n % 10 + '0';
	} while (n/=10);

	if (sign < 0)
		*++s = '-';

	*++s = '\0';

	return reverse(sStart);

}

// strrindex: return the position of the rightmost occurrence of t in s, or -1 if there is none
int strrindex(char *s, char *t)	{

	char *sStart = s, *tStart = t;

	while (*++s)	{
		if (*s == *t)	{
			char *rS = s;
			while (*++s == *++t)	{
				if (!*t)
					return rS - sStart; 
			}
			t = tStart;
		}
	}

	return -1;

}

int bufp = 0 ;
char buf[BUFFER];

char getch(void)	{
	
	return bufp > 0 ? buf[--bufp] : getchar(); 

}

void ungetch(char c)	{
	if (bufp > BUFFER)
		printf("buffer full\n");
	else
		buf[bufp++] = c;
}


int main()	{
	char s[BUFFER];
	printf("%d\n", strrindex("hello world!", "world!"));
	return 0;

}
