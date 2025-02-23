#include <iostream>

using namespace std;


int main()
{	
	int n;
	cin >> n;
	int* Array = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		Array[i] = i;
	}
	for (int p = 2; p < n + 1; p++)
	{
		if (Array[p] != 0)
		{
			cout << Array[p] << " ";
			for (int j = p * p; j < n + 1; j += p)
			{
				Array[j] = 0;
			}
		}
	}
}




