/*
Write a function invert(x,p,n) that returns x with the n bits
that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
	/*
		Example from right to left with x = 01011010 (90 in decimal), p = 4, n = 3
			mask (has the position of bits to be inverted):
			00001111 ^ 00000001 = 00001110
			return:
			01011010 & 11110001 = 01010000 
			10100101 & 00001110 = 00000100 
			01010000 | 00000100 = 01010100
	*/
	unsigned mask = ~(~0 << p) ^ ~(~0 << p-n);
	return ((x & ~mask) | (~x & mask));
}

int main()
{
	printf("%d\n", invert(90, 4, 3));
	return 0;
}