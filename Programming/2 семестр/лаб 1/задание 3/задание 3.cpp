#include <stdio.h>
#include <math.h>

double factorial(int n) 
{
    if (n == 0) 
    {
        return 1;
    }
    return n * factorial(n - 1);
}

double myCos(double x) 
{
    double result = 1.0;
    double term = 1.0;
    int n = 1;
    double eps = 0.0001;

    while (1) {
        term *= -1 * x * x / (2 * n * (2 * n - 1));
        if (fabs(term) < eps) 
        {
            break;
        }
        result += term;
        n++;
    }
    return result;
}

int main() 
{
    double x;
    printf("Enter a value for x in radians: ");
    scanf_s("%lf", &x);

    double myCosinus = myCos(x);
    double stdCosinus = cos(x);

    printf("My cos(%lf) = %lf\n", x, myCosinus);
    printf("Standard cos(%lf) = %lf\n", x, stdCosinus);

    return 0;
}
