/*
Write an alternate version of squeeze(s1,s2) that deletes
each character in s1 that matches any character in string s2.
*/

#include <stdio.h>
#define BUFFER 1000

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int conflict = 0;

	for (i=0; s1[i] != '\0'; ++i)
	{
		for (j=0; s2[j] != '\0' && conflict != 1, ++j)
		{
			if (s1[i] == s2[j])
				conflict = 1;
		}
		if (conflict == 0)
		{
			s1[k++] = s1[i];
		}
		else
		{
			conflict = 0;
		}
	}
	s1[k] = '\0'

}

int main()
{
	return 0;
}