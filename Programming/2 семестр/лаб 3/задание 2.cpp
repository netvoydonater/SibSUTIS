#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

double random(double min, double max) //Заполнение рандомными вещественными числами на отрезке 
{
	return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / (max - min));
}

void printArray(float* arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	srand(time(0));
	int n;
	cin >> n;
	float* a = new float[n];
	float** b = new float* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = random(-100.0, 100.0);
		b[i] = &a[i];
	}
	printArray(a, n);
	sort(b, b + n, [](float* x, float* y) { return *x < *y; });//Сортировка по возрастанию с библиотекой <algorithm>
	for (int i = 0; i < n; i++)
	{
		cout << *b[i] << " ";
	}
	delete[] a;
	delete[] b;
}




