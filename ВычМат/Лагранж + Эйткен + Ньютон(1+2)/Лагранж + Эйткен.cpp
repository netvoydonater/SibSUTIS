#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const int n = 4;

double y(int x)
{
	return sqrt(x);
}

double Proivvodnaya4(int x)
{
	double h = 1.0;
	return (y(x + h) - 4 * y(x) + y(x - h)) / pow(h, 4);
}

double factorial(int i)
{
	if (i == 0)
		return 1;
	else
		return i * factorial(i - 1);
} 

void Table()
{
	cout << "|    |   x   |   y    |" << endl;
	cout << "|----|-------|--------|" << endl;

	for (int x = 0; x <= 3; x++)
	{
		cout << "| " << x << "  |   " << x + 1 << "   |  " << fixed << setprecision(3) << y(x + 1) << " |" << endl;
	}
}

const double x_nodes[] = { 1.0, 2.0, 3.0, 4.0 };
const double y_nodes[] = { y(1), y(2), y(3), y(4) };

double Lagranje(double x)
{
	//double x;
	//double x_nodes, y_nodes;
	double result = 0.0;
	int n = 4;

	cout << "\n\t\t===== ПРОЦЕСС ИНТЕРПОЛЯЦИИ ПО ФОРМУЛЕ ЛАГРАНЖА: =====" << endl;


	for (int i = 0; i < n; ++i)
	{
		cout << "\t========== ШАГ: " << i + 1 << " ==========" << endl;
		cout << " x[" << i << "] = " << x_nodes[i] << ", y[" << i << "] = " << y_nodes[i] << endl;
		double term = y_nodes[i];
		cout << "Начальное значение y = " << term << endl;
		for (int j = 0; j < n; ++j)
		{
			if (j != i)
			{
				double multiplier = (x - x_nodes[j]) / (x_nodes[i] - x_nodes[j]);
				cout << "Умножаем на: (" << x << " - " << x_nodes[j] << ")/(" << x_nodes[i] << " - " << x_nodes[j] << ") = " << multiplier << endl;
				term *= multiplier;
				cout << "Текущее значение y = " << term << endl;
			}
		}
		cout << "Итоговое значение y для узла " << i << ": " << term << "\n\n";
		result += term;
		cout << "Результат P3(" << x << ") = " << result << "\n\n";
	}
	return result;
}

double Aitken(double x)
{
	double P[4][4] = { 0 };
	//double result = 0.0;
	int n = 4;

	cout << "\n\t\t===== ПРОЦЕСС ИНТЕРПОЛЯЦИИ ПО СХЕМЕ ЭЙТКЕНА: =====" << endl;

	cout << "\nИнициализация начальных значений Pxi(x) = y[i]: " << endl;
	for (int i = 0; i < n; i++)
	{
		P[i][0] = y_nodes[i];
		cout << "P[" << i << "] = y[" << i << "] = " << y_nodes[i] << endl;
	}

	for (int j = 1; j < n; j++)
	{
		cout << "\n\n\-------------------- УРОВЕНЬ " << j << " --------------------" << endl;
		for (int i = 0; i < n - j; i++)
		{
			cout << "\n========== ШАГ " << i + 1 << ":" << "==========" << endl;
			//cout << "Формула: P[" << i << "][" << j << "] = [ (x - x[" << i << "]) * P[" << i + 1 << "][" << j - 1 << "] - " << "(x - x[" << i + j << "]) * P[" << i << "][" << j - 1 << "] ] / (x[" << i + j << "] - x[" << i << "])" << endl;

			cout << "Значения:" << endl;
			cout << "x = " << x << endl;
			cout << "x[" << i << "] = " << x_nodes[i] << endl;
			cout << "x[" << i + j << "] = " << x_nodes[i + j] << endl;
			cout << "P[" << i + 1 << "][" << j - 1 << "] = " << P[i + 1][j - 1] << endl;
			cout << "P[" << i << "][" << j - 1 << "] = " << P[i][j - 1] << endl;

			double numerator1 = (x - x_nodes[i]) * P[i + 1][j - 1];
			double numerator2 = (x - x_nodes[i + j]) * P[i][j - 1];
			double denominator = x_nodes[i + j] - x_nodes[i];

			cout << "Числитель1: (" << x << " - " << x_nodes[i] << ") * " << P[i + 1][j - 1] << " = " << numerator1 << endl;
			cout << "Числитель2: (" << x << " - " << x_nodes[i + j] << ") * " << P[i][j - 1] << " = " << numerator2 << endl;
			cout << "Знаменатель: " << x_nodes[i + j] << " - " << x_nodes[i] << " = " << denominator << endl;

			P[i][j] = (numerator1 - numerator2) / denominator;

			cout << "Результат: (" << numerator1 << " - " << numerator2 << ") / " << denominator << " = " << P[i][j] << endl;
			cout << "P[" << i << "," << i + j << "] = " << fixed << setprecision(4) << P[i][j] << endl;
		}
	}
	return P[0][n - 1];
}

const double delta_y_nodes[] = { (y(2) - y(1)), (y(3) - y(2)), (y(4) - y(3)) };
const double delta2_y_nodes[] = { (delta_y_nodes[1] - delta_y_nodes[0]), (delta_y_nodes[2] - delta_y_nodes[1]) };
const double delta3_y_node = delta2_y_nodes[1] - delta2_y_nodes[0];

