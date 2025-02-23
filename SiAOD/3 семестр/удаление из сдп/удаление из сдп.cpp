#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

struct Vertex
{
    int Data;
    Vertex* Right;
    Vertex* Left;
};

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
    else if (data >= Root->Data) RecSDP(Root->Right, data);
}

bool Delete_Vertex(int data, Vertex*& Root)
{
    Vertex* q = NULL;
    Vertex** p = &Root;
    while (*p != NULL)
    {
        if (data < (*p)->Data) p = &((*p)->Left);
        else if (data > (*p)->Data) p = &((*p)->Right);
        else break;
    }
    if (*p != NULL)
    {
        q = *p;
        if (q->Left == NULL) *p = q->Right;
        else if (q->Right == NULL) *p = q->Left;
        else
        {
            Vertex* r = q->Left;
            Vertex* S = q;
            if (r->Right != NULL)
            {
                r->Right = q->Right;
                *p = r;
            }
            else
            {
                while (r->Right != NULL)
                {
                    S = r;
                    r = r->Right;
                }
                S->Right = r->Left;
                r->Left = q->Left;
                r->Right = q->Right;
                *p = r;
            }
        }
        delete q;
    }
    else return false;
    return true;
    
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

int main()
{
    setlocale(LC_ALL, "ru");
    Vertex* Root = NULL;
    int N, data;

    cout << "Введите количество элементов для добавления в дерево: ";
    cin >> N;
    cout << "Введите элементы для добавления в дерево: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        RecSDP(Root, data);
    }

    cout << "\nДерево (слева направо): ";
    TreeRight(Root);
    cout << endl;

    char choice;
    do
    {
        cout << "\nВведите ключ для удаления: ";
        cin >> data;
        Delete_Vertex(data, Root);

        cout << "\nДерево после удаления вершины " << data << ": ";
        if (Root == NULL)
            cout << "Дерево пусто";
        else
            TreeRight(Root);
        cout << endl;

        if (Root != NULL) 
        {
            cout << "Хотите удалить еще одну вершину? (y/n): ";
            cin >> choice;
        }
        else
        {
            cout << "Все вершины удалены. Программа завершена.\n";
            break;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}