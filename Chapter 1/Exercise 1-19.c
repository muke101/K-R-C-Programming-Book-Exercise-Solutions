/*
Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>
#define MAXLINE 1000

void reverse(char str[], int lim);

int c; /*defining c as a global variable so it's value can be checked in main*/

int main(){
	char line[MAXLINE];
	while (c != EOF){ 
		reverse(line, MAXLINE);
		printf("%s", line);
	}
	return 0;
}

void reverse(char s[], int lim){
	int i, len, j;

	for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = c;
		++i;
	}	/*just the getline function from the book*/

	s[i] = '\0';
	len = i;
	char n[len]; /*defines a constant length of the string (as i gets altered) and a temporary character array to store the reversed characters (directly using s causes problems)*/

	for (j = 0; j <= len-2; --i){
		if (s[i] != '\0' && s[i] != '\n'){
			n[j] = s[i];
			++j;
		}
	}	/*swaps around every non newline and null terminator character*/

	n[j+1] = '\n';
	n[j+2] = '\0'; /*adds on the missing characters to the end such that they don't get placed in the middle of the new strings*/

	for (i = 0; n[i] != '\0'; ++i){
		s[i] = n[i];
	}	/*copies the temporary character array back to the array given as an argument*/

}