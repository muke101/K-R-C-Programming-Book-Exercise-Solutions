//what we learnt: don't right shift signed bits, divide them by 2 if absolutely needed. In fact, take time to think about what you're doing when signed bits are invovled at all.

#include <stdio.h>

unsigned rotright(unsigned x, int n)
{
	/* Example with x = 11010101 (213 in decimal), n = 2
		First iteration:
			x = (01101010) | ~(11111111 >> 1) = 11101010
		Second iteration:
			x = (01110101) | ~(11111111 >> 0) = 01110101
		Returns 01110101 - in reality returns 32 bits, the result in these comments will not convert to the correct result,
		however sticking with 8 bits for readability/simplicity in explanations.
	*/

	for (; n > 0; n--)
		x = (x >> 1) | ~(~0U >> (x & 1)); //must be unsigned or you're right shifting a signed int which behaviors differently on different machines!
	return x;
}

int main()
{
	printf("%d\n", rotright(213, 2));
	return 0; 
}