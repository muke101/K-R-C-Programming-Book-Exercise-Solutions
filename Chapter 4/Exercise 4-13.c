/*
 Write a recursive version of the function reverse(s), which
 reverses the string s in place.
*/

#include <stdio.h>
#define BUFFER 1000

void reverse(char s[])	{
	static int c = 0;
	static int i = 0;
	if (c == 0)	{
		for (; s[i] != '\0'; ++i); 
		--i;
	}

	int tmp = s[c];
	s[c] = s[i-c];
	s[i-c] = tmp;
	c++;
	if (s[c] == '\0')		
		return;
	reverse(s);
}


int main()	{
	char s[BUFFER];
	int i,c;
	for (i=0; i<BUFFER-1 && (c=getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	reverse(s) ;
	printf("%s\n", s);
	return 0;
}	
