#include <stdio.h>
#include <math.h>

int calculateEasterDate(int year)
{
	int a, b, c, d, e, f, easterDate = 0;
	a = year % 19;
	b = year % 4;
	c = year % 7;
	d = (19 * a + 15) % 30;
	e = (2 * b + 4 * c + 6 * d + 6) % 7;
	f = d + e;
	if (f <= 26)
	{
		easterDate = f + 4;
		printf("%d april\n", easterDate);
	}
	if (f > 26)
	{
		easterDate = 26;
		printf("%d may\n", easterDate);
	}
	return easterDate;
}
int main()
{
	int year;
	printf("Enter the year: ");
	scanf_s("%d", &year);
	return 0;
}