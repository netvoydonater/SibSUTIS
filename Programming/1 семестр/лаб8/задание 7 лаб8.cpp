#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n = 1000; //10, 100, 1000
    float arr[1001], x, h, y, a = 1, b = 30, s1 = 0, s2 = 0, s3 = 0, s4 = 0; // 11, 101, 1001
    h = (b - a) / n;
    n++;
    x = a;
    printf("Arrive: ");
    while (x <= b)
    {
        for (int i = 0; i < n; i++)
        {
            y = 1 / sqrtf(0.02 + 0.01 * x);
            arr[i] = y;
            x += h;
            printf("%.2f , ", arr[i]);
        }
    }
    n--;
    for (int i = 1; i < n; i++)
    {
        s1 += arr[i];
    }
    s1 += arr[0] / 2 + arr[1000] / 2; //10, 100, 1000
    s1 *= h;
    printf("\nTrapezoid formula: %.2f", s1);
    for (int i = 1; i < n; i += 2)
    {
        s2 += arr[i];
    }
    s2 *= 4;
    for (int i = 2; i < n; i += 2)
    {
        s3 += arr[i];
    }
    s3 *= 2;
    s2 += s3 + arr[0] + arr[1000]; //10, 100, 1000
    s2 *= h / 3;
    printf("\nSimspon's formula: %.2f", s2);
}