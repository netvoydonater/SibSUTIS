//Тарифы
#include <stdio.h>
#include <math.h>
int main()
{
    float x = 200;
    float min = 50;
    float gb = 25;
    float c, a, d, n, itog;

    int ispmin;
    printf("Vvedite kolichestvo min: \n");
    scanf_s("%d", &ispmin);

    if (ispmin > min);
    c = ispmin - min;
    a = c * 1;

    int ispgb;
    printf("Vvedite kolichestvo gb: \n");
    scanf_s("%d", &ispgb);

    if (ispgb > gb);
    d = ispgb - gb;
    n = d * 25;

    itog = (n + a + x);
    printf("Ishodny tarif: 200 p\n", n);
    printf("Dop oplata za gb: %f\n", n);
    printf("Dop oplata za minutu: %f\n", a);
    printf("Itog: %f", itog);

    return 0;
}
