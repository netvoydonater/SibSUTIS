//6. x=(8z^2+1)/(y*e^t+t^2)  z=1  t=2  y=tg(t)+z
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float(z) = 1;
    float(t) = 2;
    float(y) = tan(t)+z;
    x = (8*powf(z,2)+1)/(y*exp(t)+powf(t,2));
    printf("%f", x);
    return 0;
}