//3. Даны 4 числа. Все отрицательные среди них числа заменить на 0. 
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c, d;
	printf("Vvedite 4 chisla: \n");
	scanf_s("%d%d%d%d", &a, &b, &c, &d);
    if (a < 0) {
        a = 0;
    }
    if (b < 0) {
        b = 0;
    }
    if (c < 0) {
        c = 0;
    }
    if (d < 0) {
        d = 0;
    }
    printf("A = %d", a);
    printf("\nB = %d", b);
    printf("\nC = %d", c);
    printf("\nD = %d", d);
    return 0;
}
