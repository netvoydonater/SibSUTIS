#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *m = (int *) malloc(29 * sizeof(int)); //вторичка
	//int *m = (int *) calloc(29, sizeof(int)); новостройка
	if (m == NULL)
	{
		printf("ERROR!");
		return -1;
	}

	free(m); //очистка памяти от массива
	return 0;
}