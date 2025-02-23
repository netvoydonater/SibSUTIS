#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int* genRandArray(int size, int maxValue)
{
	int* array = new int[size + 1];
	array[0] = size;
	for (int i = 1; i <= size; ++i)
	{
		array[i] = rand() % (maxValue + 1);
	}
	return array;
}

void print(int* arr)
{
	int size = arr[0];
	cout << size << ":";
	for (int i = 1; i <= size; ++i)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}
int main()
{
	srand(static_cast<unsigned int>(time(0))); //перевод интовых значений, чтобы вс не ругался
	int size = rand() % 10;
	int maxValue = 100;
	int* arr = genRandArray(size, maxValue);
	print(arr);
	delete[] arr;
	return 0;
}+++++++++++++