//not /really/ done but the core concept is grasped

#include <stdio.h>
#define maxLine 1000
#define True 1
#define False 0

/*comments, braces, escape sequnces, quotes (single and double)*/

int main() {

	int c, i, braces=0, comments=0, escSequence=0, singleQuote=0, doubleQuote=0, insingleQuote=False, indoubleQuote=False;
	char input[maxLine];

	for (i=0; i<maxLine-1 && (c=getchar()) != EOF; ++i) {
		input[i] = c;
	}
	input[i] = '\0';

	for (i=0; input[i] != '\0'; ++i) {
		if (input[i] == '{') {
			++braces;
		}
		if (input[i] == '}') {
			--braces;
		}
		if (input[i] == '\'' && insingleQuote == True) {
			insingleQuote = False;
			--singleQuote;
		}
		else if (input[i] == '\'') {
			insingleQuote = True;
			++singleQuote;
		}
		if (input[i] == '\\' && insingleQuote == True && (input[i+1] != 'n') && (input[i+1] != '\\') && (input[i+1] != '\'') && (input[i+1] != '\"') && (input[i+1] != 't') && (input[i+1] != '0')) {
			++escSequence;
		}
		if (input[i] == '\"' && indoubleQuote == True) {
			indoubleQuote = False;
			--doubleQuote;
		}
		else if (input[i] == '\"') {
			indoubleQuote = True;
			++doubleQuote;
		}
	}

	//printf("%s\n", input);
	printf("Number of unmatched braces: %d\n", braces);
	printf("Number of unmatched single quotes: %d\n", singleQuote);
	printf("Number of unmatched double quotes %d\n", doubleQuote);
	printf("Number of incorrect escape sequnces %d\n", escSequence);

	return 0;
}