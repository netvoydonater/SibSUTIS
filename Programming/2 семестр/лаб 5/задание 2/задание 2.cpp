/*Создать двумерный массив с переменной длиной строки, в который записать таблицу умножения следующего вида:
   1
   2   4
   3   6   9
   4   8  12 16
   5  10 15 20 25
   6  12 18 24 30 36
   7  14 21 28 35 42 49
   8  16 24 32 40 48 56 64
   9  18 27 36 45 54 63 72 81
 
*/
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int rows = 9; // Количество строк в таблице умножения
    int** multiplicationTable = (int**)malloc(rows * sizeof(int*)); // Выделение памяти под указатели на строки

    // Заполнение двумерного массива таблицей умножения
    for (int i = 0; i < rows; i++)
    {
        multiplicationTable[i] = (int*)malloc((i + 1) * sizeof(int)); // Выделение памяти под элементы строки
        for (int j = 0; j <= i; j++) 
        {
            multiplicationTable[i][j] = (i + 1) * (j + 1); // Заполнение элемента таблицы умножения
        }
    }

    // Вывод таблицы умножения
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            printf("%4d ", multiplicationTable[i][j]);
        }
        printf("\n");
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; i++) 
    {
        free(multiplicationTable[i]);
    }
    free(multiplicationTable);

    return 0;
}
