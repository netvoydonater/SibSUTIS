#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] < 0)
        {
            i++;
        }
        else if (arr[j] >= 0)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
int main() {
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 101 - 50;
    }
    Sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\t';
    }

    return 0;
}