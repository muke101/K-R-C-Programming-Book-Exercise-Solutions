/* Write a program that prints its input one word per line */

#include <stdio.h>

#define IN 1
#define OUT 0

void main(){
	int c, nl, nw, nc, state, counter;

	counter = 0;
	state = OUT;
	nl = nw = nc = 0;
	while (counter != 20){
		c = getchar();
		++nc;
		if (c == '\n'){
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			putchar('\n');
		}
		else if (state == OUT){
			state = IN;
			++nw;
		}
		if (state == IN){
			putchar(c);
		}
		++counter;
	}
	printf("%d %d %d\n", nl, nw, nc);
}