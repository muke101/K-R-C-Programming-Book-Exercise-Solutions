/*
 * Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat(s,t) copies the string t to the end of s
*/

#include <stdio.h>
#define BUFFER 1000

void strcat2(char *s, char *t)	{
	
	while (*++s); //iterate pointer to end of string s

	while (*s++ = *t++);
}


int main()	{
	char s[] = "hello ";
	char t[] = "world!";
	strcat2(s, t);
	printf("%s\n", s);
	return 0;
}
