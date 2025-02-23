#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int n , m = 0, k = 0;
	cin >> n;
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = rand() % 101 - 50;
		cout << b[i] << '\t';
		if (b[i] > 0)
		{
			c[m] = b[i];
			m++;
		}
		if (b[i] < 0)
		{
			d[k] = b[i];
			k++;
		}
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << c[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << d[i] << '\t';
	}
	return 0;
}