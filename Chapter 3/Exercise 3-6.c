/*
Write a version of itoa that accepts three arguments instead of 
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough.
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

void itoa(int n, char s[], int w) 	{
	int i, sign, j;
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

	if (i < w)	{
		for (j=0; j <= (w-i); ++j)	{
			s[i+j] = ' '; //j starts at 0 because i is already incremented an extra time from do-while
		}
		s[i+j] = '\0'; //restore replaced null character
	}
}

int main()	{
	char s[BUFFER];
	itoa(-423,s,6);
	printf("%s\n",s);
	return 0;
}