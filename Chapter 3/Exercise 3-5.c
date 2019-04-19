/*
Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob(n,s,16) formats n as a hexadecimal integer in s.
*/

/*
max base of 32
*/

#include <stdio.h>
#define BUFFER 1000

void discardnewline(char s[])
{
  int i;
  for(i = 0; s[i] != '\0'; i++)
  {
    if(s[i] == '\n')
      s[i] = '\0';
  }
}

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

void itob(int n, char s[], int b) 	{
	int i, j, sign, c;
	unsigned k = 0;

	if ((sign=n) < 0)	{
		k = -n;
	}
	else	{
		k = n;
	}
	i = 0;

	do
	{
		j = k % b;
		s[i++] = (j < 9) ? (j + '0'):((j-10) + 'A');
	} while (k /= b);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


int main()	{

	char s[BUFFER];

	itob(255, s, 32);
	printf("%s\n", s);

	return 0;
}