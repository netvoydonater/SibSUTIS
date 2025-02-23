#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

int Rand(int x, int y)
{
    if (x > 0) return x + rand() % (y - x);
    else return x + rand() % (abs(x) + y);
}

void PrintSum(int** A, int size)
{
    for (int i = 0; i < size; i++)
    {
        int n = A[i][0];
        int Sum = 0;
        for (int j = 0; j < n; j++)
        {
            Sum += A[i][j];
        }
        cout << "Summa elements " << i + 1 << " row " << ": " << Sum << endl;
    }
}

int main() 
{
    srand(time(NULL));
    int** A = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        int n = Rand(2, 11);
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 11;
            A[i][0] = n;
            cout << A[i][j] << '\t';
        }
        cout << endl;
    }

    PrintSum(A, 5);

    for (int i = 0; i < 5; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
