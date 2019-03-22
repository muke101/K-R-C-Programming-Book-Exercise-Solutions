/*
Writ a function expand(s1,s2) that expands shorthand notations like a-z
in the string s1 into the equivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is 
taken literally.
*/

//I do not for the life of me understand how for loop incrementation works ffs

#include <stdio.h>
#define BUFFER 1000

void expand(char s[], char t[])	{

	int i, j, d=0;

	if (s[0] == '-')	{
		t[0] = '-';
	}
	else	{
		t[0] = s[0];
	}

	for (i=1; s[i] != '\0'; ++i)	{
		if (s[i] == '-' && s[i+1] != '\0')	{ //allow trailing '-' characters
			for (j=1; (s[i-1] + j) < s[i+1]; ++j)	{ //j=1 as to not include s[i-1]
				t[i+d+(j-1)] = s[i-1] + j; //j-1 because the index of t starts where '-' would be
			}
			d+=j-2; /*displacement between s and t after adding j more characters
						-2 as takes into account '-' character's index in s and the other because for loops I guess*/
		}
		else	{
			t[i+d] = s[i];
		}
	}

	t[i+d] = '\0';
}

int main()	{
	char s[BUFFER];
	char t[BUFFER];

	int i, c;

	for (i=0; (c=getchar()) != '\n' || c == EOF; ++i)	{
		s[i] = c;
	}
	s[i] = '\0';

	expand(s,t);
	printf("%s\n", t);

	return 0;
}