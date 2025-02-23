//2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 5;
int main()
{
	float arr[5][5];
	int a = -10, b = 10;
		for (int i = 0; i < N ; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = (float)rand() * (b - a) / RAND_MAX + a;
			}
		}

		printf("Arrive: \n");

		for (int i = 0; i < N; i++)
		{
			printf("\n");
			for (int j = 0; j < N; j++)
			{
				printf("%6.2f", arr[i][j]);
			}
		}
		for (int i = 0; i < N; i++)
		{
			float summa = 0;
			for (int j = 0; j < N; j++)
			{
				summa += arr[i][j];
			}
			for (int j = 0; j < N; j++)
			{
				arr[i][j] /= summa;
			}
		}
		printf("\n\nChanging massiv: \n");

		for (int i = 0; i < N; i++)
		{
			printf("\n");
			for (int j = 0; j < N; j++)
			{
				printf("%6.2f", arr[i][j]);
			}
		}


	return 0;
}