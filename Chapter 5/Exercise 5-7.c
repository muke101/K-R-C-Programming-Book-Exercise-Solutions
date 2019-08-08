/* Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster
 * is the program?
 */

#include <stdio.h>
#include <string.h>
#define BUFFER 1000

void writelines(char *lineptr[], int nlines)	{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)	{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)	{

	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getline2(char *s, int lim)	{

	int i, c;

	for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		*s++ = c;
	
	*s = '\0';

	return i;

}

int readlines(char **lineptr, int maxlines, char *lineStore)	{
	int len, nlines;
	int totalLen = 0;
	char line[BUFFER];

	nlines = 0;
	while ((len = getline2(line, BUFFER)) > 0)
		if (nlines >= maxlines)
			return -1;
		else	{
			//printf("%c",line[len]);
			line[len] = '\0';
			strcpy(lineStore+totalLen, line);
			*lineptr++ = lineStore+totalLen;
			totalLen += len+1;
			nlines++;
		}
	return nlines;
}

char *lineptr[BUFFER];

int main()	{
	int nlines;
	char lineStore[BUFFER];

	if((nlines = readlines(lineptr, BUFFER, lineStore)) >= 0)	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else	{
		printf("error: input too big to sort\n");
		return 1;
	}

	return 0;
}
