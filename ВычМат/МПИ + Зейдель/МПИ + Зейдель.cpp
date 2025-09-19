#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void print_matrix(double** M, int rows, int cols)
{
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void print_matrix1(double* M, int rows)
{
    cout << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << M[i] << "\t";
        cout << endl;
    }
}

double* X0(double** M, int n)
{
    double* x0 = new double[n];
    cout << "\nМатрица X0: " << endl;
    for (int i = 0; i < n; i++)
    {
        x0[i] = 0;
        cout << x0[i] << endl;
    }
    cout << endl;
    return x0;
}

double** matrixA(double** M, int n)
{
    double diag;
    double** A = new double* [n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n + 1];
        diag = M[i][i];
        for (int j = 0; j < n + 1; j++)
        {
            A[i][j] = M[i][j] / diag;
        }
    }
    return A;
}

double** matrixC(double** M, int n)
{
    double** C = new double* [n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                C[i][j] = 0;
            else
                C[i][j] = M[i][j];
        }
    }
    return C;
}

double* matrixB(double** M, int n)
{
    double* B = new double[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = M[i][n];
    }
    return B;
}

int Norm(double** C, double* B, int n)
{
    /*double c1 = abs(C[0][1]) + abs(C[0][2]);
    double c2 = abs(C[1][0]) + abs(C[1][2]);
    double c3 = abs(C[2][0]) + abs(C[2][1]);
    double norm_C = max({ c1, c2, c3 });
    cout << "\nНорма матрицы C по формуле: ||C|| = max(C[1][2] + C[1][3], C[2][1] + C[2][3], C[3][1] + C[3][2]) = " << norm_C << endl;

    double b1 = abs(B[0]);
    double b2 = abs(B[1]);
    double b3 = abs(B[2]);
    double norm_B = max({ b1, b2, b3 });
    cout << "Норма матрицы B по формуле: ||B|| = max(B[1], B[2], B[3]) = " << norm_B << endl;

    double N = ceil((log(eps * (1 - norm_C) / norm_B)) / log(norm_C));
    cout << "Количество шагов: N = " << N << endl;
    */

    double C_max = 0;
    double B_max = 0;
    double C_var = 0;
    double B_var = 0;
    double eps = pow(10, -3);

    for (int i = 0; i < n; i++)
    {
        C_var = B_var = 0;
        for (int j = 0; j < n; j++)
        {
            C_var += abs(C[i][j]);
        }
        B_var += abs(B[i]);
        if (C_var > C_max)
            C_max = C_var;
        if (B_var > B_max)
            B_max = B_var;
    }
    cout << "||C|| = " << C_max << endl;
    cout << "||B|| = " << B_max << endl;

    double N = ceil((log(eps * (1 - C_max) / B_max)) / log(C_max));
    cout << "Количество шагов: N = " << N << endl;
    return N;
}

void Zeidel_method(double** M, double* B, double** C, int n)
{
    double* x0 = X0(M, n);
    int step = 0;
    int n1 = Norm(C, B, n);

    for (int st = 0; st < n1; st++)
    {
        cout << "\nШАГ " << step + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            double var = 0;
            for (int j = 0; j < n; j++)
            {
                var += C[i][j] * x0[j];
            }
            x0[i] = B[i] - var;
            cout << x0[i] << endl;
        }
        step++;
    }

    delete[] x0;
}

void Simple_Iterations_Steps(double** M, double* B, double** C, int n)
{
    double* x0 = X0(M, n);
    int step = 0;
    double n1 = Norm(C, B, n);

    for (int st = 0; st < n1; st++)
    {
        double* xnew = new double[n];
        cout << "\nШАГ " << step + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            double var = 0;
            for (int j = 0; j < n; j++)
            {
                var += C[i][j] * x0[j];
            }
            xnew[i] = B[i] - var;
        }
        for (int i = 0; i < n; i++)
        {
            x0[i] = xnew[i];
            cout << x0[i] << endl;
        }
        step++;
        delete[] xnew;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;

    cout << "Введите размер матрицы: ";
    cin >> n;

    fstream file("Matrix1.txt");
    if (!file)
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    double** M = new double* [n];
    double** A = new double* [n];
    double** C = new double* [n];
    double* B = new double[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new double[n + 1];
        for (int j = 0; j < n + 1; ++j)
        {
            file >> M[i][j];
        }
    }
    double** x = new double* [n];
    for (int i = 0; i < n; i++)
    {
        x[i] = new double[1];
        x[i][0] = 0;
    }

    cout << "\nИсходная матрица: " << endl;
    print_matrix(M, n, n + 1);

    cout << "\nМатрица A:" << endl;
    A = matrixA(M, n);
    print_matrix(A, n, n + 1);

    cout << "\nМатрица C:" << endl;
    C = matrixC(A, n);
    print_matrix(C, n, n);

    cout << "\nМатрица B:" << endl;
    B = matrixB(A, n);
    print_matrix1(B, n);

    cout << "\nВыберите метод: \n1. Метод Зейделя \n2. Метод простых итераций \n3. Выход" << endl;
    int choise;
    cin >> choise;

    switch (choise)
    {
    case 1:
        cout << "\n\t========== МЕТОД ЗЕЙДЕЛЯ: ==========" << endl;
        Zeidel_method(M, B, C, n);
        cout << "\nНорма: " << endl;
        Norm(C, B, n);
        break;
    case 2:
        cout << "\n\t========== МЕТОД ПРОСТЫХ ИТЕРАЦИЙ: ==========" << endl;
        Simple_Iterations_Steps(M, B, C, n);
        cout << "\nНорма: " << endl;
        Norm(C, B, n);
        break;
    case 3:
        break;
    default:
        cout << "Ошибка! Выберите 1, 2 или 3." << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
        delete[] A[i];
        delete[] C[i];
        delete[] x[i];
    }
    delete[] M;
    delete[] A;
    delete[] C;
    delete[] B;
    delete[] x;

    return 0;
}