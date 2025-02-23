//S= tg2 + tg4 +...+ tg(N*2); N = ввести с клавиатуры (при N=19 S=1)
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	double s = 0;
	int i;

	printf("N: ");
	scanf_s("%d", &n);
	if (n > 0) {
		for (i = 2; i <= n * 2; i += 2)
		{
			s += tan(i);
		}
		printf("S = %.3f\n", s);
	}
	else
	{
		printf("Error!\n");
	}
	
	return 0;
}