/*
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at mot the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
*/

#include <stdio.h>
#define BUFFER 1000

char *strncpy2(char *s, char *t, int n)	{

	int i;
	char *sStart = s;

	for (i=0; i < n && (*s++ = *t++); ++i);
	
	if (i == n)
		*s = '\0';

	return sStart;
}

char *strncat2(char *s, char *t, int n)	{
	
	while (*++s);

	return strncpy2(s, t, n);
}

int strncmp2(char *s, char *t, int n)	{
	
	int i;

	for (i=0; i < n && *s == *t; ++i, ++s, ++t)	{
		if (i == n || !*s)
			return 0;
	}

	return *s - *t;
}

int main()	{
	int i;
	char s[BUFFER] = "hello";
	char t[BUFFER] = "hello world!";
	i = strncmp2(s,t,6);
	printf("%d\n", i);
	return 0;
}
