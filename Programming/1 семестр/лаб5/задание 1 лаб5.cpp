//1.Вычислить приближенно значение числа Пи c помощью ряда лейбница с точностью до e=0.00001, где Pi = 4 * (1 - 1 / 3 + 1 / 5 - 1 / 7 + 1 / 9….)
#include <stdio.h>

int main() {
    double pi = 0.0;
    double dr = 1.0;
    int q = 1;
    int n = 1;
    double e = 0.00001;

    while (dr > e) {
        pi += q * dr;
        q *= -1;
        n += 2;
        dr = 1.0 / n;
    }
    pi *= 4;
    printf("4islo pi: %.5f\n", pi);
    return 0;
}