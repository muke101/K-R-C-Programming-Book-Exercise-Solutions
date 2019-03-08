//when integers are divided, no rounding takes place for decimal remainders. Instead the floor is effecitevly taken by traunicating the data

#include <stdio.h>

int binsearch(int x, int v[], int n)	{

	int low, mid, high;
	
	low = 0;
	high = n-1;
	while (low < high)	{
		mid = (low+high)/2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}

	if (x == v[low])
		return low;
	else
		return -1;
}

/*
both functions are timed to 0.001 seconds (I guess it's easier to see the difference on CPU's from the 80's)
however, in reality the new binsearch has a better worst case but a worse best cas
as the old one would instantly return if input was best case, while the new one still has
to iterate a few times, even if they're faster iterations.
*/

int main()	{ 
	int var[] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d\n", binsearch(4,var,10));
	return 0;
}