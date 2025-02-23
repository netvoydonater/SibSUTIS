//1.	Вывести  список слов, имеющих приставку (несколько букв), задаваемую с клавиатуры.
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
	int j = 0, size = 0, size_consolt = 0, l;
	char offers[256], consolt[256];
	char* offer;
	printf("Enter text: ");
	offer = gets_s(offers);
	printf("Enter prefix: ");
	gets_s(consolt);
	while (consolt[size_consolt] != '\0')
		size_consolt++;
	while (offer[j] != '\0')
		j++;
	offer[j] = ',';
	while (size < j)
	{
		int k = 0, count = size;
		char word[256] = "", word1[256] = "";
		while (offer[count] != ',')
		{
			word1[k] = offer[count];
			count++;
			k++;
		}
		while (offer[size] != ',')
			size++;
		if (strncmp(word1, consolt, size_consolt) == 0)
			printf("%s", word1);
		printf("\n");
		size += 2;
	}
	return 0;
}