//4. S= ln 0.1 + ln 0.3 +...+ ln1.9  (s=-2.726)
#include <stdio.h>
#include <math.h>

int main()
{
	double s = 0;
	double i;

	for (i = 0.1; i <= 1.9; i += 0.2)
	{
		s += log(i);
	}
	printf("S = %.3f\n", s);
	return 0;
}