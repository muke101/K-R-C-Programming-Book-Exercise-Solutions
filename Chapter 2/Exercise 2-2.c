/*
Write a loop equivalent to the for loop above without using && or ||
*/

#include <stdio.h>
#define MAXLINE 10

int main()
{
	int i,c;
	char s[MAXLINE];

	for (i=0; i<MAXLINE-1; ++i)
	{
		if ((c=getchar()) != '\n')
		{
			if (c != EOF)
			{
				s[i] = c;
			}
		}
	}	
	s[i] = '\0';
	printf("%s", s);
	return 0;
}
