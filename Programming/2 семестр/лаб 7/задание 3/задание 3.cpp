#include <iostream>
#include <locale>
#include <ctime>
using namespace std;

int Rand(int x, int y)
{
    if (x > 0) return x + rand() % (y - x);
    else return x + rand() % (abs(x) + y);
}
void Sort(int* A, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (A[j] < A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int BinarySearch(int* A, int size, int target)
{
    int comparisons = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;

        if (A[mid] == target)
        {
            return comparisons;
        }

        if (A[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return comparisons;
}


int LinearSearch(int* A, int size, int target)
{
    int comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        comparisons++;
        if (A[i] == target)
        {
            return comparisons;
        }
    }

    return -1;
}




int main()
{
    srand(time(NULL));
    int n; cin >> n;
    int* Massiv = new int[n];

    for (int i = 0; i < n; i++)
    {
        Massiv[i] = Rand(-100, 100);
        cout << Massiv[i] << '\t';
    }
    Sort(Massiv, n);
    cout << endl << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << Massiv[i] << '\t';
    }
    cout << endl;

    int target; cin >> target;

    cout << "Comparisons for binary search : " << BinarySearch(Massiv, n, target) << endl;
    cout << "Comparisons for linear search: " << LinearSearch(Massiv, n, target) << endl;
    return 0;
}







