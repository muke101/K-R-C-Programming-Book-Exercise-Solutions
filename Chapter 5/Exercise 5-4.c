/*
 * Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise
*/

#include <stdio.h>

int strend(char *s, char *t)	{
	char *tstart = t;
	while (*s)	{
		if (*++s == *t)	{
			while (*++s == *++t)	{
				if (!*s && !*t)
					return 1;
				}
			t = tstart;
			}
		}	
	return 0;
}

int main()	{
	printf("%d\n", strend("hello world!", "world!"));
	return 0;
}
