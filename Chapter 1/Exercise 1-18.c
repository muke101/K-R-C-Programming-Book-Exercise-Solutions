/*
Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

/* you can use for statements without bodies to incredment/deincrement variables up to certain points! */

#include <stdio.h>
#define MAXLINE 1000
#define True 1
#define False 0

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = getline2(line, MAXLINE)) > 0){
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0){
		printf("%s", longest);
	}

	return 0;
}

int getline2(char s[], int lim){
	int c, i, inWord;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		if (c == ' ' || c == '\t'){
			if (inWord == True) {
				s[i] = c;
				inWord = False;
			}
			if (inWord == False) {
				
			}
		}
		else {
			inWord = True;
			s[i] = c;
		}
	}
	inWord = False;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0'){
		++i;
	}
}