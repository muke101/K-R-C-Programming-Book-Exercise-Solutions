/*
Write a function escape(s,t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/

#include <stdio.h>
#define BUFFER 1000

void escape(char s[], char t[])	{

	int i, j=0; /*j is used as a counter to track how far ahead t is over s 
				when multiple characters need to be added in the place of one*/

	for (i=0; s[i-j] != '\0'; ++i)	{
		switch(s[i-j])	{
			case '\n':
				t[i] = '\\';
				t[++i] = 'n';
				++j;
				break;
			case '\t':
				t[i] = '\\';
				t[++i] = 't';
				++j;
				break;
			default:
				t[i] = s[i-j];
				break;
		}
	}

	t[i] = '\0';
}

void reverseEscape(char s[], char t[])	{

	int i, j=0;

	for (i=0; s[i+j] != '\0'; ++i)	{
		switch(s[i+j])	{
			case '\\':
				switch(s[i+j+1])	{
					case 'n':
						t[i] = '\n';
						++j;
						++i; //increment i to skip next character
						break;
					case 't':
						t[i] = '\t';
						++j;
						++i;
						break;					
				}
			default:
				t[i] = s[i+j];
				break;
		}
	}
	
	t[i] = '\0';
}

int main()	{

	int i, c;
	char s[BUFFER], t[BUFFER];

	for (i=0; i<BUFFER-1 && (c=getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';

	escape(s,t);
	printf("%s\n", t);
	return 0;
}