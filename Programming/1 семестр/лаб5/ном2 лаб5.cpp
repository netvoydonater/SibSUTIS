//2. a  = 2.14;  b= - 4.21;  c = 3.25; xнач= -4.5; xкон = -13.5; h = 0.5
#include <stdio.h>
#include <math.h>
int main() 
{
    float a, b, c, x1, x2, h, y, maxY = 0;
    float minY = 100000000000;
    printf("\nEnter values: \"a\" \"b\" \"c\" \"Xнач\" \"Xкон\" \"h\"\n");
    scanf_s("%f%f%f%f%f%f", &a, &b, &c, &x1, &x2, &h);
    if (x2 < x1) { y = x1; x1 = x2; x2 = y; y = 0; }
    while (x1 < x2) {
        y = (a * powf(x1, 2) + b * x1 + c) * sin(x1);
        if (y > maxY) maxY = y;
        if (y < minY) minY = y;
        x1 += h;
    }
    printf("min: %.3f | max: %.3f", minY, maxY);
    return 0;
}