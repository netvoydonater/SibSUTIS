#include <iostream>
#include <iomanip>
#include <locale>
 
using namespace std;

struct Vertex
{
	int Data;
	Vertex* Left;
	Vertex* Right;
};

void Obhod1(Vertex* p)
{
	if (p != NULL)
	{
		cout << " " << p->Data;
		Obhod1(p->Left);
		Obhod1(p->Right);
	}
}

void Obhod2(Vertex* p)
{
	if (p != NULL)
	{
		Obhod1(p->Left);
		cout << " " << p->Data;
		Obhod1(p->Right);
	}
}

void Obhod3(Vertex* p)
{
	if (p != NULL)
	{
		Obhod1(p->Left);
		Obhod1(p->Right);
		cout << " " << p->Data;
	}
}

int Razmer(Vertex* p)
{
	int n;
	if (p == NULL) n = 0;
	else n = 1 + Razmer(p->Left) + Razmer(p->Right);
	return n;
}

int Summa(Vertex* p)
{
	int s;
	if (p == NULL) s = 0;
	else s = p->Data + Summa(p->Left) + Summa(p->Right);
	return s;
}

int Vysota(Vertex* p)
{
	int h;
	if (p == NULL) h = 0;
	else h = 1 + max(Vysota(p->Left), Vysota(p->Right));
	return h;
}

int Summa_dlin_putey(Vertex* p, int L)
{
	int s;
	if (p == NULL) s = 0;
	else s = L + Summa_dlin_putey(p->Left, L + 1) + Summa_dlin_putey(p->Right, L + 1);
	return s;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Vertex* Root;
	Root = new Vertex;
	Root->Data = 1;
	Root->Right = NULL;

	Root->Left = new Vertex;
	Root->Left->Data = 2;

	Root->Left->Left = new Vertex;
	Root->Left->Left->Data = 3;
	Root->Left->Left->Left = NULL;

	Root->Left->Right = new Vertex;
	Root->Left->Right->Data = 4;
	Root->Left->Right->Left = NULL;
	Root->Left->Right->Right = NULL;

	Root->Left->Left->Right = new Vertex;
	Root->Left->Left->Right->Data = 5;
	Root->Left->Left->Right->Left = NULL;

	Root->Left->Left->Right->Right = new Vertex;
	Root->Left->Left->Right->Right->Data = 6;
	Root->Left->Left->Right->Right->Left = NULL;
	Root->Left->Left->Right->Right->Right = NULL;

	printf("          %d      \n", Root->Data);
	printf("\n      %d   \n", Root->Left->Data);
	printf("\n    %d     %d   \n", Root->Left->Left->Data, Root->Left->Right->Data);
	printf("\n      %d  \n", Root->Left->Left->Right->Data);
	printf("\n        %d  \n", Root->Left->Left->Right->Right->Data);


	cout << "Обход сверху вниз:\n";
	Obhod1(Root);
	
	cout << "\nОбход слева направо:\n";
	Obhod2(Root);
	
	cout << "\nСнизу вверх:\n";
	Obhod3(Root);

	double h1 = static_cast<double>(Summa_dlin_putey(Root, 1) / Razmer(Root));
	cout << "\nРазмер дерева: \n"<< Razmer(Root);
	Razmer(Root);
	cout << "\nСумма дерева: \n"<< Summa(Root);
	Summa(Root);
	cout << "\nВысота дерева: \n"<< Vysota(Root);
	Vysota(Root);
	cout << "\nСредняя длина дерева: \n"<<fixed << setprecision(2)<< h1;

  	return 0;
}