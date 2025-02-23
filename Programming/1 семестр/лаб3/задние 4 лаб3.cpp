//4. Вводится номер  месяца М и дня  D. Определить  порядковый номер дня в году Т, соответствующий этой дате.
#include <stdio.h>


int main()
{
	int M, D;
	int Day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("Enter mouth: ");
	scanf_s("%d", &M);
	while (M > 12 || M <= 0)
	{
		printf("This mouth not exist, repeat attend: ");
		scanf_s("%d", &M);
	}
	printf("Enter day: ");
	scanf_s("%d", &D);
	while (D > Day[M - 1] || D <= 0)
	{
		printf("This day not exist in this mouth, repeat attend: ");
		scanf_s("%d", &D);
	}
	int num = 0;
	switch (M)
	{
	case 1:
		num += Day[1];
		break;
	case 2:
		for (int i = 0; i < 1; i++)
		{
			num += Day[i];
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
		{
			num += Day[i];
		}
		break;
	case 4:
		for (int i = 0; i < 3; i++)
		{
			num += Day[i];
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++)
		{
			num += Day[i];
		}
		break;
	case 6:
		for (int i = 0; i < 5; i++)
		{
			num += Day[i];
		}
		break;
	case 7:
		for (int i = 0; i < 6; i++)
		{
			num += Day[i];
		}
		break;
	case 8:
		for (int i = 0; i < 7; i++)
		{
			num += Day[i];
		}
		break;
	case 9:
		for (int i = 0; i < 8; i++)
		{
			num += Day[i];
		}
		break;
	case 10:
		for (int i = 0; i < 9; i++)
		{
			num += Day[i];
		}
		break;
	case 11:
		for (int i = 0; i < 10; i++)
		{
			num += Day[i];
		}
		break;
	case 12:
		for (int i = 0; i < 11; i++)
		{
			num += Day[i];
		}
		break;
	default:
		break;
	}
	num += D;
	printf("Sequence number: %d", num);
}