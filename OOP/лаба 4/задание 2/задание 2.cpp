#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Matrix
{
private:
    T** M; //Т - шаблонный параметр
    int m;
    int n;

public:
    Matrix() : m(0), n(0), M(nullptr) {}

    Matrix(int rows, int cols) : m(rows), n(cols) //матрица m*n
    {
        M = new T * [m];
        for (int i = 0; i < m; i++)
        {
            M[i] = new T[n];
            for (int j = 0; j < n; j++)
            {
                M[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) : m(other.m), n(other.n) //конструктор копирования 
    {
        M = new T * [m];
        for (int i = 0; i < m; i++)
        {
            M[i] = new T[n];
            for (int j = 0; j < n; j++)
            {
                M[i][j] = other.M[i][j];
            }
        }
    }

    void SetM(int row, int col, T value) //устанавливает значение элемента по заданным индексам строки и столбца
    {
        if (row >= 0 && row < m && col >= 0 && col < n)
            M[row][col] = value;
        else
            cerr << "Error: Index out of bounds." << endl;
    }

    T GetM(int row, int col) const //возвращает значение элемента по указанным индексам
    {
        if (row >= 0 && row < m && col >= 0 && col < n)
            return M[row][col];
        else
        {
            cerr << "Error: Index out of bounds." << endl;
            return T();
        }
    }

    void Print(const char* label) const
    {
        cout << label << ":" << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(5) << M[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix& operator=(const Matrix& other) //оператор копирования
    {
        if (this == &other) return *this;

        for (int i = 0; i < m; i++)
        {
            delete[] M[i];
        }
        delete[] M;

        m = other.m;
        n = other.n;

        M = new T * [m];
        for (int i = 0; i < m; i++)
        {
            M[i] = new T[n];
            for (int j = 0; j < n; j++)
            {
                M[i][j] = other.M[i][j];
            }
        }
        return *this;
    }

    ~Matrix()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] M[i];
        }
        delete[] M;
    }
};

int main()
{
    Matrix <double> M(3, 4);
    M.Print("M");
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
			M.SetM(i, j, (i + j) * 0.5);
        }
    }
    M.Print("M");

    Matrix <double> M1 = M;
	M1.Print("M1");

    Matrix <double> M2;
    M2 = M;
	M2.Print("M2");

    Matrix <double> M3;
	M3 = M2 = M1 = M;
	M3.Print("M3");
    return 0;
}