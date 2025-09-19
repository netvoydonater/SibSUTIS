#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return pow(x, 2) - 6 * x;
}

void Golden_ratio(double a, double b)
{
	double phi = (3 - sqrt(5)) / 2; 
	double eps = pow(10, -5); 
	double lyambda1 = 0;
	double lyambda2 = 0;
	int step = 0;
	while ((b - a) / 2 >= eps) 
	{
		cout << endl;
		cout << "----------ШАГ " << step + 1 << "----------" << endl;
		lyambda1 = a + phi * (b - a); 
		lyambda2 = a + (1 - phi) * (b - a); 
		cout << "Лямбда1 = " << lyambda1 << endl;
		cout << "Лямбда2 = " << lyambda2 << endl;
		cout << "f(Лямбда1) = " << f(lyambda1) << endl;
		cout << "f(Лямбда2) = " << f(lyambda2) << endl;
		if (f(lyambda1) > f(lyambda2))
		{
			a = lyambda1;
			cout << "а = Лямбда1 = " << a << endl;
		}
		else
		{
			b = lyambda2;
			cout << "b = Лямбда2 = " << b << endl;
		}
		double x = (a + b) / 2;
		cout << "Минимум функции находится в интервале [" << a << "; " << b << "]" << endl;
		cout << "Приблизительное значение минимума: x = " << x << endl;
		cout << "Значение функции f(" << x << ") = " << f(x) << endl;
		step++;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Функция: f(x) = x^2 - 6x" << endl;

	double a, b;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;

	if (a >= b)
	{
		cout << "Ошибка! a должно быть меньше b." << endl;
		return 1;
	}

	cout << "Интервал [" << a << "; " << b << "]" << endl;


	Golden_ratio(a, b);

	return 0;
}