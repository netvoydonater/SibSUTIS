//1. Написать функцию, которая вычисляет периметр и площадь треугольника. 
// В функцию передаётся длина его сторон. (периметр)
// Результаты возвращаются через параметры-указатели. 
// В функции также предусмотреть ошибку в введённых данных 
// (если такой треугольник может существовать, функция возвращает 1, иначе 0 через своё имя).
//P = a + b + c
//S = √(p(p - a)*(p - b)*(p - c))
#include <iostream>
#include <cmath>

int calculateTriangle(float a, float b, float c, float* P, float* S)
{
    if (a + b > c && a + c > b && b + c > a) 
    {
        *P = a + b + c;
        float p = *P / 2;
        *S = sqrt(p * (p - a) * (p - b) * (p - c));
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() 
{
    float side1, side2, side3;
    std::cout << "Enter the lengths of the sides of the triangle: ";
    std::cin >> side1 >> side2 >> side3;

    float P, S;
    int result = calculateTriangle(side1, side2, side3, &P, &S);

    if (result == 1) 
    {
        std::cout << "Perimeter: " << P << std::endl;
        std::cout << "Area: " << S << std::endl;
    }
    else 
    {
        std::cout << "Error: The triangle with sides " << side1 << ", " << side2 << ", " << side3 << " cannot exist." << std::endl;
    }

    return 0;
}
