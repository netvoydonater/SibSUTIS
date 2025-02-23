#include <iostream>	
#include <algorithm>

using namespace std;

struct School   //Создание структуры
{
	int Number;  //Номер школы
	int Graduates; //Кол-во выпускников
	int UniversityStudents; //Кол-во студентов поступивших в вуз
};


bool ComparisonStudets(const School& SchoolFirst, const School& SchoolSecond) //В параметры передается две школы , функция для параметра в Sort
{
	int FirstPercent = static_cast<double>(SchoolFirst.UniversityStudents) / (SchoolFirst.Graduates) * 100;  //Создается первый процент постувших путем деления числа студентов на число окончивших школу (static_cast<double> переводит число в double)
	int SecondPercent = static_cast<double>(SchoolSecond.UniversityStudents) / (SchoolSecond.Graduates) * 100; //Таким же путем создается и второй процент поступивших для второй школы
	return FirstPercent > SecondPercent;  //Возвращается больший процент поступивших
}

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
	cout << "Enter number of schools: ";
	int n; cin >> n;

	School* schools = new School[n];   //Создание динамического массива из структур
	cout << "Enter school information " << endl;
	for (int i = 0; i < n; i++)   //Заполнения массива записями о каждой структуре 
	{
		cout << "School Number: "; 
		cin >> schools[i].Number;   //Заполнение номера школы i структуры          
		cout << "Number of graduates: "; 
		cin >> schools[i].Graduates;//Заполнение кол-ва выпускников i структуры 
		cout << "Number of students admitted to the university: "; 
		cin >> schools[i].UniversityStudents; //Заполнение студентов поступивших в ВУЗ i структуры 
		if (schools[i].UniversityStudents > schools[i].Number)  //Проверка на неверно введеные записи 
		{
			cout << "Wrong data!";
			return -1;
		}
	}
	sort(schools, schools + n, ComparisonStudets);  //Сортировка массива структур путем встроенной сортировки библиотеки <algorithm> , в качестве как сортировать используем функцию ComparisonStudets
	for (int i = 0; i < n; i++)
	{
		int Percent = static_cast<double> (schools[i].UniversityStudents) / (schools[i].Graduates) * 100;  //Вывод данных о школах 
		cout << "The school number: " << schools[i].Number << " Graduates: " << schools[i].Graduates << " and percentage of admissions: " << Percent << "%" << endl;
	}
}