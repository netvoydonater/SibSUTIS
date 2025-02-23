#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

struct Vertex
{
    int Data = 0;
    Vertex* Left = nullptr;
    Vertex* Right = nullptr;
};

struct WeightArray
{
    int Data;
    int Weight;
};


void LeftRight(Vertex* p)
{
    if (p != nullptr)
    {
        LeftRight(p->Left);
        cout << p->Data << " ";
        LeftRight(p->Right);
    }
}

void BubbleSort(WeightArray* A, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j].Data > A[j + 1].Data)
                swap(A[j], A[j + 1]);
        }
}

void RandomSearchTree(int D, Vertex*& Root)
{
    Vertex** p = &Root;
    while (*p != nullptr)
    {
        if (D < (*p)->Data)
            p = &((*p)->Left);
        else if (D > (*p)->Data)
            p = &((*p)->Right);
        else
            return;
    }
    if ((*p) == nullptr)
    {
        (*p) = new Vertex;
        (*p)->Data = D;
        (*p)->Right = nullptr;
        (*p)->Left = nullptr;
    }
}

void CreateMatrix(int**& AW, int**& AP, int**& AR, int Size)
{
    AW = new int* [Size];
    AP = new int* [Size];
    AR = new int* [Size];
    for (int i = 0; i < Size; ++i)
    {
        AW[i] = new int[Size];
        AP[i] = new int[Size];
        AR[i] = new int[Size];
    }
    for (int i = 0; i < Size; ++i)
    {
        for (int j = 0; j < Size; ++j)
        {
            AW[i][j] = 0;
            AP[i][j] = 0;
            AR[i][j] = 0;
        }
    }
}

void FillAW(int N, WeightArray* W, int**& AW)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            AW[i][j] = AW[i][j - 1] + W[j - 1].Weight;
        }
    }
}

void Fill_AP_and_AR(int N, int**& AW, int**& AP, int**& AR)
{
    for (int i = 0; i < N; ++i)
    {
        int j = i + 1;
        AP[i][j] = AW[i][j];
        AR[i][j] = j;
    }
    for (int h = 2; h <= N; ++h)
    {
        for (int i = 0; i < N - h; ++i)
        {
            int j = i + h;
            int m = AR[i][j - 1];
            int min = AP[i][m - 1] + AP[m][j];
            for (int k = m + 1; k <= AR[i + 1][j]; ++k)
            {
                int x = AP[i][k - 1] + AP[k][j];
                if (x < min)
                {
                    m = k;
                    min = x;
                }
            }
            AP[i][j] = min + AW[i][j];
            AR[i][j] = m;
        }
    }
}

void CreateTree(int L, int R, int** AR, Vertex*& Root, WeightArray A[])
{
    if (L < R)
    {
        int k = AR[L][R];
        RandomSearchTree(A[k - 1].Data, Root);
        CreateTree(L, k - 1, AR, Root, A);
        CreateTree(k, R, AR, Root, A);
    }
}

int Level(int X, Vertex*& p)
{
    if (p == nullptr)
        return 0; 

    if (X < p->Data)
        return 1 + Level(X, p->Left);
    else if (X > p->Data)
        return 1 + Level(X, p->Right);
    else
        return 1; 
}

void MiddleTree(WeightArray* Matrix, int N, Vertex*& p)
{
    int W = 0, S = 0;
    for (int i = 0; i < N; i++)
        W += Matrix[i].Weight;
    for (int i = 0; i < N; i++)
        S += Matrix[i].Weight * Level(Matrix[i].Data, p);
    cout << fixed << setprecision(3) << (float)S / (float)W << endl;
}

void PrintMatrix(int**& T, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << setw(3) << T[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
    srand(time(nullptr));
    int Size = 10;
    WeightArray Matrix[100];
    int** AW = nullptr, ** AP = nullptr, ** AR = nullptr;
    Vertex* Tree = nullptr;

    for (int i = 0; i < Size; ++i)
    {
        Matrix[i].Data = i + 1;
        Matrix[i].Weight = rand() % 100 + 1;
    }

    BubbleSort(Matrix, Size);

    CreateMatrix(AW, AP, AR, Size);
    FillAW(Size, Matrix, AW);
    Fill_AP_and_AR(Size, AW, AP, AR);

    cout << "Матрица AW:" << endl;
    PrintMatrix(AW, Size);

    cout << "Матрица AP:" << endl;
    PrintMatrix(AP, Size);

    cout << "Матрица AR:" << endl;
    PrintMatrix(AR, Size);

    CreateTree(0, Size - 1, AR, Tree, Matrix);

    cout << "Обход слева направо (ДОП): ";
    LeftRight(Tree);
    cout << endl;

    cout << "Средневзвешенная высота ДОП: ";
    MiddleTree(Matrix, Size, Tree);

    cout << "AP[0][n] / AW[0][n]: " << (float)AP[0][Size - 1] / (float)AW[0][Size - 1] << endl;

    return 0;
}
