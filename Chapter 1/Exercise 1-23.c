/*
Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly.
C comments do not nest.
*/

/*suggestion for future - when dealing with getchar on the fly is sticky, store everything in an array first and then work on that*/

#include <stdio.h>
#define True 1
#define False 0
#define maxLine 1000

int main() {

	int i, c;
	int inComment, inQuote = False;
	char input[maxLine];

	for (i = 0; i<maxLine-1 && (c=getchar()) != EOF; ++i) {
		if (c == '"') { 
			if (inQuote == True) {
				inQuote = False;
			}
			else {
				inQuote = True;
			}
		}
		if (c == '/' && inQuote == False) {
			if (getchar() == '*') {
				--i; /*deincrement i to account for the for loop incrementing i upon seeing the next non-comment character*/
				inComment = True;
				while (inComment && c != EOF) { /*if the comment never ends program won't enter infinite loop*/
					if ((c=getchar()) == '*') {
						if (getchar() == '/') {
							inComment = False;
							}
						}
					}
				}
			else { /*as far as I know, there is no instance in which '/' should show up in a C program without being in quotes.*/
				input[i] = c; /*To be safe though, this deals with such a case*/
				}
			}
		else {
			input[i] = c;
			}
	}

	input[i] = '\0';
	printf("%s", input);

	return 0;
}