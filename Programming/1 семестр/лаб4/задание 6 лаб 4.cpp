//6. S= 1 - 2 + 3 - 4 + ...  N , N > 0 выводится с клавиатуры. (n = 20, s = -10)
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int s = 0;

	printf("Enter N: ");
	scanf_s("%d", &n);

	if (n > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				s -= i;
			}
			else
			{
				s += i;
			}
		}
		printf("S = %d\n", s);
	}
	else
	{
		printf("Error!");
	}
	return 0;
}