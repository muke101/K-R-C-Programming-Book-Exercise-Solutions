/*
Write a program to copy its input to its output, replacing each
tab by \t, each backspace by \b, and each backslash by \\.
This makes tabs and backsapces visable in an unambiguous way.
*/

#include <stdio.h>

void main(){
	int c;
	while((c = getchar()) != EOF){
		if (c == '\\'){ 
			c = '\\';
		} 
		if (c == '	'){
			c = '\t';
		}
		if (c == ' '){
			c = ' ';
		}
		putchar(c);
	}
}