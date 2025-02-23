//3. В китайском гороскопе года носят следующие названия: крыса, корова, тигр, заяц, дракон, змея,  лошадь, овца, обезьяна, петух, собака, свинья. Учитывая, что 2008 – год крысы, написать программу, определяющую название года по его номеру.
#include <stdio.h>
#include <math.h>
int main()
{
	int year;
	printf("Enter the number year: \n");
	scanf_s("%d", &year);

	int y = (year - 2008) % 12;
	if (y < 0) y += 12;

	switch (y)
	{
	case 0:
		printf("Year of rat\n", year);
		break;
	case 1:
		printf("Year of cow\n", year);
		break;
	case 2:
		printf("Year of tiger\n", year);
		break;
	case 3:
		printf("Year of rabbit\n", year);
		break;
	case 4:
		printf("Year of dragon\n", year);
		break;
	case 5:
		printf("Year of snake\n", year);
		break;
	case 6:
		printf("Year of horse\n", year);
		break;
	case 7:
		printf("Year of sheep\n", year);
		break;
	case 8:
		printf("Year of monkey\n", year);
		break;
	case 9:
		printf("Year of rooster\n", year);
		break;
	case 10:
		printf("Year of dog\n", year);
		break;
	case 11:
		printf("Year of pig\n", year);
		break;
	default:
		printf("Error!");
	}

	return 0;
}
