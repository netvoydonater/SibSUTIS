//2. Вводится  целое число С. Если -9<=c<=9 вывести величину числа в словесной форме с учетом знака, в противном случае - предупреждающее сообщение и повторный ввод.
#include <stdio.h>
#include <math.h>

int main()
{
	int chislo;
	printf("Vvedite chislo: ");
	scanf_s("%d", &chislo);

	int c = chislo;
	if (-9 <= c && c <= 9);

	switch (c)
	{
	case 0:
		printf("Chislo: Null\n");
		break;
	case 1:
		printf("Chislo: Odin\n");
		break;
	case 2:
		printf("Chislo: Dva\n");
		break;
	case 3:
		printf("Chislo: Tri\n");
		break;
	case 4:
		printf("Chislo: Chetyre\n");
		break;
	case 5:
		printf("Chislo: Pyat\n");
		break;
	case 6:
		printf("Chislo: Shest\n");
		break;
	case 7:
		printf("Chislo: Sem\n");
		break;
	case 8:
		printf("Chislo: Vosem\n");
		break;
	case 9:
		printf("Chislo: Devyat\n");
		break;
	case -1:
		printf("Chislo: Minus odin\n");
		break;
	case -2:
		printf("Chislo: Minus dva\n");
		break;
	case -3:
		printf("Chislo: Minus tri\n");
		break;
	case -4:
		printf("Chislo: Minus chetyre\n");
		break;
	case -5:
		printf("Chislo: Minus pyat\n");
		break;
	case -6:
		printf("Chislo: Minus shest\n");
		break;
	case -7:
		printf("Chislo: Minus sem\n");
		break;
	case -8:
		printf("Chislo: Minus vosem\n");
		break;
	case -9:
		printf("Chislo: Minus devyat\n");
		break;
	case 20:
		prinf("Huinya")
	default:
		printf("Error!");
	}
	return 0;
}