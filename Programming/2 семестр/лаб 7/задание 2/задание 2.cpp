#include <iostream>
#include <locale>
#include <ctime>
using namespace std;

int Rand(int x, int y)
{
    if (x > 0) return x + rand() % (x - y);
    else return x + rand() % (abs(x) + y);
}
void NullMassiv(int* A, int size)
{
    int IndexFirstMin = 0;
    int IndexSecondMin = 0;
    int FirstMin = INT_MAX;
    int SecondMin = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (A[i] < FirstMin)
        {
            SecondMin = FirstMin;
            IndexSecondMin = IndexFirstMin;
            FirstMin = A[i];
            IndexFirstMin = i + 1;
        }
        else if (A[i] < SecondMin)
        {
            SecondMin = A[i];
            IndexSecondMin = i + 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i > IndexFirstMin - 1 && i < IndexSecondMin - 1 || i > IndexSecondMin - 1 && i < IndexFirstMin - 1)
        {
            A[i] = 0;
        }
    }
    cout << FirstMin << " " << IndexFirstMin << '\t' << SecondMin << " " << IndexSecondMin << endl;
}
int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    int* Massiv = new int[n];
    for (int i = 0; i < n; i++)
    {
        Massiv[i] = Rand(-100, 100);
        cout << Massiv[i] << '\t';
    }
    cout << endl;

    NullMassiv(Massiv, n);

    for (int i = 0; i < n; i++)
    {
        cout << Massiv[i] << '\t';
    }
    return 0;
}
