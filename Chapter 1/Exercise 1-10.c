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