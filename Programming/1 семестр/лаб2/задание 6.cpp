//6. Даны четыре числа. Найти разность между наибольшим и наименьшим среди них.
#include <iostream>
#include<math.h>
int main()
{
    int a, b, c, d;
    printf("Enter 4 nombers:\n");
    scanf_s("%d%d%d%d", &a, &b, &c, &d);
    int max = -1000;
    int min = 1000;
    if (max < a) max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;
    printf("MAX = %d", max);
    if (min > a) min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    if (min > d) min = d;
    printf("\nMIN = %d", min);
    int n = max - min;
    printf("\nMAX - MIN = %d", n);

    return 0;
}
