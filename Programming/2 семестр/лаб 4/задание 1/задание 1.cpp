//Выполнить следующие задания, используя оператор new и функцию malloc().
//1.Задан двумерный динамический массив B  размерности m x n. (n = 5, m вводить с клавиатуры).Заполнить её случайными числами.
// Получить новую динамическую матрицу С[m - 1][n - 1]  путем удаления из В строки и столбца, в которых содержится максимальный элемент исходной матрицы.
//malloc - инициализация указателей необходимым объёмом памяти
//* - указатель
//** - указатель из указателя  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int n = 5;
typedef int rown[n];

int main() 
{
    int i, j, m;
    printf("Enter number rows: ");
    scanf_s("%d", &m);

    // Создание двумерного динамического массива B размерности m x n
    printf("Array B:\n");
    int** B = new int* [m];
    for (i = 0; i < m; i++) 
    {
        B[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) 
        {
            B[i][j] = rand() % 11; // Заполнение случайными числами
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Поиск максимального элемента
    int max_value = B[0][0];
    int max_row = 0, max_col = 0;
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (B[i][j] > max_value) 
            {
                max_value = B[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    printf("\n");

    // Создание нового динамического массива C размерности (m-1) x (n-1)
    printf("Array C:\n");
    int** C = new int* [m - 1];
    for (int i = 0, k = 0; i < m ; i++) 
    {
        if (i == max_row) continue; // Пропускаем строку с максимальным элементом
        C[k] = (int*)malloc((n - 1) * sizeof(int));
        for (int j = 0, l = 0; j < n; j++) 
        {
            if (j == max_col) continue; // Пропускаем столбец с максимальным элементом
            C[k][l] = B[i][j];
            printf("%d ", C[k][l]);
            l++;
        }
        printf("\n");
        k++;
    }

    // Освобождение памяти
    for (int i = 0; i < m; i++) 
    {
        free(B[i]);
    }
    delete[] B;

    for (int i = 0; i < m - 1; i++) 
    {
        free(C[i]);
    }
    delete[] C;

    return 0;
}

