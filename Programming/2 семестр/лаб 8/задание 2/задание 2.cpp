#include <iostream>	
#include <algorithm>

using namespace std;

struct Room
{
	int Number;  //Номер комнаты 
	int Quantity;  //Кол-во проживающих
	double Square;  //Площадь комнаты 
	string Faculty;  //Название факультета
};

bool Words(string* A, int size, string& words) //Функция для переноса из массива слов которые не повторяются
{
	for (int i = 0; i < size; i++)
	{
		if (A[i] == words) return 0;
	}
	return 1;
}
int main(void)
{
	cout << "Enter the number of rooms: ";       //Вводим кол-во комнат
	int k; cin >> k;
	Room* rooms = new Room[k];       //Создаем динамический массив из структур Room
	cout << "Enter room details " << endl;
	for (int i = 0; i < k; i++)
	{
		cout << "Room number: "; 
		cin >> rooms[i].Number;
		cout << "Number of residents: "; 
		cin >> rooms[i].Quantity;
		cout << "Room area: "; 
		cin >> rooms[i].Square;
		cout << "Faculty: "; 
		cin >> rooms[i].Faculty;                 //Заполнем данные каждой структуры
	}
	string* Faculties = new string[k];           //Создаем массив для факультетов которые не повторяются
	int countFaculties = 0;       //Переменная для подсчета факультетов
	for (int i = 0; i < k; i++)
	{
		if (Words(Faculties, countFaculties, rooms[i].Faculty))          //Переносим из структуры те факультеты которые не повторяются
		{
			Faculties[countFaculties] = rooms[i].Faculty;
			countFaculties++;                  //Увеличиваем число факультетов
		}
	}

	cout << endl << endl;

	for (int i = 0; i < countFaculties; i++)        //Перебираем все факультеты
	{
		int countRooms = 0;
		int countQuantity = 0;           //Переменные для подчета комнат, проживающих, и площади
		double countSquare = 0.0;

		for (int j = 0; j < k; j++)           //Перебираем все факультеты в структурах
		{
			if (rooms[j].Faculty == Faculties[i])        //Если факультеты структуры совпадает с факультетом из массива не повторяющиеся факульетот
			{
				countRooms++;         //Кол-во комнат увеличиваем
				countQuantity += rooms[j].Quantity;        //Складываем общее кол-во проживающих
				countSquare += rooms[j].Square;       //Складываем общую площадь
			}
		}

		double AverageSquare = countSquare / countQuantity;   //Считаем среднюю площадь на одного проживающего

		cout << "At the Faculty: " << Faculties[i] << endl;
		cout << "Number of rooms: " << countRooms << endl;               //Вывод всех данных
		cout << "Number of students: " << countQuantity << endl;
		cout << "Average area per student: " << AverageSquare << endl;
	}
}