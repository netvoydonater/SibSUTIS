//3. Сформировать с помощью датчика случайных чисел в диапазоне [-10,10] массив из 20 элементов вещественного типа.Вывести его на экран. Сформировать из положительных элементов массива А массив В.Вывести массив В
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
const int N = 20;
int sort(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int i, a = -10, b = 10;
    float E[20], B[20];
    srand(time(NULL));
    for (i = 0; i < N; i++)
        E[i] = (float)rand() * (b - a) / RAND_MAX + a;
    printf("Array: ");
    for (i = 0; i < N; i++)
        printf("%6.2f", E[i]);
    printf("\nPosition: ");
    for (int i = 0; i < 20; i++) {
        if (E[i] > 0) {
            B[i] = E[i];
            printf("%6.2f", B[i]);
        }
    }
	return 0;
}