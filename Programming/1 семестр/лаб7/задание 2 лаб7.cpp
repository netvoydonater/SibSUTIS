//2. Сформировать с помощью датчика случайных чисел в диапазоне     [0,10] массив из 15 элементов целого типа. Вывести его на экран. Вывести элементы массива, исключая ранее встречавшиеся.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int arr[15];
    bool visited[11] = { false };
    int i;
    for (i = 0; i < 15; i++) {
        arr[i] = rand() % 11;
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < 15; i++) {
        if (!visited[arr[i]]) {
            printf("%d ", arr[i]);
            visited[arr[i]] = true;
        }
    }
    printf("\n");
	return 0;
}