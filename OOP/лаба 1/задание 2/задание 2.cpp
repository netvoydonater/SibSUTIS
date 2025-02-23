#include <iostream>
#include <cstdlib>
#include <ctime>
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


int** genRandMatrix(int size, int maxValue)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		int rowSize = rand() % 10 + 1;
		if (rowSize == 0) rowSize = rand() % 10 + 1;
		matrix[i] = genRandArray(rowSize, maxValue);
	}
	return matrix;
}

void printMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		print(matrix[i]);
	}
}

void cleanMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int size = rand() % 10;
	int maxValue = 100;
	int** matrix = genRandMatrix(size, maxValue);
	printMatrix(matrix, size);
	cleanMatrix(matrix, size);
}