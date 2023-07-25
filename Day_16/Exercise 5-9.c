#include <stdio.h>

static char daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

//Main function
int main(int argc, char *argv[]) 
{
	int a, b;

	printf("Number of day in this year = %d\n\n", day_of_year(2023, 6, 14)); // The date is 14th june 2023 as an input

	month_day(2023, 165, &a, &b); //pointer as a day and month and 165th day the date.
	printf("The date is: %dth month, %dth day\n", a, b);

	return 0;
}
/**
 * Calculates the day of the year based on the given date.
 *
 * @param year  The year.
 * @param month The month.
 * @param day   The day.
 * @return     The day of the year, or -1 if the date is invalid.
 */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
	if (year >= 1582 && month > 0 && month <= 12 && day > 0 && day <= *(*(daytab + leap) + month)) // Using Pointer instated of indexing
	{
		for (i = 1; i < month; i++)
		{
			day += *(*(daytab + leap) + i); // Using Pointer instated of indexing
		}
			
		return day;
		
	}
	else
		return -1;
}


/**
 * Calculates the month and day based on the given day of the year.
 *
 * @param year     The year.
 * @param yearday  The day of the year.
 * @param pmonth   Pointer to the variable to store the month.
 * @param pday     Pointer to the variable to store the day.
 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (year >= 1582 && yearday > 0 && (yearday <= 366 && leap || yearday <= 365)) 
	{
		for (i = 1; yearday > *(*(daytab + leap) + i); i++) // Using Pointer instated of indexing
		{
			yearday -= *(*(daytab + leap) + i); // Using Pointer instated of indexing
		}
		*pmonth = i;
		*pday = yearday;
	}
	else
		*pmonth = *pday = -1;
}