void Table_Newton()
{
	cout << "|    |   x   |   y    |   Δy   |   Δ^2y   |   Δ^3y   |" << endl;
	cout << "|----|-------|--------|--------|----------|----------|" << endl;

	cout << "| 0  |   1   |  " << fixed << setprecision(3) << y(1) << " |  " << delta_y_nodes[0] << " |          |          |" << endl;
	cout << "| 1  |   2   |  " << y(2) << " |  " << delta_y_nodes[1] << " |  " << delta2_y_nodes[0] << "  |          |" << endl;
	cout << "| 2  |   3   |  " << y(3) << " |  " << delta_y_nodes[2] << " |  " << delta2_y_nodes[1] << "  |  " << delta3_y_node << "   |" << endl;
	cout << "| 3  |   4   |  " << y(4) << " |        |          |          |" << endl;
	cout << endl;
}

double NewtonV1(double x)
{
	//const int n = 4;
	double h = 1.0;
	double g = (x - x_nodes[0]) / h;
	cout << "g = (x - x[0]) / h = " << g << endl;
	cout << endl;
	double result = y_nodes[0];

	double** delta = new double* [n];
	for (int i = 0; i < n; i++)
	{
		delta[i] = new double[n - i];
	}

	for (int i = 0; i < n; i++)
	{
		delta[0][i] = y_nodes[i];
	}

	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			delta[j][i] = delta[j - 1][i + 1] - delta[j - 1][i];
			cout << "Delta[" << j + 1 << "][" << i + 1 << "] = " << delta[j][i] << endl;
		}
	}

	double term = 1.0;
	for (int j = 1; j < n; j++)
	{
		term *= (g - (j - 1));
		result += (delta[j][0] * term) / factorial(j);
	}

	for (int i = 0; i < n; i++)
	{
		delete[] delta[i];
	}
	delete[] delta;
	
	return result;
}

double NewtonV2(double x)
{
	//const int n = 4;
	double h = 1.0;
	double g = (x - x_nodes[n - 1]) / h;
	cout << "g = (x - x[n]) / h = " << g << endl;
	cout << endl;
	double result = y_nodes[n - 1];

	double** delta = new double* [n];
	for (int i = 0; i < n; i++)
	{
		delta[i] = new double[n - i];
	}

	for (int i = 0; i < n; i++)
	{
		delta[0][i] = y_nodes[i];
	}

	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			delta[j][i] = delta[j - 1][i + 1] - delta[j - 1][i];
			cout << "Delta[" << j + 1 << "][" << i + 1 << "] = " << delta[j][i] << endl;
		}
	}

	double term = 1.0;
	for (int j = 1; j < n; j++)
	{
		term *= (g + (j - 1));
		result += (delta[j][0] * term) / factorial(j);
	}

	for (int i = 0; i < n; i++)
	{
		delete[] delta[i];
	}
	delete[] delta;

	return result;
}

double Pogreshnost(double x)
{
	double M4 = 15.0 / 16.0; // 15/16 = 0.9375
	double koef = abs((x - 1) * (x - 2) * (x - 3) * (x - 4));
	double eps_usech = (M4 / factorial(4)) * koef;
	//cout << eps_usech << endl;
	double eps_okr = pow(10, -5);
	double eps_real = eps_okr + eps_usech;
	return eps_real;
}

int main()
{
	double x;
	setlocale(LC_ALL, "ru");
	cout << "Функция y = sqrt(x)\n" << endl;
	cout << "Введите x: ";
	cin >> x;

	cout << "Таблица значений: \n" << endl;
	Table();


	double y_interpolated = 0.0;
	double y1_interpolated = 0.0;
	double newton1 = 0.0;
	double newton2 = 0.0;

	cout << "\nВыберите метод: \n1. Формула Лагранжа \n2. Схема Эйткена \n3. Формула Ньютона (1) \n4. Формула Ньютона (2) \n5. Выход" << endl;
	int choise;
	cin >> choise;
	switch (choise)
	{
	case 1:
		y_interpolated = Lagranje(x);
		cout << "------------------------------------------" << endl;
		cout << "\nИнтерполяция по формуле Лагранжа для x = " << x << endl;
		cout << "P(" << x << ") = " << fixed << setprecision(4) << y_interpolated << endl;
		cout << "Точное значение по функции y = " << y(x) << endl;
		//cout << "Разница составила: " << y_interpolated - y(x) << endl;
		cout << "Погрешность: eps = " << Pogreshnost(x) << endl;
		break;

	case 2:
		y1_interpolated = Aitken(x);
		cout << "------------------------------------------" << endl;
		cout << "\nИнтерполяция по схеме Эйткена для x = " << x << endl;
		cout << "Pn(" << x << ") = " << fixed << setprecision(4) << y1_interpolated << endl;
		cout << "Точное значение по функции y = " << y(x) << endl;
		//cout << "Разница составила: " << y1_interpolated - y(x) << endl;
		cout << "Погрешность: eps = " << Pogreshnost(x) << endl;
		break;
	case 3:
		cout << "Таблица для Ньютона: \n" << endl;
		Table_Newton();
		newton1 = NewtonV1(x);
		cout << "------------------------------------------" << endl;
		cout << "\nИнтерполяция по 1-ой формуле Ньютона для x = " << x << endl;
		cout << "Pn(" << x << ") = " << fixed << setprecision(4) << newton1 << endl;
		cout << "Точное значение по функции y = " << y(x) << endl;
		break;
	case 4:
		cout << "Таблица для Ньютона: \n" << endl;
		Table_Newton();
		newton2 = NewtonV2(x);
		cout << "------------------------------------------" << endl;
		cout << "\nИнтерполяция по 2-ой формуле Ньютона для x = " << x << endl;
		cout << "Pn(" << x << ") = " << fixed << setprecision(4) << newton2 << endl;
		cout << "Точное значение по функции y = " << y(x) << endl;
		break;
	case 5:
		break;
	default:
		cout << "Ошибка! Выберите 1, 2 или 3." << endl;
	}
	return 0;
}