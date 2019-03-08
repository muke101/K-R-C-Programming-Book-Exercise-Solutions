/*
Write a program detab that replaces tabs in the input with the 
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columnes. Should n be a variable or a symbolic paramter?
*/

#include <stdio.h>
#define tabStop 10 /*Saw no reason for a constant value to be stored as a variable.*/
#define maxInput 1000

int main(){
	int c, i;
	char input[maxInput]; /*Book doesn't specify what it wants you to do with the input, so I'm just storing it.*/

	for (i = 0; i<maxInput-1 && (c=getchar()) != EOF; ++i){
		if (c != '\t')
			input[i] = c;
		else{
			for (int j = 0; j <= tabStop; ++j, ++i){
				input[i] = ' ';
			}
			--i; /*Need to deincrement i to compensate for the incremention as the nested for loops returns to the original for loop.*/
		}
	}

	input[i] = '\0';

	return 0;
}