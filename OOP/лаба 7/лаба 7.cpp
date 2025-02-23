#include <iostream>
#include <stdexcept> // Для исключений
#include <locale>

using namespace std; 
// try - блок возбуждения исключительных ситуаций и возбуждение исключения
// catch - блок перехвата исключительных ситуций 
struct Node 
{
    int data;
    Node* next;    

    Node(int value) : data(value), next(nullptr) {}
};

class List //базовый класс СПИСОК
{
protected:
    Node* head;    
    Node* tail; 
    static int totalObjects; //общее кол-во созданных объектов

public:
    List() : head(nullptr), tail(nullptr) { ++totalObjects; } // Конструктор по умолчанию

    List(const List& other) = delete;            // Запрет конструктора копирования
    List& operator=(const List& other) = delete; // Запрет присваивания

    virtual void Add(int value)     //добавление элемента конец списка
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    virtual int Remove()     //удаление первого элемента
    {
        if (!head) 
            throw runtime_error("Список пуст!"); // Исключение (удаление из пустого списка)
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        if (!head) 
            tail = nullptr;
        delete temp;
        return value;
    }

    void Print() const      //печать списка
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    bool IsEmpty() const
    {
        return head == nullptr;
    }

    virtual ~List()     // Очистка списка
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    static int GetTotalObjects() { return totalObjects; }     //получить общее количество созданных объектов
};

int List::totalObjects = 0; //инициализация статического члена


class Stack : public List 
{
public:
    Stack() : List() {}

    void Add(int value) override     //добавление элемента (LIFO: добавляем в начало)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
    }

    int Remove() override     //удаление элемента (LIFO)
    {
        return List::Remove();
    }
};


class Queue : public List //производный класс ОЧЕРЕДЬ
{
public:
    Queue() : List() {}

    //добавление элемента (FIFO: добавляем в конец)
    void Add(int value) override
    {
        List::Add(value);
    }

    //удаление элемента (FIFO)
    int Remove() override
    {
        return List::Remove();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        cout << "Работа с виртуальным методом Remove:" << endl;
        List* list = new Stack(); 

        if (list->IsEmpty())
        {
            cout << "Список пуст. Добавление элементов для проверки:" << endl;
            list->Add(10);
            list->Add(20);
            list->Add(30);
            list->Print();
        }
        else
        {
            cout << "Список не пуст. Удаляем элемент:" << endl;
            cout << "Удалено: " << list->Remove() << endl;
            list->Print();
        }

        cout << "Попытка удаления из пустого списка:" << endl;
        while (!list->IsEmpty())
        {
            list->Remove();
        }
        list->Remove(); //исключение из виртуального метода Remove
    }
    catch (const runtime_error& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }

    cout << "Всего объектов СПИСОК: " << List::GetTotalObjects() << endl;
    return 0;
}
