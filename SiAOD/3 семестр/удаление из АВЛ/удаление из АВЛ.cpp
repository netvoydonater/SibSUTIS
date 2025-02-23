#include <iostream>
#include <locale>

using namespace std;

struct Vertex
{
    int Data = 0;
    short int Bal = 0;
    Vertex* Right = NULL;
    Vertex* Left = NULL;
};

void TreeRight(Vertex*& p)
{
    if (p != NULL)
    {
        TreeRight(p->Left);
        cout << " " << p->Data;
        TreeRight(p->Right);
    }
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

void LL1_rotate(Vertex*& p, bool& Umen)
{
    Vertex* q = p->Left;
    if (q->Bal = 0)
    {
        q->Bal = 1;
		p->Bal = -1;
        Umen = false;
    }
    else
    {
        q->Bal = 0;
		p->Bal = 0;
    }
    p->Left = q->Right;
	q->Right = p;
	p = q;
}

void RR1_rotate(Vertex*& p, bool& Umen)
{
    Vertex* q = p->Right;
    if (q->Bal = 0)
    {
        q->Bal = 1;
        p->Bal = -1;
        Umen = false;
    }
    else
    {
        q->Bal = 0;
        p->Bal = 0;
    }
    p->Right = q->Left;  //
    q->Left = p;
    p = q;
}

void LR1_rotate(Vertex*& p)
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

void RL1_rotate(Vertex*& p)
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

void BL(Vertex*& p, bool& Umen)
{
    if (p->Bal = -1) p->Bal = 0;
    else if (p->Bal = 0)
    {
        p->Bal = 1; 
        Umen = false;
    }
    else if (p->Bal = 1)
    {
        if (p->Right->Bal >= 0) RR1_rotate(p, Umen);
		else RL1_rotate(p);
    }
}

void BR(Vertex*& p, bool& Umen)
{
	if (p->Bal = 1) p->Bal = 0;
    else if (p->Bal = 0)
    {
        p->Bal = -1; 
        Umen = false;
    }
    else if (p->Bal = -1)
	{
		if (p->Left->Bal <= 0) LL1_rotate(p, Umen);
		else LR1_rotate(p);
	}
}

void del(Vertex*& r, Vertex*& q, bool& Umen)
{
    if (r->Right != NULL)
    {
        del(r->Right, q, Umen);
        if (Umen) BR(r, Umen);
    }
    else
    {
        q->Data = r->Data;
        q = r;
		r = r->Left;
		Umen = true;
    }
}

bool delete_AVL(Vertex*& p, int key, bool& Umen)
{
    Vertex* q = NULL;
    if (p == NULL) return 1;
    else if (key < p->Data)
    {
        delete_AVL(p->Left, key, Umen);
        if (Umen) BL(p, Umen);
    }
    else if (key > p->Data)
    {
        delete_AVL(p->Right, key, Umen);
        if (Umen) BR(p, Umen);
    }
    else
    {
        q = p;
        if (q->Left == NULL)
        {
            p = q->Right;
            Umen = true;
        }
        else if (q->Right == NULL)
        {
			p = q->Left;
			Umen = true;
        }
        else
        {
			del(q->Left, q, Umen);
			if (Umen) BL(p, Umen);
        }
    }
	delete q;
	return 0;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Vertex* p = NULL;
	bool Rost = false;
	bool Umen = false;
    int N, data;

    cout << "Введите количество элементов для добавления в дерево: ";
    cin >> N;
    cout << "Введите элементы для добавления в дерево: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
		add_AVL(data, p, Rost);
    }
    cout << "\nОбход дерева (слева направо): ";
	TreeRight(p);
    cout << endl;

    char choice;
    do
    {
        cout << "\nВведите ключ для удаления: ";
        cin >> data;
		delete_AVL(p, data, Umen);

        cout << "\nДерево после удаления вершины " << data << ": ";
        if (p == NULL) cout << "Дерево пусто";
        else TreeRight(p);
        cout << endl;

        if (p != NULL)
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
}