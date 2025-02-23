//1. x=2y+3*sinh(t)-z  y=2 t=5/(1+y^2) z=4
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(y) = 2;
    float(z) = 4;
    float(t) = 5/(1+powf(y,2));
    x = 2*y+3*sinh(t)-z;
    
    printf("%f", x);
    return 0;
}