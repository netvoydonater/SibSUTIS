//3. 3.	Сформировать с помощью датчика случайных чисел в диапазоне [0,10] массив из 20 элементов вещественного типа. Вывести его на экран. Вывести элементы массива, большие своих соседей справа и слева.
#include <stdlib.h>
#include <stdio.h>
const int N = 10;
int random(int N) { return rand() % N; }
int main() 
{
    int i, a = 0, b = 10, e = 20;
    float C[20];
    for (i = 0; i < e; i++)
        C[i] = (float)rand() * (b - a) / RAND_MAX + a;
    printf("Array C: \n");
    for (i = 0; i < e; i++)
        printf("%6.2f", C[i]);
    printf("\nArrays: \n");
    for (i = 1; i < e - 1; i++) {
        if ((C[i] > C[i - 1]) && (C[i] > C[i + 1])) printf("%5.2f ", C[i]);
    }
    return 0;
}