/* There is no error checking in day_of_year or month_day.
 * Remedy this defect.
 */

#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* set day of year from month & day */
int day_of_year(int year, int month, int day)	{
	
	int i, leap;
	
	if (year < 1752 || month < 1 || month > 12 || day < 1)
		return -1;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pda)	{

	int i, leap;

	if (year < 1752 || month < 1 || month > 12 || day < 1)
		return -1;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pda = yearday;
}

int main()	{
	int *pmonth, *pda;
	printf("%d\n", day_of_year(2011, 5, 12));
	month_day(2011, 240, pmonth, pda);
	printf("%d %d\n", *pmonth, *pda); 
	return 0;
}
