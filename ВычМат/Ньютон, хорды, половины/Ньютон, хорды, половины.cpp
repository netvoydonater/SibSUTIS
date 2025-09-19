#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return pow(x, 2) - 2;
}

double Proizvodnaya1(double x)
{
	double h = 1.0;
	double f1;
	// производная 1-го порядка
	f1 = (f(x + h) - f(x - h)) / (2 * h);
	return f1;
}

double Proizvodnaya2(double x)
{
	double f2;
	double h = 1.0;
	// производная 2-го порядка
	f2 = (f(x + h) - 2 * f(x) + f(x - h)) / pow(h, 2);
	return f2;
}

void method_Newton(double x)
{
 	int step = 1;
	double eps = 0;
	double x0 = Proizvodnaya2(x);
	do
	{
		cout << "\t\tШАГ " << step << endl;
		// формула x(n) = x(n - 1) - f(x(n - 1))/f`(x(n - 1))
		double x1 = x0 - (f(x0) / Proizvodnaya1(x0));
		// eps = x[n] - x[n -1]

		eps = abs(x0 - x1);
		x0 = x1;
		cout << "Частота: e = x[n] - x[n -1] = " << eps << endl;

		cout << "X = " << x0 << endl;
		step++;
	} while (eps > pow(10, -8));
}

double bisection_method(double x, double a, double b)
{
	int step = 1;
	double c;
	double eps = 0;
	do
	{
		cout << "\t\tШАГ " << step << endl;
		c = (a + b) / 2;
		cout << "Половина интервала: C = (a + b)/2 = " << c << endl;
		cout << "Значение функции f(x) = x^2 -2 при x = " << x << " в точке C: f(c) = " << f(c) << endl;

		eps = abs(b - a) / 2;
		cout << "Интервал: (" << a << "; " << b << ")" << endl;
		cout << "Частота: e = |b - a|/2 = " << eps << endl;
		if (f(c) == 0.0)
			return c;
		else if (f(a) * f(c) < 0)
			b = c;
		else
			a = c;
		cout << "Новый интервал: (" << a << "; " << b << ")\n\n";

		step++;
	} while (eps > pow(10, -8));
	return c;
}

double horda_method(double x, double a, double b)
{
	int step = 1;
	double c;
	double c0 = a;
	double eps = 0;
	do
	{
		cout << "\t\tШАГ " << step << endl;
		c = (a * f(b) - b * f(a)) / (f(b) - f(a));
		cout << "Половина интервала: C = (a * f(b) - b * f(a)/f(b) * f(a) = " << c << endl;
		cout << "Значение функции f(x) = x^2 -2 при x = " << x << " в точке C: f(c) = " << f(c) << endl;

		eps = abs(c - c0);
		cout << "Частота: e = c[n] - c[n - 1] = " << eps << endl;
		cout << "Интервал: (" << a << "; " << b << ")" << endl;

		if (f(c) == 0.0)
			return c;
		else if (f(a) * f(c) < 0)
			b = c;
		else
			a = c;
		cout << "Новый интервал: (" << a << "; " << b << ")\n\n";

		c0 = c;
		step++;
	} while (eps > pow(10, -8));
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Функция x^2 - 2 = 0" << endl;
	double x, a, b;
	cout << "Введите x: ";
	cin >> x;
	cout << "Выберите метод: \n1. Метод половинного деления \n2. Метод хорд \n3. Метод Ньютона \n4. Выход" << endl;
	int choise;
	cin >> choise;

	switch (choise)
	{
	case 1:
		system("CLS");
		cout << "Метод половинного деления: \n";
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		bisection_method(x, a, b);
		break;
	case 2:
		system("CLS");
		cout << "Метод хорд: \n";
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		horda_method(x, a, b);
		break;
	case 3:
		system("CLS");
		cout << "Выражение x^2 - 2 = " << f(x) << "\tпри x = " << x << endl;
		cout << "Производная 1-го порядка: " << Proizvodnaya1(x) << endl;
		cout << "Производная 2-го порядка: " << Proizvodnaya2(x) << endl;
		method_Newton(x);
		break;
	case 4:
		break;
	default:
		cout << "Ошибка. Выберите 1, 2 или 3" << endl;
	}
	return 0;
}