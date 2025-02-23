//2. x=3y^2/(4tg(z)-2t^2)  y=t+2ctg(z) t=0.5 z=6
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(t) = 0.5;
    float(z) = 6;
    float(y) = t+2*(cos(z)/sin(z));
    x = 3*powf(y,2)/(4*tan(z)-2*powf(t,2));
    
    printf("%f", x);
    return 0;
}