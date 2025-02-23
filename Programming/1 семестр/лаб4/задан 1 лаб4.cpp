//1. S= 1+ 2 + 3+...+ 117;  (s=6903)
#include <stdio.h>
#include <math.h>

int main()
{
	int s = 0;
	int i;
	for (int i = 1; i <= 117; i++)
	{
		s += i;
	}
	printf("S = %d\n", s);
	return 0;
}