/*
 Adapt the idea of printd to write a recursive version of itoa;
 that is, convert an integer into a string by using a recursive routine
*/

#include <stdio.h>
#define BUFFER 1000

int c = 0;
unsigned k;

void itoa(int n, char s[])	{
	if (n < 0)	{
		s[c] = '-';
		c++;
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	s[c] = n % 10 + '0';
	c++;
	s[c] = '\0';
}

int main()	{
	char s[BUFFER];
	itoa(-1432432, s);
	printf("%s\n", s);
	return 0;
}
