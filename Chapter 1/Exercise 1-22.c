/*
Write a program to "fold" long input lines into two or more shorter
lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with the very
long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>
#define fold 12
#define maxLine 1000

int main() {

	int i, j, c;
	char line[maxLine];

	for (i = 0, j = 0; i < maxLine-1 && (c=getchar()) != EOF; ++i, ++j) {
		if (c == ' ' && j >= fold) { /*adds a newline character upon seeing the first blank character after the j counter passes the fold limit*/
			j = 0; /*sets the j counter back to 0 such that lines are folded continiously throughout input*/
			line[i] = c;
			line[++i] = '\n';
		}
		else {
			line[i] = c;
		}
		if (j > fold*3) { /*arbitary multiple of fold limit to deal with very long lines without blank characters*/
			j = 0;
			line[i] = c;
			line[++i] = '\n';
		}
	}

	line[i] = '\0';
	printf("%s", line);

	return 0;
}