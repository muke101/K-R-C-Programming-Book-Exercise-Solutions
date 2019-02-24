/*It seems a practical solution to calculate these values doesn't exist only using what's given so far in K&R*/

#include <stdio.h>
#include <limits.h>

int power(int number, int power)
{
	int raisedNumber = number;

	for(int i=1; i < power; ++i)
	{
		raisedNumber = raisedNumber*number;
	}
	return raisedNumber;
}

int sign(int range)
{
	int negative, positive;

	if (range % 2 == 0)
	{
		positive = negative = range/2;
		return 
	}
	else
	{
		negative = (range+1)/2;
		positive = (range-1)/2;
		return negative, positive;
	}
}

int main()
{
	printf("Short int range:%d\n", power(2,16));
	printf("Long int range:%d\n", power(2,32));
	printf("char range:%d\n", power(2,8));
	printf("Singned short int:%s\n", sign(power(2,16)));
	return 0;
}