//4. Сформировать с помощью датчика случайных чисел в диапазоне [0,20] два массива C и D, из 20 элементов целого типа каждый. 
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int sort(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int C[20], D[20], E[40];
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        C[i] = rand() % 21;
        D[i] = rand() % 21;
    }
    printf("Massiv C:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n\nArray D:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", D[i]);
    }
    qsort(C, 20, sizeof(int), sort);
    qsort(D, 20, sizeof(int), sort);
    int i = 0, j = 0, k = 0;
    while (i < 20 && j < 20)
    {
        if (C[i] < D[j])
        {
            E[k++] = C[i++];
        }
        else
        {
            E[k++] = D[j++];
        }
    }
    while (i < 20)
    {
        E[k++] = C[i++];
    }
    while (j < 20)
    {
        E[k++] = D[j++];
    }
    printf("\n\nMassiv E:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%d ", E[i]);
    }
    return 0;
}