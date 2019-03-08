/*
Write a program to copy its unput to its output, 
replacing each string of one or more blanks by a single blank
*/

#include <stdio.h>
#include <string.h>

void main(){
	int c, pc;
	while((c=getchar()) != EOF){
		if (c == ' '){
			if (pc != ' '){
				putchar(c);
			}
		}
		if (c != ' '){
			putchar(c);
		}
		pc = c;
	}
}	
