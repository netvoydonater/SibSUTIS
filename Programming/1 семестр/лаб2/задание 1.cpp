// 1.  Даны 6 чисел.На сколько их сумма меньше или больше их произведения ?
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, e, f;
    printf("Enter 6 numbers:\n");
    scanf_s("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int sum = (a + b + c + d + e + f);
    int pr = (a * b * c * d * e * f);
    float n = (sum - pr);
    float m = (pr - sum);

    if (sum > pr) {
        printf("Summa > proizvedenia na = %f", n);
    }
    else {
        printf("Proizvedenie > summy na = %f", m);
    }
    return 0;
}
