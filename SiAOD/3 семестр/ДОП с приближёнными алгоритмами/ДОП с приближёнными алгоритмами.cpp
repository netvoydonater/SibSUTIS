#include <iostream>
#include <iomanip>

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

void QuickSortV2(int A[], int left, int right)
{
    int x = A[(left + right)] / 2, i = left, j = right;
    while (left < right)
    {
        while (A[i] < x)
        {
            i++;
        }
        while (A[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (j - left < right - i)
    {
        QuickSortV2(A, left, j);
        left = i;
    }
    else if (j - right > right - i)
    {
        QuickSortV2(A, i, right);
        right = j;
    }
}
void BubbleSortW(WeightArray* A, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j].Weight < A[j + 1].Weight)
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

void A1(WeightArray* W, Vertex*& Root, int Size)
{
    BubbleSortW(W, Size);
    for (int i = 0; i < Size; ++i)
    {
        RandomSearchTree(W[i].Data, Root);
    }
}

void A2(int L, int R, WeightArray* W, Vertex*& Root)
{
    int Wes = 0, Sum = 0, i;
    if (L <= R)
    {
        for (i = L; i <= R; ++i)
        {
            Wes += W[i].Weight;
        }
        for (i = L; i < R; ++i)
        {
            if (Sum <= (Wes / 2) and (Sum + W[i].Weight) >= (Wes / 2))
                break;
            Sum += W[i].Weight;
        }
        RandomSearchTree(W[i].Data, Root);
        A2(L, i - 1, W, Root);
        A2(i + 1, R, W, Root);
    }
}
int HeightLevel(Vertex* p, int D)
{
    if (D < p->Data)
        return 1 + HeightLevel(p->Left, D);
    if (D > p->Data)
        return 1 + HeightLevel(p->Right, D);
    return 1;
}
int Level(int X, Vertex*& p)
{
    if (X < p->Data)
        return 1 + Level(X, p->Left);
    else if (X > p->Data)
        return 1 + Level(X, p->Right);
    else
        return 1;
}
void MiddleTree(WeightArray* Matrix, int N, Vertex*& p) //средняя высота
{
    int W = 0, S = 0;
    for (int i = 0; i < N - 1; i++)
        W += Matrix[i].Weight;
    for (int i = 0; i < N - 1; i++)
        S += Matrix[i].Weight * Level(Matrix[i].Data, p);
    cout << fixed << setprecision(3) << (float)S / (float)W << " ";
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

void PrintTable(int Size, WeightArray* Matrix, Vertex*& Tree)
{
    cout << "| Num |  Data | Weight | Level |"
        "\n|-----|-------|--------|-------|"
        << endl;
    for (int i = 0; i < Size - 1; ++i)
    {
        cout << "|" << setw(4) << i + 1 << " | " << setw(5) << Matrix[i].Data
            << " | " << setw(5) << Matrix[i].Weight
            << "  |  " << setw(3) << Level(Matrix[i].Data, Tree) << "  |" << endl;
    }
}

int main()
{
    srand(time(nullptr));
    Vertex* Tree = nullptr;
    Vertex* Root = nullptr;
    Vertex* Roots = nullptr;
    int Size = 11;
    WeightArray Matrix[10], Matrix1[10], Matrix2[10];
    int** AW = nullptr;
    int** AP = nullptr;
    int** AR = nullptr;

    for (int i = 0; i < Size - 1; ++i)
    {
        Matrix[i].Data = rand() % (Size * 10) + 1;
        Matrix[i].Weight = rand() % (Size * 2) + 1;
        for (int j = 0; j < i; ++j)
        {
            if (Matrix[i].Data == Matrix[j].Data or Matrix[i].Weight == Matrix[j].Weight)
                i--;
        }
    }

    for (int i = 0; i < Size - 1; ++i)
    {
        Matrix1[i] = Matrix2[i] = Matrix[i];
    }

    BubbleSort(Matrix, Size - 1);
    BubbleSort(Matrix2, Size - 1);

    CreateMatrix(AW, AP, AR, Size);
    FillAW(Size, Matrix, AW);
    Fill_AP_and_AR(Size, AW, AP, AR);
    cout << "AW" << endl
        << "---------------------" << endl;
    PrintMatrix(AW, Size);
    cout << "AP" << endl
        << "---------------------" << endl;
    PrintMatrix(AP, Size);
    cout << "AR" << endl
        << "---------------------" << endl;
    PrintMatrix(AR, Size);

    CreateTree(0, Size - 1, AR, Tree, Matrix);
    cout << "Left Right DOP: ";
    LeftRight(Tree);
    cout << endl;
    A1(Matrix1, Root, Size - 1);
    cout << "Left Right A1: ";
    LeftRight(Root);

    cout << endl;
    A2(0, Size - 2, Matrix2, Roots);
    cout << "Left Right A2: ";
    LeftRight(Roots);
    cout << endl;

    cout << "Middle Tree DOP: ";
    MiddleTree(Matrix, Size, Tree);
    cout << endl
        << "Middle Tree A1: ";
    MiddleTree(Matrix1, Size, Root);
    cout << endl
        << "Middle Tree A2: ";
    MiddleTree(Matrix2, Size, Roots);

    cout << endl
        << setprecision(3) << (float)AP[0][Size - 1] / (float)AW[0][Size - 1] << " ";
    cout << endl;

    PrintTable(Size, Matrix, Root);
}