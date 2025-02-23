//Сгенерировать одномерный динамический массив A из m элементов. 
//Вводится число k (k<m). Получить из А матрицу B, по k элементов в строке.  
//Если m не кратно k,  недостающие элементы последней строки дополнить нулями.
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int* A, int m, int k) 
{
    int rows = m / k + (m % k != 0); // Вычисляем количество строк в матрице B
    int** B = (int**)malloc(rows * sizeof(int*)); // Выделяем память под указатели на строки
    for (int i = 0; i < rows; i++) 
    {
        B[i] = (int*)calloc(k, sizeof(int)); // Выделяем память под элементы строки и инициализируем нулями
        for (int j = 0; j < k; j++) 
        {
            if ((i * k + j) < m)
            {
                B[i][j] = A[i * k + j]; // Заполняем элементами из массива A
            }
        }
    }


    // Выводим матрицу B
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Освобождаем выделенную память
    for (int i = 0; i < rows; i++) 
    {
        free(B[i]);
    }
    free(B);
}

int main() 
{
    int m, k;
    printf("Enter number elements in array A (m): ");
    scanf_s("%d", &m);

    int* A = (int*)malloc(m * sizeof(int));// Выделяем память под массив A
    printf("Enter elements of array A:\n");
    for (int i = 0; i < m; i++)
    {
        scanf_s("%d", &A[i]);
    }

    printf("Enter number k (k < m): ");
    scanf_s("%d", &k);

    createMatrix(A, m, k);

    free(A); // Освобождаем память массива A

    return 0;
}
