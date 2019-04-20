/*
In a two's complement number representation, our version 
of itoa odes not handle the largest negative number, that is, the n equal
to -2^(wordsize-1). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs.
*/

/*
Explanation - when a negative number is passed to itoa, it is multipled by -1 and reassigned to itself (n=-n). However, for signed integers the range of values is -2^31-(2^31-1),
so asigning -(-2^31) to the signed variable n causes an integer overflow, and have n remain at -2^31. This is fixed by storing n in an unsigned variable instead 
(however this cannot be done from the function arguments, as n must still be checked against being negative or not).
*/

#include <stdio.h>
#define BUFFER 1000

int reverse(char s[])
{
  char ch;
  int i, j;

  for(j = 0; s[j] != '\0'; j++);

  --j;

  for(i = 0; i < j; i++)
  {
    ch   = s[i];
    s[i] = s[j];
    s[j] = ch;
    --j;
  }

  return 0;
}

void itoa(int n, char s[]) 	{ //this just takes numbers and turns them to their ascii versions
	int i, sign;
	unsigned k;

	if ((sign = n) < 0)	{
		k = -n;
	}
	else 	{
		k = n;
	}
	i = 0;
	do
	{
		s[i++] = k % 10 + '0';
	} while ((k /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()	{
	char s[BUFFER];
	int i, c;
	itoa(-2147483648,s);
	printf("%s\n", s);
	return 0;
}