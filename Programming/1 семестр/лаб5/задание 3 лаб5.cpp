//3.Найти и вывести простые числа и  их количество в диапазоне от 2 до n, n ввести с клавиатуры
#include <stdio.h>

int main() 
{
    int n;
    int count = 0; 

    printf("Enter n: ");
    scanf_s("%d", &n);

    printf("Prime numbers in the range from 2 to %d:\n", n);

    int num = 2;
    while (num <= n) 
    {
        int is_prime = 1; 

        for (int i = 2; i < num; i++) 
        {
            if (num % i == 0) 
            {
                is_prime = 0; 
                break;
            }
        }

        
        if (is_prime) 
        {
            printf("%d ", num);
            count++;
        }

        num++;
    }

    printf("\nNumber of prime numbers: %d\n", count);

    return 0;
}