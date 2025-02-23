#include <stdio.h>

void F()
{
	int n;
	scanf_s("%d", &n);
	if (n != 0)
	{
		F();
	}
	if (n > 0 && n % 10 == 0)
	{
		printf("%d\t", n);
	}
}

int main()
{
	F();
}