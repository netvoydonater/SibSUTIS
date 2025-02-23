#include <iostream>
#include <string> //тип данных
#include <algorithm> //для ревёрса

using namespace std;

string BinaryNumber(int n)
{
	string Result = "";
	if (n == 0) return "0";
	while (n > 0)
	{
		int m = n % 2;
		Result += to_string(m);
		n /= 2;
	}
	reverse(Result.begin(), Result.end());
	return Result;
}
int main()
{
	int n;
	cin >> n;
	cout << BinaryNumber(n);
}
