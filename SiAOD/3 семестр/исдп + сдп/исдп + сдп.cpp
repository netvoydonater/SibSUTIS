#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale>

using namespace std;

struct Vertex
{
    int Data;
    Vertex* Right;
    Vertex* Left;
};

void FillInc(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
}

void FillDec(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
}

void FillRand(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }
}

Vertex* ISDP(int A[], int L, int R)
{
    Vertex* p;
    int m = 0;
	if (L > R) return NULL;
    else
    {
        m = (L + R) / 2;
        p = new Vertex;
        p->Data = A[m];
        p->Left = ISDP(A, L, m - 1);
        p->Right = ISDP(A, m + 1, R);
        return p;
    }
}

void DoubleCosSDP(Vertex*& Root, int data)
{
    Vertex** p = &Root;
    while (*p != NULL)
    {
        if (data < (*p)->Data) p = &((*p)->Left);
        else if (data > (*p)->Data) p = &((*p)->Right);
        else break;
    }
    if (*p == NULL)
    {
        *p = new Vertex;
        (*p)->Data = data;
        (*p)->Left = NULL;
        (*p)->Right = NULL;
    }
}

void RecSDP(Vertex*& Root, int data)
{
    if (Root == NULL)
    {
        Root = new Vertex;
        Root->Data = data;
        Root->Left = NULL;
        Root->Right = NULL;
    }
    else if (data < Root->Data) RecSDP(Root->Left, data);
    else if (data > Root->Data) RecSDP(Root->Right, data);
}

void TreeRight(Vertex* Root)
{
    if (Root != NULL)
    {
        TreeRight(Root->Left);
        cout << " " << Root->Data;
        TreeRight(Root->Right);
    }
}

int CalculateTreeSize(Vertex* Root)
{
    if (Root == NULL) return 0;
    else return 1 + CalculateTreeSize(Root->Left) + CalculateTreeSize(Root->Right);
}

int CalculateTreeSum(Vertex* Root)
{
	if (Root == NULL) return 0;
    else return Root->Data + CalculateTreeSum(Root->Left) + CalculateTreeSum(Root->Right);
}

int CalculateTreeHeight(Vertex* Root)
{
    if (Root == 0) return 0;
    else return 1 + max(CalculateTreeHeight(Root->Left), CalculateTreeHeight(Root->Right));
}

int CalculatePathLenght(Vertex* Root, int l)
{
    if (Root == NULL) return 0; 
    else return l + CalculatePathLenght(Root->Left, l + 1) + CalculatePathLenght(Root->Right, l + 1);
}

int main()
{
	setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int size = 100;

    int* array = new int[size];
    FillInc(array, size);
    Vertex* Root_ISDP = ISDP(array, 0, size - 1);

    int* randArray = new int[size];
    FillDec(randArray, size);

    Vertex* Root_DoubleCos = NULL;
    for (int i = 0; i < size; i++)
    {
        DoubleCosSDP(Root_DoubleCos, randArray[i]);
    }

    int* randArray_1 = new int[size];
    FillDec(randArray_1, size);

    Vertex* Root_Rec = NULL;
    for (int i = 0; i < size; i++)
    {
        RecSDP(Root_Rec, randArray[i]);
    }

    cout << "Обход ИСДП слева направо: " << endl;
    TreeRight(Root_ISDP);
    cout << endl
        << endl;
    cout << "Обход с добавлением двойной косвенности: " << endl;
    TreeRight(Root_DoubleCos);
    cout << endl
        << endl;
    cout << "Обход с рекурсивным добавлением: " << endl;
    TreeRight(Root_Rec);
    cout << endl
        << endl;

    cout << "N = 100" << setw(25) << "Размер дерева"
        << setw(25)
        << "Сумма дерева"
        << setw(25)
        << "Высота дерева"
        << setw(25)
        << "Средняя высота дерева" << endl;
    cout << "ИСДП"
        << setw(25) << CalculateTreeSize(Root_ISDP) << setw(25) << CalculateTreeSum(Root_ISDP) << setw(20) << CalculateTreeHeight(Root_ISDP) << setw(25) << (float)CalculatePathLenght(Root_ISDP, 1) / CalculateTreeSize(Root_ISDP) << endl;
    cout << "Рекурсивное СДП"
        << setw(14) << CalculateTreeSize(Root_Rec) << setw(25) << CalculateTreeSum(Root_Rec) << setw(20) << CalculateTreeHeight(Root_Rec) << setw(25) << (float)CalculatePathLenght(Root_Rec, 1) / CalculateTreeSize(Root_Rec) << endl;
    cout << "Косвенное СДП"
        << setw(16) << CalculateTreeSize(Root_DoubleCos) << setw(25) << CalculateTreeSum(Root_DoubleCos) << setw(20) << CalculateTreeHeight(Root_DoubleCos) << setw(25) << (float)CalculatePathLenght(Root_DoubleCos, 1) / CalculateTreeSize(Root_DoubleCos) << endl;

    return 0;
}