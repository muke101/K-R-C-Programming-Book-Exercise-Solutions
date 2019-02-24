#include <stdio.h>

#define MAXWORDLEN 10
#define IN 1 
#define OUT 0

void main(){
	int c, state, letters, counter;
	int wordLengths[MAXWORDLEN+1];

	for (int i = 0; i < MAXWORDLEN; ++i){
		wordLengths[i] = 0;
	}
	counter = letters = 0;
	while (counter != 20){
		c = getchar();
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			if (letters != 0){
				++wordLengths[letters];
				letters = 0;
			}
		}
		else{
			state = IN;
		}
		if (state == IN){
			++letters;
		}
		++counter;
	}
	for (int i = 0; i < MAXWORDLEN; ++i){
		printf("%d: ", i);
		for (int j = 0; j < wordLengths[i]; ++j){
			printf("-");
		}
		printf("\n");
	}
}