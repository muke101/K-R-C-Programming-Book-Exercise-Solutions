/*
In a two's complement number system, x &= (x-1) deletes the 
rightmost 1-bit in x. Explain why. Use this overservation to writer a faster 
version of bitcount
*/

#include <stdio.h>

/* 'Explain  why x&=(x-1) deletes the rightmost 1-bit in x':
Given any byte, subtracting 1 will flip the rightmost 1-bit. It will also likely change
other bits, but when &'ed with the original byte, these changes are reverted, but
the rightmost 1-bit being flipped will always result in the rightmost 1-bit of the newly 
asigned byte being 0.
*/



//Supposedly faster, although timing ./a.out using both functions both return 0.001s!

int bitcount(unsigned x)	{
	int b=0;
	while (x != 0)	{
		x &= (x-1);
		b++;
	}

	return b;
}

int main()	{
	printf("%d\n", bitcount(25));
	return 0;
}