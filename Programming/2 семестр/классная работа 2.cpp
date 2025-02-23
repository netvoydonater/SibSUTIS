#include <stdio.h>
void swap(int* v1, int* v2)  //у - адрес переменной
{
	int temp = *v1;    //*у - значение той переменной
	*v1 = *v2;
	*v2 = temp;
}
int main()
{
	int a = 5;
	int b = 100;
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}