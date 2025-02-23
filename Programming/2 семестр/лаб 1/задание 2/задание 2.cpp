#include <stdio.h>
float power(float x, int n)
{
    float result = 1.0;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            result *= x;
        }
    }
    else if (n < 0) 
    {
        for (int i = 0; i < -n; i++)
        {
            result /= x;
        }
    }
    return result;
}

int main() {
    float x;
    int n;
    printf("Enter a real number x: ");
    scanf_s("%f", &x);
    printf("Enter an integer power n: ");
    scanf_s("%d", &n);
    printf("%f^%d = %f\n", x, n, power(x, n));

    return 0;
}