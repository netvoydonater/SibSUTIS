//4. Написать программу для проверки номера банковской карты по алгоритму Луна (необходимо просуммировать все четные по номеру цифры последовательности, далее прибавить к сумме все нечетные по номеру цифры, помноженные на 2, при этом если произведение получается больше 9, то из него вычитается 9. Сумма должна быть кратной 10). Пример правильного номера – 4276 4400 1336 1511
#include <stdlib.h>
#include <stdio.h>
int main() {
    int x1, x2, x3, x4;
    int A[4], C[4];
    int all, n, nech;
    int sum_ch = 0, sum_nech = 0;
    printf("Enter card number: ");
    for (int i = 0; i < 4; i++) {
        scanf_s("%d", &A[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", A[i]);
    }
    for (int i = 0; i < 4; i++) {
        n = A[i];
        for (int e = 0; e < 4; e++) {
            C[e] = n % 10;
            n = n / 10;
            if (e % 2 == 0) sum_ch += C[e];
            else {
                nech = C[e] * 2;
                if (nech > 9) sum_nech += nech - 9;
                else sum_nech += nech;
            }
        }
    }
    if ((sum_ch + sum_nech) % 10 == 0)
        printf("\nCorrect!"); 
    else printf("\nIncorrect!");
    return 0;
}