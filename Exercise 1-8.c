#include <stdio.h>

void main(){
	int c, nl, tb, bk = 0;
	while((c = getchar()) != EOF){
		if (c == '\n'){ 
			++nl;
			printf("newlines: %d\n", nl);
		} 
		if (c == '\t'){
			++tb;
			printf("tabs: %d\n", tb);
		}
		if (c == ' '){
			++bk;
			printf("spaces: %d\n", bk);
		}
	}
}