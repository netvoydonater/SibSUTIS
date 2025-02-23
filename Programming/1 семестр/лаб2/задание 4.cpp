//4.   Даны 8 чисел. Определить сколько среди них отрицательных и сколько положительных.
#include<stdio.h>
#include<math.h>
int main()
{
    int count = 0;
    int count1 = 0;
    int a, b, c, d, e, f, g, h;
    printf("Enter 8 nombers:\n");
    scanf_s("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    if (a > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (b > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (c > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (d > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (e > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (f > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (g > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    if (h > 0) {
        count += 1;
    }
    else {
        count1 += 1;
    }
    printf("Number of positive numbers:%d", count);
    printf("\nThe number of negative numbers:%d", count1);
    return 0;

}

