//2. S= sin1 + sin 2 +...+ sin25;  (s=-0.058)
#include <stdio.h>
#include <math.h>

int main()
{
	double s = 0;
	int i;
	for (i = 1; i <= 25; i++)
	{
		s += sin(i);
	}
	printf("S = %.3f\n", s);
	return 0;
}