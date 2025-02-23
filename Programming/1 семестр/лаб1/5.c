//5. x=6t^2-(ctg(z)+1)/y^2  y=2  z=4  t=sin(2+z)
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(y) = 2;
    float(z) = 4;
    float(t) = sin(2+z);
    x = 6*powf(t,2)-(cos(z)/sin(z)+1)/powf(y,2);
    printf("%f", x);
    return 0;
}