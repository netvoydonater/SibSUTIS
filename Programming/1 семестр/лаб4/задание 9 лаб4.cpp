//9. S= 1+ x/1! + x2/2!+...+ xN/N!, N>0 вводится с клавиатуры. (x=5, N=10, s=146.38)
#include <stdio.h>
#include <math.h>

int main()
{
	int i, il, n = 0;
	int faq = 1;
	float s = 1;
	int x = 5;
	printf("Enter N, if N>0: ");
	scanf_s("%d", &n);
	while (n <= 0)
	{
		printf("Error! Repeat attend: ");
		scanf_s("%d", &n);
	}
	for (i = 1; i < n + 1; i++)
	{
		faq = 1;
		for (il = 1; il <= i; il++)
		{
			faq *= il;
		}
		s += (pow(x, i) / faq);
	}
	printf("%.2f", s);
	return 0;
}