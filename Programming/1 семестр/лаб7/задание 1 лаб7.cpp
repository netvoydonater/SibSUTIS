//1. Вычислить и записать в массив значения функции y=a*x2*sin(x)+b*x+c при изменении x от хнач до хкон с шагом h. Массив значений отсортировать по убыванию методом пузырька и напечатать.  
#include <stdio.h>
#include <math.h>
int main()
{
    double a = 2.14, b = -4.21, c = 3.25, x1 = -4.5, h = 0.5, y, arr[58];
    for (int i = 0; i < 58; i++) {
        y = a * powf(x1, 2) * sinf(x1) + b * x1 + c;
        arr[i] = y;
        x1 -= h;
        printf("%.2f  ", arr[i]);
    }
    printf("\nSorting: ");
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size - 1; i++) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 58; i++)
        printf("%.2f  ", arr[i]);
	return 0;
}