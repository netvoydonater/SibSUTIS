#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale>

using namespace std;

struct Vertex
{
    int Data = 0;
    short int Bal = 0;
    Vertex* Right = NULL;
    Vertex* Left = NULL;
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
    bool table[110] = { false };
    int x;
    for (int i = 0; i < n; i++)
    {
        do
        {
            x = rand() % 110 + 1;
        } while (table[x]);
        table[x] = true;
        A[i] = x;
    }
}

void TreeRight(Vertex*& p)
{
    if (p != NULL)
    {
        TreeRight(p->Left);
        cout << " " << p->Data;
        TreeRight(p->Right);
    }
}

int CalculateTreeSize(Vertex*& p)
{
    if (p == NULL) return 0;
    else return 1 + CalculateTreeSize(p->Left) + CalculateTreeSize(p->Right);
}

int CalculateTreeSum(Vertex*& p)
{
    if (p == NULL) return 0;
    else return p->Data + CalculateTreeSum(p->Left) + CalculateTreeSum(p->Right);
}

int CalculateTreeHeight(Vertex*& p)
{
    if (p == 0) return 0;
    else return 1 + max(CalculateTreeHeight(p->Left), CalculateTreeHeight(p->Right));
}

int CalculatePathLenght(Vertex*& p, int l)
{
    if (p == NULL) return 0;
    else return l + CalculatePathLenght(p->Left, l + 1) + CalculatePathLenght(p->Right, l + 1);
}

void LL_rotate(Vertex*& p)
{
    Vertex* q = p->Left;
    p->Bal = 0;
    q->Bal = 0;
    p->Left = q->Right;
    q->Right = p;
    p = q;
}

void RR_rotate(Vertex*& p)
{
    Vertex* q = p->Right;
    p->Bal = 0;
    q->Bal = 0;
    p->Right = q->Left;
    q->Left = p;
    p = q;
}

void LR_rotate(Vertex*& p)
{
    Vertex* q = p->Left;
    Vertex* r = q->Right;
    if (r->Bal < 0) p->Bal = 1;
    else p->Bal = 0;

    if (r->Bal > 0) q->Bal = -1;
    else q->Bal = 0;

    r->Bal = 0;
    q->Right = r->Left;
    p->Left = r->Right;
    r->Left = q;
    r->Right = p;
    p = r;
}

void RL_rotate(Vertex*& p)
{
    Vertex* q = p->Right;
    Vertex* r = q->Left;
    if (r->Bal > 0) p->Bal = -1;
    else p->Bal = 0;

    if (r->Bal < 0) q->Bal = 1;
    else q->Bal = 0;

    r->Bal = 0;
    q->Left = r->Right;
    p->Right = r->Left;
    r->Right = q;
    r->Left = p;
    p = r;
}

bool add_AVL(int data, Vertex*& p, bool& Rost)
{
    if (p == NULL) 
    {
        p = new Vertex;
        p->Data = data;
        p->Left = NULL;
        p->Right = NULL;
        p->Bal = 0;
        Rost = true;
    }
    else if (p->Data > data) 
    {
        add_AVL(data, p->Left, Rost);
        if (Rost) 
        {
            if (p->Bal > 0) 
            {
                p->Bal = 0;
                Rost = false;
            }
            else if (p->Bal == 0) 
            {
                p->Bal = -1;
                Rost = true;
            }
            else if ((p->Left)->Bal < 0)
            {
                LL_rotate(p);
                Rost = false;
            }
            else 
            {
                LR_rotate(p);
                Rost = false;
            }
        }
        else return false;
    }

    else if (p->Data < data) 
    {
        add_AVL(data, p->Right, Rost);
        if (Rost)
        {
            if (p->Bal < 0)
            {
                p->Bal = 0;
                Rost = false;
            }
            else if (p->Bal == 0)
            {
                p->Bal = 1;
                Rost = true;
            }
            else if ((p->Right)->Bal > 0)
            {
                RR_rotate(p);
                Rost = false;
            }
            else 
            {
                RL_rotate(p);
                Rost = false;
            }
        }
        else return false;
    }
    else return false;
    return true;
}

Vertex* create_AVL(int n, int* Arr) 
{
    Vertex* Root = NULL;
    bool Rost;
    for (int i = 0; i < n; i++)
    {
        add_AVL(Arr[i], Root, Rost);
    }
    return Root;
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

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int size = 100;

    int* array = new int[size];   
    FillRand(array, size);
    Vertex* AVL_Tree = create_AVL(size, array);
    int AVL_Size = CalculateTreeSize(AVL_Tree);
    int AVL_Sum = CalculateTreeSum(AVL_Tree);
    int AVL_Height = CalculateTreeHeight(AVL_Tree);
    int AVL_PathLength = CalculatePathLenght(AVL_Tree, 1);
    double AVL_AvgHeight = static_cast<double>(AVL_PathLength) / AVL_Size;
    cout << "Обход АВЛ слева направо:\n";
    TreeRight(AVL_Tree);
    cout << endl;

	cout << "\n" << endl;

    int* array1 = new int[size];
    FillInc(array1, size);
    Vertex* Root_ISDP = ISDP(array1, 0, size - 1);
    int ISDP_Size = CalculateTreeSize(Root_ISDP);
    int ISDP_Sum = CalculateTreeSum(Root_ISDP);
    int ISDP_Height = CalculateTreeHeight(Root_ISDP);
    int ISDP_PathLength = CalculatePathLenght(Root_ISDP, 1);
    double ISDP_AvgHeight = static_cast<double>(ISDP_PathLength) / ISDP_Size;
    cout << "Обход ИСДП слева направо:\n";
    TreeRight(Root_ISDP);
    cout << endl;

    cout << "\n" << endl;

    cout << setw(10) << "N = 100" << setw(10) << "Размер" << setw(15) << "Контр. сумма" << setw(10) << "Высота" << setw(15) << "Средн. высота" << endl;
    cout << setw(10) << "ИСДП" << setw(10) << ISDP_Size << setw(15) << ISDP_Sum << setw(10) << ISDP_Height << setw(15) << ISDP_AvgHeight << endl;
    cout << setw(10) << "АВЛ" << setw(10) << AVL_Size << setw(15) << AVL_Sum << setw(10) << AVL_Height << setw(15) << AVL_AvgHeight << endl;

    
   /* cout << "Размер дерева: " << CalculateTreeSize(AVL_Tree) << endl;
    cout << "Сумма элементов дерева: " << CalculateTreeSum(AVL_Tree) << endl;
    cout << "Высота дерева: " << CalculateTreeHeight(AVL_Tree) << endl;
    cout << "Длина всех путей в дереве: " << CalculatePathLenght(AVL_Tree, 0) << endl;
*/

    delete[] array;
    delete[] array1;
    return 0;
}
