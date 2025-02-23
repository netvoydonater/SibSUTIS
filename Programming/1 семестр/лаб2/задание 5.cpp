//5. Даны 4 числа. Опредделить порядковый номер наименьшего среди них
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, m;
    printf("Vvedite 4 chisla: ");
    scanf_s("%f %f %f %f", &a, &b, &c, &d);
    m = a;
    int i = 1;
    if (b < m) 
    {
        m = b; 
        i = 2; 
    }
    if (c < m) 
    { 
        m = c; 
        i = 3; 
    }
    if (d < m) 
    { 
        m = d; 
        i = 4; 
    }
    printf("Poryadkovy nomer naimenshego chisla: % d", i);
    return 0;
}
