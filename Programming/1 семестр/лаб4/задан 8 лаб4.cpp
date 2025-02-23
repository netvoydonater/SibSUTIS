//8. P= 2* 4* 6*...* 12;   (P=46080)
#include <stdio.h>
#include <math.h>

int main()
{
	int p = 1;

	for (int i = 2; i <= 12; i += 2)
	{
		p *= i;
	}
	printf("P = %d\n", p);
	return 0;
}