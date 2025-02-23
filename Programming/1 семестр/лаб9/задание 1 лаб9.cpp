//1
#include <stdio.h>
void swapRow(int a[][20], int i1, int i2)
{
    for (int j = 0; j < 20; j++)
    {
        int temp;
        temp = a[i1][j];
        a[i1][j] = a[i2][j];
        a[i2][j] = temp;
    }

}
int main()
{
    int a[10][20];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            a[i][j] = i * 20 + j + 1;
        }
    }
    for (int i = 0; i < 10; i += 2) 
    {
        swapRow(a, i, i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
