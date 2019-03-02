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
}

int main()
{
	printf("%i", any());
	return 0;
}