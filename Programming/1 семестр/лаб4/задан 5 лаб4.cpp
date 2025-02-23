//5. S= 0.18x + (0.20x)**2 + (0.22x)**3 +...+ (0.36x)**10; (x = 1, s = 0.236)
#include <stdio.h>
#include <math.h>

int main()
{
	double x = 1.0;
	double s = 0;
	printf("Enter x: \n");
	scanf_s("%d", &x);

	for (int i = 1; i <= 10; i++)
	{
		s += pow((0.18 * x), i);
		x += 0.0999 * x;
	}
	printf("S = %.3f\n", s);
	return 0;
}