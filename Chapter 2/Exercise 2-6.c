/*
Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/*
	Taken from left to right operations (seperated by or operands) with examples x=01011101, p=4, n=3, y=11010011 (numbers here in binary, decimal representations used in program)
		00000111 & 11010011 << 4-3 = 00000110 - the 'mask'
		11110000 & 01011101 = 01010000 - find all bits past point p
		00000001 & 01011101 = 00000001 - find all bits before p-n (the range of bits to be changed)
		00000001 | 01010000 | 00000110 = 00000001 | 01010110 = 01010111 which is the correct awnser
	*/
	return ((~(~0<<p-n) & x) | (((~0<<p) & x) | ((~(~0 << n) & y) << p-n)));
}

int main()
{
	printf("%d\n",setbits(93,4,3,211));
	return 0;
}