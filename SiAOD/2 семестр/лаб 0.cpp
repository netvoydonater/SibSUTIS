#include <stdio.h>
#include <stdlib.h>
int A[10];
void PrintMas()
{
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", A[i]);
	}
}
void FillInc()
{
	for (int i = 0; i < 10; i++)
	{
		A[i] = i;
	}
}
void FillDec()
{
	for (int i = 9; i >= 0; i--)
	{
		A[i] = i;
	}
}
void FillRand()
{
	for (int i = 0; i < 10; i++)
	{
		A[i] = rand() % 10;
	}
}
int CheckSum()
{
	int d = 0;
	for (int i = 0; i < 10; i++)
	{
		d += A[i];
	}
	return d;

}
int RunNumber()
{
	int Number;
	int j = 1;
	for (int i = 0; i < 9; i++)
	{
		if (A[i] >= A[i + 1])
		{
			j++;
		}
	}
	return printf("%d", j);
}
int main()
{
	FillInc();
	PrintMas();
	printf(" ");
	printf("%d ", RunNumber());
	printf("%d\n", CheckSum());

	FillDec();
	PrintMas();
	printf(" ");
	printf("%d ", RunNumber());
	printf("%d\n", CheckSum());

	FillRand();
	PrintMas();
	printf(" ");
	printf("%d ", RunNumber());
	printf("%d\n", CheckSum());

	return 0;
}