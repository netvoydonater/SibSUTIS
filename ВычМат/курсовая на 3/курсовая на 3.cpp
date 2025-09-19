#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double epsilon = pow(10, -8);
const double h = 0.1;
const double a = 0.0;
const double b = 1.0;
const double Y0 = 1.0;
const double DY0 = 1.0;

void f(double x, double y, double dy, double F[2])
{
    F[0] = dy;              
    F[1] = (exp(x) + y + dy) / 3.0; 
}

void Runge_Kutta2(double a, double b, double h, double y, double dy, bool flag, double result[2])
{
    int n = static_cast<int>(round((b - a) / h)) + 1;
    double* X = new double[n];
    double Y[2] = { y, dy };

    for (int i = 0; i < n; i++)
    {
        X[i] = a + i * h;
    }

    if (flag)
    {
        cout << "Начальные условия:" << endl;
        cout << fixed << setprecision(6) << "x = " << X[0] << " | " << setprecision(13) << "y = " << Y[0] << " | y' = " << Y[1] << endl;
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        double K1[2], K2[2];

        f(X[i - 1], Y[0], Y[1], K1); 
        f(X[i - 1] + h / 2, Y[0] + h / 2 * K1[0], Y[1] + h / 2 * K1[1], K2); 

        Y[0] = Y[0] + h * K2[0]; 
        Y[1] = Y[1] + h * K2[1]; 

        if (flag)
        {
            cout << "Шаг " << i << ":" << endl;
            cout << fixed << setprecision(6) << "x = " << X[i] << " | " << setprecision(13) << "y = " << Y[0] << " | y' = " << Y[1] << endl;
        }
    }

    result[0] = Y[0];
    result[1] = Y[1];
    delete[] X;
}

void Runge_Kutta4(double a, double b, double h, double y, double dy, bool flag, double result[2])
{
    int n = static_cast<int>(round((b - a) / h)) + 1;
    double* X = new double[n];
    double Y[2] = { y, dy };

    for (int i = 0; i < n; i++)
    {
        X[i] = a + i * h; 
    }

    if (flag)
    {
        cout << "Начальные условия:" << endl;
        cout << fixed << setprecision(6) << "x = " << X[0] << " | " << setprecision(13) << "y = " << Y[0] << " | y' = " << Y[1] << endl;
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        double K1[2], K2[2], K3[2], K4[2];

        f(X[i - 1], Y[0], Y[1], K1); 
        f(X[i - 1] + h / 2, Y[0] + h / 2 * K1[0], Y[1] + h / 2 * K1[1], K2); 
        f(X[i - 1] + h / 2, Y[0] + h / 2 * K2[0], Y[1] + h / 2 * K2[1], K3); 
        f(X[i - 1] + h, Y[0] + h * K3[0], Y[1] + h * K3[1], K4); 

        Y[0] = Y[0] + h / 6 * (K1[0] + 2 * K2[0] + 2 * K3[0] + K4[0]);
        Y[1] = Y[1] + h / 6 * (K1[1] + 2 * K2[1] + 2 * K3[1] + K4[1]); 

        if (flag)
        {
            cout << "Шаг " << i << ":" << endl;
            cout << fixed << setprecision(6) << "x = " << X[i] << " | " << setprecision(13) << "y = " << Y[0] << " | y' = " << Y[1] << endl;
        }
    }

    result[0] = Y[0];
    result[1] = Y[1];
    delete[] X;
}

double dv_peresch(double eps, double h, double a, double b, double y0, double dy0, bool use_rk4)
{
    double Y1[2], Y2[2];
   

    if (use_rk4)
    {
        Runge_Kutta4(a, b, h, y0, dy0, false, Y1);
        Runge_Kutta4(a, b, h / 2, y0, dy0, false, Y2);
    }
    else
    {
        Runge_Kutta2(a, b, h, y0, dy0, false, Y1);
        Runge_Kutta2(a, b, h / 2, y0, dy0, false, Y2);
    }

    int iteration = 1;

    while (true)
    {
        cout << "ИТЕРАЦИЯ " << iteration++ << endl;
        cout << "Текущая разница: " << Y1[0]  <<  " - " << Y2[0] << " = " << fabs(Y1[0] - Y2[0]) << " (требуется < " << eps << ")" << endl;

        h /= 2.0;
        Y1[0] = Y2[0]; 
        Y1[1] = Y2[1]; 

        if (use_rk4)
            Runge_Kutta4(a, b, h / 2, y0, dy0, false, Y2);
        else
            Runge_Kutta2(a, b, h / 2, y0, dy0, false, Y2);

        if (fabs(Y1[0] - Y2[0]) < eps)
        {
            break;
        }
    }

    cout << "Точность " << eps << " достигнута!" << endl;
    cout << fixed << setprecision(15) << "Оптимальный шаг: " << h / 2 << endl;
    cout << "---------------------" << endl;
    return h / 2;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "===== Решение дифференциального уравнения =====" << endl;
    cout << "Уравнение: y'' = (e^x + y + y')/3" << endl;
    cout << "Начальные условия: " << endl;
    cout << "y(0) = " << Y0 << "\n" << "y'(0) = " << DY0 << endl;
    cout << "Интервал: [" << a << ", " << b << "]" << endl;
    cout << "Начальная длина шага h = " << h << endl;


    cout << fixed << setprecision(15) << "Введённая точность: " << epsilon << endl;

    double Y2[2];
    double Y4[2];

    double h_new2, h_new4;

    int choise = 0;
    cout << "Выберите метод: \n1. Метод Рунге-Кутта 2-го порядка с усреднением по времени. \n2. Метод Рунге-Кутта 4-го порядка. \n3. Выход." << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
        cout << "\n\t---------- МЕТОД РУНГЕ-КУТТА 2-ГО ПОРЯДКА----------" << endl;
        cout << "\n\t===== Подбор шага =====" << endl;
        h_new2 = dv_peresch(epsilon, h, a, b, Y0, DY0, false);

        cout << "\n\t===== Выполнение метода =====" << endl;
        //double Y2[2];
        Runge_Kutta2(a, b, h_new2, Y0, DY0, true, Y2);
        break;
        
    case 2:
        cout << "\n\t---------- МЕТОД РУНГЕ-КУТТА 4-ГО ПОРЯДКА ----------" << endl;
        cout << "\n\t===== Подбор шага =====" << endl;
        h_new4 = dv_peresch(epsilon, h, a, b, Y0, DY0, true);

        cout << "\n\t===== Выполнение метода =====" << endl;
        //double Y4[2];
        Runge_Kutta4(a, b, h_new4, Y0, DY0, true, Y4);
        break;

    case 3:
        break;

    default:
        cout << "Ошибка! Выберите 1, 2 или 3." << endl;
        break;
    }

    return 0;
}