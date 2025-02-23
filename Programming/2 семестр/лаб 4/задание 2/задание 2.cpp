#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, m, n;
    printf("Enter number rows m: ");
    scanf_s("%d", &m);
    printf("Enter number column n: ");
    scanf_s("%d", &n);

    // Выделение памяти под двумерный динамический массив A[m][n]
    int** A = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
    {
        A[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            A[i][j] = rand() % 11; // случайное число от 0 до 10
        }
    }

    // Выделение памяти под массив D[m+1][n+1] и инициализация элементов нулями
    int** D = (int**)malloc((m + 1) * sizeof(int*));
    for (i = 0; i < m + 1; i++)
    {
        D[i] = (int*)malloc((n + 1) * sizeof(int));
        for (j = 0; j < n + 1; j++)
        {
            D[i][j] = 0;
        }
    }

    // Заполнение массива D и вычисление сумм
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            D[i][j] = A[i][j];
            D[i][n] += A[i][j]; // Сумма элементов строки
            D[m][j] += A[i][j]; // Сумма элементов столбца
            D[m][n] += A[i][j]; // Сумма всех элементов
        }
    }

    // Вывод массива D с суммами строк и столбцов
    printf("Array D:\n");
    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);

    for (i = 0; i < m + 1; i++)
    {
        free(D[i]);
    }
    free(D);

    return 0;
}
