#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;
void Matrix(vector<vector<int>>& matrix, int N) 
{
    srand(time(0));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Переписать элементы по правым диагоналям
vector<int> byRightDiagonals(const vector<vector<int>>& matrix, int N)
{
    vector<int> result;
    for (int diag = 0; diag < 2 * N - 1; diag++) 
    {
        for (int i = 0; i < N; i++) 
        {
            int j = diag - i;
            if (j >= 0 && j < N)
            {
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}

// Переписать элементы по левым диагоналям
vector<int> byLeftDiagonals(const vector<vector<int>>& matrix, int N)
{
    vector<int> result;
    for (int diag = 0; diag < 2 * N - 1; diag++)
    {
        for (int i = 0; i < N; i++)
        {
            int j = diag - (N - 1 - i);
            if (j >= 0 && j < N) 
            {
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}

// Переписать элементы по спирали, начиная с центрального элемента
vector<int> spiralFromCenter(const vector<vector<int>>& matrix, int N)
{
    vector<int> result;
    int x = 0, y = 0;
    int step = 1;
    if (N % 2 == 0)
    {
        //result.push_back(matrix[x + 2][y + 2]);
        x = N / 2;
        y = N / 2;
        result.push_back(matrix[x][y]);
        while (step < N)
        {
            for (int i = 0; i < step; i++) result.push_back(matrix[x][++y]);
            for (int i = 0; i < step; i++) result.push_back(matrix[--x][y]);
            step++;
            for (int i = 0; i < step; i++) result.push_back(matrix[x][--y]);
            for (int i = 0; i < step; i++) result.push_back(matrix[++x][y]);
            step++;
        }
        return result;
    }
    else
    {
        x = N / 2;
        y = N / 2;
        result.push_back(matrix[x][y]);
        while (step < N)
        {
            for (int i = 0; i < step; i++) result.push_back(matrix[x][++y]);
            for (int i = 0; i < step; i++) result.push_back(matrix[--x][y]);
            step++;
            for (int i = 0; i < step; i++) result.push_back(matrix[x][--y]);
            for (int i = 0; i < step; i++) result.push_back(matrix[++x][y]);
            step++;
        }
        return result;
    }

}

// Переписать элементы по спирали, начиная с левого верхнего угла
vector<int> spiralFromTopLeft(const vector<vector<int>>& matrix, int N) 
{
    vector<int> result;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) 
    {
        for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) 
        {
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (const auto& elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}
int main()
{
	setlocale(LC_ALL, "ru"); 
    int N;
    cout << "Введите размер матрицы: ";
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    Matrix(matrix, N);

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    vector<int> D1 = byRightDiagonals(matrix, N);
    cout << "\nПо правым диагоналям: ";
    for (int num : D1) cout << num << " ";
    cout << endl;

    vector<int> D2 = byLeftDiagonals(matrix, N);
    cout << "\nПо левым диагоналям: ";
    for (int num : D2) cout << num << " ";
    cout << endl;

    vector<int> D3 = spiralFromCenter(matrix, N);
    cout << "\nПо спирали от центра: ";
    for (int num : D3) cout << num << " ";
    cout << endl;

    vector<int> D4 = spiralFromTopLeft(matrix, N);
    cout << "\nПо спирали от левого верхнего угла: ";
    for (int num : D4) cout << num << " ";
    cout << endl;

    return 0;
}
