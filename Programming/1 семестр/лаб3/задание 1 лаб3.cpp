//1. Вводится число М - номер месяца. Определить номер квартала и время года по введенному номеру месяца.
#include <stdio.h>

int main()
{
	int mouth;
	printf("Vvedite nomer mesyatsa: ");
	scanf_s("%d", &mouth);
	switch (mouth)
	{
	case 1:
		printf("Quarter: 1\n");
		printf("Season: Winter\n");
		break;
	case 2:
		printf("Quarter: 1\n");
		printf("Season: Winter\n");
		break;
	case 3:
		printf("Quarter: 1\n");
		printf("Season: Spring\n");
		break;
	case 4:
		printf("Quarter: 2\n");
		printf("Season: Spring\n");
		break;
	case 5:
		printf("Quarter: 2\n");
		printf("Season: Spring\n");
		break;
	case 6:
		printf("Quarter: 2\n");
		printf("Season: Summer\n");
		break;
	case 7:
		printf("Quarter: 3\n");
		printf("Season: Summer\n");
		break;
	case 8:
		printf("Quarter: 3\n");
		printf("Season: Summer\n");
		break;
	case 9:
		printf("Quarter: 3\n");
		printf("Season: Autumn\n");
		break;
	case 10:
		printf("Quarter: 4\n");
		printf("Season: Autumn\n");
		break;
	case 11:
		printf("Quarter: 4\n");
		printf("Season: Autumn\n");
		break;
	case 12:
		printf("Quarter: 4\n");
		printf("Season: Winter\n");
		break;
	default:
		printf("Error!");
	}

	return 0;
}