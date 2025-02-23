#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
bool VR = true, HR = true;

using namespace std;

struct Vertex 
{
    string Data;         
    string Translation; 
    short int Bal;            
    Vertex* Left;           
    Vertex* Right;  
    Vertex* Equal;
};

// Класс абстрактного двоичного дерева
class BinaryTree
{
protected:
    Vertex* Root;

    void DeleteTree(Vertex* node) 
    {
        if (node) 
        {
            DeleteTree(node->Left);
            DeleteTree(node->Right);
            DeleteTree(node->Equal);
            delete node;
        }
    }

public:
    BinaryTree() : Root(nullptr) {}
    virtual ~BinaryTree() { DeleteTree(Root); }

    virtual void Insert(const string& key, const string& translation) = 0;
    virtual string Search_DBD(const string& key) = 0;
    virtual void Remove(const string& key) = 0;
    int CalculateHeight(Vertex* node) 
    {
        if (!node) return 0;
        return 1 + max(CalculateHeight(node->Left), CalculateHeight(node->Right));
    }
    int GetHeight() 
    {
        return CalculateHeight(Root);
    }
};

class DBD : public BinaryTree
{
private:
    void Insert(Vertex*& root, const string& key, const string& translation)
    {
        if (!root)
        {
            root = new Vertex{ key, translation, 0, nullptr, nullptr };
            root->Data = key;
            root->Left = root->Right = nullptr;
            root->Bal = 0;
            VR = true;
        }
        else if (key < root->Data)
        {
            Insert(root->Left, key, translation);
            if (VR)
            {
                if (!root->Bal)
                {
                    Vertex* q = root->Left;
                    root->Left = q->Right;
                    q->Right = root;
                    root = q;
                    q->Bal = 1;
                    VR = false;
                    HR = true;
                }
                else
                {
                    root->Bal = 0;
                    VR = true;
                    HR = false;
                }
            }
            else
                HR = false;
        }
        else if (key > root->Data)
        {
            Insert(root->Right, key, translation);
            if (VR)
            {
                root->Bal = 1;
                HR = true;
                VR = false;
            }
            else if (HR)
            {
                if (root->Bal)
                {
                    Vertex* q = root->Right;
                    root->Bal = 0;
                    q->Bal = 0;
                    root->Right = q->Left;
                    q->Left = root;
                    root = q;
                    VR = true;
                    HR = false;
                }
                else
                    HR = false;
            }
        }
        else if (key == root->Data)
        {
			Vertex* newEqual = new Vertex{ key, translation, 0, nullptr, nullptr };
			newEqual->Data = key;
			newEqual->Equal = root->Equal;
            root->Equal = newEqual;
        }
    }

    string Search_DBD(Vertex* root, const string& key) 
    {
        if (!root) return "Перевод слова не найден.";

        if (key < root->Data) 
            return Search_DBD(root->Left, key);
        else if (key > root->Data) 
            return Search_DBD(root->Right, key);
        else
            return root->Translation; //вернём первый найденный перевод
    }

    void Remove(Vertex*& root, const string& key) 
    {
        if (!root) return;

        if (key < root->Data) 
            Remove(root->Left, key);
        else if (key > root->Data) 
            Remove(root->Right, key);
        else
        {
            if (root->Equal) 
            {
                //если у элемента есть дубли, удаляем первый из цепочки дубликатов
                Vertex* temp = root->Equal;
                root->Equal = root->Equal->Equal;
                delete temp;
            }
            else
            {
                if (!root->Left && !root->Right)
                {
                    delete root;
                    root = nullptr;
                }
                else if (!root->Left) 
                {
                    //один потомок справа
                    Vertex* temp = root;
                    root = root->Right;
                    delete temp;
                }
                else if (!root->Right) 
                {
                    //один потомок слева
                    Vertex* temp = root;
                    root = root->Left;
                    delete temp;
                }
                else
                {
                    //2 потомка: замена минимальным элементом в правом поддереве
                    Vertex* minRight = root->Right;
                    while (minRight->Left) 
                    {
                        minRight = minRight->Left;
                    }
                    root->Data = minRight->Data;
                    root->Translation = minRight->Translation;
                    Remove(root->Right, minRight->Data);
                }
            }
        }
    }

public:
    DBD() : BinaryTree() {}

    void Insert(const string& key, const string& translation) override 
    {
        Insert(Root, key, translation);
    }

    string Search_DBD(const string& key) override
    {
        return Search_DBD(Root, key);
    }

    void Remove(const string& key) override
    {
        Remove(Root, key);
    }

    void TreeRight(Vertex* node) 
    {
        if (!node) return;
        TreeRight(node->Left);
        cout << node->Data << " -> " << node->Translation << endl;
        TreeRight(node->Equal);
        TreeRight(node->Right);
    }

    void Print() 
    {
        if (!Root) 
            cout << "Словарь пустой." << endl;
        else 
            TreeRight(Root);
    }
};

int main() 
{
    setlocale(LC_ALL, "ru");

    DBD derevo;
    derevo.Insert("hello", "привет");
    derevo.Insert("apple", "яблоко");
    derevo.Insert("cat", "кот");
    derevo.Insert("world", "мир");
    derevo.Insert("tree", "дерево");
    derevo.Insert("cat", "кот");
	derevo.Insert("apple", "яблоко");
	derevo.Insert("dog", "собака");
    derevo.Insert("humster", "хомяк");
	derevo.Insert("book", "книга");
	derevo.Insert("cat", "кот");


    cout << "Словарь (обход дерева слева направо):" << endl;
    derevo.Print();

    cout << "\nВысота дерева: " << derevo.GetHeight() << endl;

    //поиск слова и его перевод
    string search_word;
    cout << "\nВведите слово для поиска: ";
    cin >> search_word;
    cout << "Перевод слова '" << search_word << "': " << derevo.Search_DBD(search_word) << endl;

    //удаление слова
    string delete_word;
    cout << "\nВведите слово для удаления: ";
	cin >> delete_word;
	derevo.Remove(delete_word);
    cout << "\nСловарь после удаления '" << delete_word << "':" << endl;
    derevo.Print();
    cout << "\nВысота дерева после удаления слова: " << derevo.GetHeight() << endl;

    return 0;
}
