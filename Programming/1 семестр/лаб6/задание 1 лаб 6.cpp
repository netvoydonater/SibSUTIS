//1. Сформировать с помощью датчика случайных чисел в диапазоне [-10,10] массив из 20 элементов целого типа. Вывести его на экран.  Затем вывести на экран  все положительные элементы массива, и все отрицательные элементы.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int randomp(int N) { return rand() % N; }
int main() {
    int a, arr[20];
    for (int i = 0; i < 21; i++) {
        a = randomp(11);
        a = a * powf(-1, randomp(10)); 
        arr[i] = a;
    }
    printf("Massiv: [");
    for (int i = 0; i < 21; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
    printf("+ numbers: ");
    for (int i = 0; i < 21; i++) {
        if (arr[i] > 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
    printf("- numbers: ");
    for (int i = 0; i < 21; i++) {
        if (arr[i] < 0)
            printf("%d ", arr[i]);
    }
    return 0;
}