//you can be a lot more literal with using characters as bounds than you'd expect

#include <stdio.h>
#include <ctype.h>
#define BUFFER 1000

int power(int b, int p)
{
	int r=b;

	if (p == 0)
		return 1;

	for (; p > 1; --p)
		r = r*b;
	return r;
}

int ctoi(char c) //take character string of hex number and convert each number into it's respective integer
{
	if (isdigit(c))
		return c - '0';
	else
		return 10 + ((tolower(c) - '0') - 49); //ASCII value of 'a' is 49, 'b' 50 etc
}

int main()
{	
	int i, j, c, n;
	char s[BUFFER];

	for (i=0; i<BUFFER && (c=getchar()) != '\n' && c != EOF; ++i)
	{
		if (c == 'x' && s[i-1] == '0')
		{
			--i;
			--i;
		}
		else
			s[i] = c;
	}

	for (n=0, j=0; j != i; ++j)
		n = n + ctoi(s[j])*power(16, (i-j)-1);

	printf("%d\n", n);

	return 0;
}