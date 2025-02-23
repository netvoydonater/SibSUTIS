//2.Даны 5 чисел.  Вычислить сумму положительных среди них чисел.
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, d, e;
	printf("Vvedite 5 chisel:");
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int x, y, z, v, k;
	if (a > 0) {
		x = a;
	}
	else {
		x = 0;
	}
	if (b > 0) {
		y = b;
	}
	else {
		y = 0;
	}
	if (c > 0) {
		z = c;
	}
	else {
		z = 0;
	}
	if (d > 0) {
		v = d;
	}
	else {
		v = 0;
	}
	if (e > 0) {
		k = e;
	}
	else {
		k = 0;
	}
   
	int l = x + y + z + v + k;
    printf("%d", l);
    return 0;
}