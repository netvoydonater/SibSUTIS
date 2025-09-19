#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double epsilon = pow(10, -8);
double* Find_Y(int n, double* x)
{
    double* y = new double[n];
    for (int i = 0; i < n; i++)
    {
        y[i] = 1 / x[i];
    }
    return y;
}

void Print_Table(int n, double* x, double* y) 
{
    cout << "\tX\t\tY";
    cout << "\n-----------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << x[i] << "\t|";
        cout << "   " << y[i] << endl;
        cout << "-----------------------------------\n";
    }
}

double Trapecia(int n, double* x, double* y) 
{
    double result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double slag = (x[i + 1] - x[i]) * (y[i] + y[i + 1]) * 0.5;
        result += slag;
    }
    cout << "\nРЕЗУЛЬТАТ = " << result << endl;
    return result;
}

double Simpson(int n, double* x, double* y) 
{
    /*if ((n - 1) % 2 != 0) 
    {
        cout << "Для метода Симпсона требуется четное количество интервалов!" << endl;
        return -1;
    }
*/
    double result = 0;
    for (int i = 0; i < n - 1; i += 2) 
    {
        double h = x[i + 1] - x[i];
        double slag = h / 3 * (y[i] + 4 * y[i + 1] + y[i + 2]);
        result += slag;
    }
    cout << "\nРЕЗУЛЬТАТ = " << result << endl;
    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double a;
    double b;
    double h;

    cout << "Введите нижний предел: a = ";
    cin >> a;
    cout << "Введите верхний предел: b = ";
    cin >> b;
    cout << "Введите шаг: h = "; 
    cin >> h;

    cout << "Точность: e = ";
    cout << fixed << setprecision(12) << epsilon << endl;

    int n = ((b - a) / h ) + 1;
    cout << "n = " << n << endl;

    double* x = new double[n];
    x[0] = a;
    for (int i = 1; i < n; i++)
    {
        x[i] = x[i - 1] + h;
    }

    double* y = Find_Y(n, x);
    Print_Table(n, x, y);

    double prev_result = 0;


    cout << "\n\n---------------------- ФОРМУЛА ТРАПЕЦИИ ----------------------\n";
    double trapecia = Trapecia(n, x, y);
    //double epsilon = pow(10, -8);

    double new_h = h;
    int iteration = 1;
    while (true)
    {
        new_h /= 2;
        cout << "При методе двойного пересчёта h = " << new_h << endl;
        int new_n = ((b - a) / new_h) + 1;
        //cout << "n = " << new_n << endl;
        if (new_n <= 1) 
            break;

        double* new_x = new double[new_n];
        new_x[0] = a;
        for (int i = 1; i < new_n; i++) 
        {
            new_x[i] = new_x[i - 1] + new_h;
        }

        double* new_y = Find_Y(new_n, new_x);
        //Print_Table(new_n, new_x, new_y);
        prev_result = trapecia;
        cout << "\nПРИ h = " << new_h;
        trapecia = Trapecia(new_n, new_x, new_y);

        delete[] new_x;
        delete[] new_y;

        if (abs(trapecia - prev_result) < epsilon) 
        {
            cout << "\n\nДОСТИГНУТА ТОЧНОСТЬ при h = " << new_h << " на итерации " << iteration << endl;
            cout << "ОТВЕТ: " << trapecia;
            break;
        }
        iteration++;
    }

    /*cout << "\n\n---------------------- ФОРМУЛА СИМПСОНА ----------------------\n";
    double simpson = Simpson(n, x, y);
    new_h = h;
    iteration = 1;
    while (true)
    {
        new_h /= 2;
        //cout << "При методе двойного пересчёта h = " << new_h << endl;
        int new_n = ((b - a) / new_h) + 1;
        //cout << "n = " << new_n << endl;
        if (new_n <= 1)
            break;

        double* new_x = new double[new_n];
        new_x[0] = a;
        for (int i = 1; i < new_n; i++)
        {
            new_x[i] = new_x[i - 1] + new_h;
        }

        double* new_y = Find_Y(new_n, new_x);
        //Print_Table(new_n, new_x, new_y);
        prev_result = simpson;
        cout << "\nПРИ h = " << new_h;
        simpson = Simpson(new_n, new_x, new_y);

        delete[] new_x;
        delete[] new_y;

        if (abs(simpson - prev_result) < epsilon)
        {
            cout << "\n\nДОСТИГНУТА ТОЧНОСТЬ при h = " << new_h << " на итерации " << iteration << endl;
            cout << "ОТВЕТ: " << simpson << "\n\n\n\n";
            break;
        }
        iteration++;
    }*/

    delete[] x;
    delete[] y;

    return 0;
}