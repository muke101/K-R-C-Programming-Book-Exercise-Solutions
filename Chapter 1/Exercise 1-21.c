#include <stdio.h>
#define tabStop 4
#define maxInput 10000

int main(){

	int i, c, b, n, t, index, nonBlank;
	char input[maxInput];

	for (i = 0; i<maxInput-1 && (c=getchar()) != EOF; ++i){
		if (c != ' ')
			input[i] = c;
		else {
			input[i] = c; /*add the first blank to the array*/
			index = i; /*stores location in character array at start of blanks*/
			for (b = 1; (c=getchar()) == ' '; ++b, ++i); /*counts the number of blanks (b) until the next non-blank character. b starts at 1 as blank has already been seen*/
			nonBlank = c; /*saves the first seen non-blank character to be re-added later (as getchar() will have taken it in from input and will now stay at that point of the input)*/
			if (b >= tabStop){ /*if the tab space fits inside the number of blanks, otherwise there is nothing to be done*/
				for (n = 0, t = 0; (t+tabStop) <= b; ++n) /*counts the culmnative total of tab 'spaces' (t) and the number of tab stops (n) that fit in number of blanks*/
					t += tabStop;
				i = index;
				for (int x = 0; x < n; ++x, ++i) /*loops over the number of tabs to be added starting from the first blank in the array found up until the first non-blank*/
						input[i] = '\t';
				while (t < b){ /*if true, there are remaining blanks not filled in by tabs*/
					input[i] = ' ';
					++t;
					++i;
					}
				}
				input[i] = nonBlank; /*puts the first seen non-blank character into place, as getchar() has already covered it and so it wouldn't otherwise be added like other non-blanks*/
			}
		}

	input[i] = '\0';
	printf("%s", input);

	return 0;
}

