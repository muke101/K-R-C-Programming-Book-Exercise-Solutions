/*
  Extend atof to handle scientific notation of the form
  	123.45e-6
  where a floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define BUFFER 1000

int atoi(char s[])	{
  int i, n, sign;

  for (i=0; isspace(s[i]); ++i);
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    ++i;
  for (n=0; isdigit(s[i]); ++i)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}

double atof(char s[])	{
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++);

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    ++i;
  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
    ++i;
  for (power = 1.0; isdigit(s[i]); ++i)	{
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

	if (s[i] == 'e' || s[i] == 'E' )	{
    ++i;
    char t[BUFFER];
    int j, n;
    for (j=0; s[i] != '\0'; ++j, ++i)	{
      t[j] = s[i];
    }
    t[j] = '\0';
    n = atoi(t); //wanted to use recurrsion here with atof but we haven't met that yet so keeping it category 0. Works as the expodent is always expected to be an int anyway.
    power *= pow(10,-n); //flip the sign of n as power is dividing the final value
  }

  return sign * val / power;
}

  int main()	{
    char s[] = "-123.45e-6";
    printf("%f\n", atof(s));
    return 0;
  }
