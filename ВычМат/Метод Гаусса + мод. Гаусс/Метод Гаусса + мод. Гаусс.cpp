#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void PrintMatrix(double** M, int n)
{
    cout << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            cout << M[i][j] << "\t";
        }
        cout << "\n";
    }
}
void SwapSTR(double** matrix, int size)
{
    int index = 0;
    int maxValue = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (abs(matrix[i][0]) > abs(maxValue))
        {
            maxValue = matrix[i][0];
            index = i;
        }
    }
    if (index != 0)
    {
        swap(matrix[0], matrix[index]);
        cout << "\nСтрока номер " << index + 1 << " поменялась со строкой номер " << 1 << endl;
    }
    /*else
        cout << "\nНет обмена";*/
}

void EditMatrixToZero(double** M, int size, int stroka)
{
    double x;
    for (int i = stroka + 1; i < size; i++)
    {
        x = -M[i][stroka] / M[stroka][stroka];
        cout << endl;
        cout << "Будет занулён элемент " << M[i][stroka] << " в строке " << i + 1;
        for (int j = 0; j < size + 1; j++)
        {
            M[i][j] += M[stroka][j] * x;
        }
        PrintMatrix(M, size);
        if (M[i][stroka] == 0)
            cout << "Зануление произошло!" << endl;
        else
            cout << "Зануления не было!"<< endl;

    }
}
void Find_X(double** M, int size)
{
    double* ArrayForX = new double[size];
    for (int i = size - 1; i >= 0; i--)
    {
        ArrayForX[i] = M[i][size];
        for (int j = i + 1; j < size; j++)
        {
            ArrayForX[i] -= M[i][j] * ArrayForX[j];
        }
        ArrayForX[i] /= M[i][i];
    }
    cout << "\nНайденные X:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "x" << (i + 1) << " = " << ArrayForX[i] << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите размер матрицы: " << endl;
    cin >> n;

    fstream file("Matrix.txt");
    double** M = new double* [n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new double[n + 1];
        for (int j = 0; j < n + 1; ++j)
            file >> M[i][j];
    }
    cout << "Матрица " << n << "*" << n << ": " << endl;
    PrintMatrix(M, n);

    int answer = 0;
    cout << "\nВыберите метод: " << endl;
    cout << "1. Метод Гаусса. \n2. Модифицированный метод Гаусса. \n3. Выход." << endl;
    cin >> answer;
    switch (answer)
    {
    case 1:
        for (int i = 0; i < n - 1; i++)
        {
            EditMatrixToZero(M, n, i);
        }
        Find_X(M, n);
        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
        {
            SwapSTR(M, n);
            PrintMatrix(M, n);
            EditMatrixToZero(M, n, i);
        }
        Find_X(M, n);
        break;
    case 3:
        break;
    default:
        break;
    }

    return 0;
}
