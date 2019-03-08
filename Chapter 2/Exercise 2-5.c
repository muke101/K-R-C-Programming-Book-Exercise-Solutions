/*
Write the function any(s1,s2), which returns the first 
location in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (the standards library function strpbrk does
the same job but returns a pointer to the location.)
*/

//this can aparently be made more efficient with poiners, revisit after chp 5 maybe

#include <stdio.h>
#define BUFFER 1000

int any(char s1[], char s2[])
{
	int i, j;

	for (i=0; s1[i] != '\0'; ++i)
	{
		for (j=0; s2[j] != '\0'; ++j)
		{
			if (s1[i] == s2[j])
			{
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	printf("%i", any());
	return 0;
}