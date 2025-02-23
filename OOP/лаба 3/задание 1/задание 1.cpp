#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <locale>

using namespace std;

class Matrix
{
private:
    int** Arr;    
    int rows;     
    int cols;      
    int sum;       

public:
    Matrix() : rows(0), cols(0), Arr(nullptr), sum(0) {} //конструктор по умолчанию (размерность 0)

    Matrix(int size) : rows(size), cols(size), sum(0) //конструктор, инициализирующий единичную квадратную матрицу 
    {
        Arr = new int* [rows];
        for (int i = 0; i < rows; ++i) 
        {
            Arr[i] = new int[cols];
            for (int j = 0; j < cols; ++j) 
            {
                if (i == j)
                    Arr[i][j] = 1;  
                else
                    Arr[i][j] = 0;  
            }
        }
    }

    Matrix(int r, int c) : rows(r), cols(c), sum(0) //конструктор, принимающий размерность матрицы, для инициализации матрицы указ. размера
    {
        Arr = new int* [rows];
        for (int i = 0; i < rows; ++i) 
        {
            Arr[i] = new int[cols];
            for (int j = 0; j < cols; ++j) 
            {
                Arr[i][j] = 0;  
            }
        }
    }

    ~Matrix() //деструктор, корректно очищающий динам.память от матрицы
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] Arr[i];
        }
        delete[] Arr;
    }

    void input() 
    {
        cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                cin >> Arr[i][j];
            }
        }
    }

    void FillRand() 
    {
        srand(time(0));
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                Arr[i][j] = rand() % 100;  
            }
        }
    }

    void print() const 
    {
        cout << "Матрица (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << Arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Summa() 
    {
        sum = 0;
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                sum += Arr[i][j];
            }
        }
    }

    void print_summa() const 
    {
        cout << "Сумма элементов матрицы: " << sum << endl;
    }

    void proizvedenie_rows_cols() //метод заполнения матрицы произведением номера строки и столбца
    {
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                Arr[i][j] = i * j;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    // Часть I. Создаем матрицы разными конструкторами
    Matrix M1;                  
    Matrix M2(3);               
    Matrix M3(3, 4);            
    Matrix M4(2, 3);           

    // Часть II. Демонстрация работы с матрицами
    cout << "Матрица M2 (единичная матрица):\n";
    M2.print();

    cout << "Матрица M3:\n";
    M3.print();

    cout << "Матрица M4:\n";
    M4.print();

    //заполнение матриц и вывод
    M2.proizvedenie_rows_cols();
    cout << "Матрица M2 после заполнения произведением индексов строки и столбца:\n";
    M2.print();
    M3.FillRand();
    cout << "Матрица M3 после заполнения случайными числами:\n";
    M3.print();
	M3.Summa();
    M3.print_summa();

    M4.input();
    cout << "Матрица M4 после ввода с клавиатуры:\n";
    M4.print();

    return 0;
}