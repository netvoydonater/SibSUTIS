#include <iostream>
#include <vector>
#include <locale>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");
    int rows;
    cout << "Введите количество строк: ";
    cin >> rows;

    // Создаем двумерный динамический массив (вектор векторов)
    vector<vector<int>> matrix(rows);

    for (int i = 0; i < rows; i++) 
    {
        int elementsInRow;
        cout << "Введите количество элементов в строке " << i + 1 << ": ";
        cin >> elementsInRow;

        // Выделяем место для элементов в строке
        matrix[i].resize(elementsInRow);

        cout << "Введите элементы строки " << i + 1 << ": ";
        for (int j = 0; j < elementsInRow; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    // Выводим массив построчно
    cout << "\nВаш массив:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < matrix[i].size(); j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
