/*
Writ a function expand(s1,s2) that expands shorthand notations like a-z
in the string s1 into the equivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is 
taken literally.
*/

#include <stdio.h>
#include <ctype.h>
#define BUFFER 1000

void expand(char s[], char t[])	{

	int i, j, d=0;

	if (s[0] == '-')	{
		t[0] == '-';
	}

	for (i=1; s[i+1] != '\0'; ++i)	{
		if (s[i] == '-')	{
			for (j=0; (s[i-1] + j) <= s[i+1]; ++j)	{
				t[d+j] = s[i-1] + j;
			}
			d+=j; //displacement between s and t after adding j more characters
		}
	}

	if (s[i] == '-')	{
		t[d++] == '-';
	}

	t[d] = '\0';
}


int main()	{
	char s[BUFFER];
	char t[BUFFER];

	int i, c;

	for (i=0; (c=getchar()) != EOF; ++i)	{
		s[i] = c;
	}
	s[i] = '\0';

	expand(s,t);
	printf("%s\n", t);

	return 0;
}