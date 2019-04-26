/*
  Write the function strrindex(s,t), which returns the position
  of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#define BUFFER 1000

char pattern[] = "ould";

int main()	{
  char line[BUFFER];
  int len, pos, found = 0;

  while ((len=getline2(line, BUFFER)) > 0)	{
    if ((pos=strindex2(line, pattern, len))>= 0)	{
      printf("At position %d: %s",pos, line);
    found++;
    }
  }
  return found;
}

int getline2(char s[], int lim)	{
	int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strindex2(char s[], char t[], int len)	{
  int i,j,k,l;

  for (l=0; t[l] != '\0'; ++l);

  for (i=len; i >= 0; --i)	{
    for (j=i, k=0; t[k] != '\0' && s[j] == t[l-k-1]; --j, ++k); //transverse pattern array backwards, -1 to skip null char
    if (k > 0 && t[k] == '\0')	{
      return j+1;
    }
  }
  return -1;

}
