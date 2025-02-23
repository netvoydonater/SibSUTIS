#include <stdio.h>
#include <math.h>

int factorial(int n) // вычисление факториала
{
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

void calculateProbability(int n, int m, float p, float q, float* probability) // вычисление вероятности по формуле C(n, m) * p^m * q^(n-m)
{
    if (n < 0 || m < 0 || m > n || p < 0 || p > 1) // Проверка на корректность входных данных
    {
        *probability = -1; // Отрицательное значение как признак ошибки (вероятность)
        return;
    }

    int cnm = factorial(n) / (factorial(m) * factorial(n - m)); // Вычисление вероятности
    *probability = cnm * pow(p, m) * pow(q, n - m);
}

int main()
{
    int totalChildren, girls;
    float girlProbability = 0.45;
    float boyProbability = 1 - girlProbability;

    printf("Enter the total number of children: ");
    scanf_s("%d", &totalChildren);

    printf("Enter the number of girls among the children: ");
    scanf_s("%d", &girls);

    float girlProbabilityResult, boyProbabilityResult;

    calculateProbability(totalChildren, girls, girlProbability, boyProbability, &girlProbabilityResult);
    calculateProbability(totalChildren, girls, boyProbability, girlProbability, &boyProbabilityResult);

    if (girlProbabilityResult >= 0 && boyProbabilityResult >= 0)
    {
        printf("Probability of having %d girls among %d children: %f\n", girls, totalChildren, girlProbabilityResult);
        printf("Probability of having %d boys among %d children: %f\n", totalChildren - girls, totalChildren, boyProbabilityResult);
    }
    else printf("Error: Invalid input data.\n");

    return 0;
}
