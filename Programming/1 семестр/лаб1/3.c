//3. x=4y^2/(4y*e^z-2t^3) t=1 z=3 y=sin(t)
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(t) = 1;
    float(z) = 3;
    float(y) = sin(t);
    x = 4*powf(y,2)/(4*y*exp(z)-2*powf(t,3));
    
    printf("%f", x);
    return 0;
}