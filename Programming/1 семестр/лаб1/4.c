//4.x=4ln*y^3-z/t   t=2   z=3  y=cos(t+z)
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(t) = 2;
    float(z) = 3;
    float(y) = cos(t+z);
    x = 4*log(powf(y,3))-z/t;
    printf("%f", x);
    return 0;
}