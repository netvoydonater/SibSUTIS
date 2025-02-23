#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int n = 10;

struct tLE //tLE - тип элемента списка (type of List Element)
{
    tLE* next; //указатель на след.элемент
    int data; //данные, которые я добавляю в список 
}*head, *tail; //указатели на голову и хвост

void StackFillInc(int n, tLE* (&head))
{
    int i = n; //i - локальная переменная 
    tLE* p;
    p = NULL; //у указателя р отсутствует адрес
    do 
    {
        head = (struct tLE*)malloc(sizeof(struct tLE)); //выделение памяти, head - динамический массив
        head->next = p; //указатель на адрес след.элемента
        p = head;
        head->data = i; 
        i--;

    } while (i > 0);
}

void StackFillDec(int n, tLE* (&head))
{
    int i = 1;
    tLE* p;
    p = NULL;
    do 
    {
        head = (struct tLE*)malloc(sizeof(struct tLE));
        head->next = p;
        p = head;
        head->data = i;
        i++;

    } while (i <= n);
}

void StackFillRand(int n, tLE* (&head))
{
    srand(time(NULL));
    int i = 1;
    tLE* p;
    p = NULL;
    do 
    {
        head = (struct tLE*)malloc(sizeof(struct tLE));
        head->next = p;
        p = head;
        head->data = rand() % (n * 2) - n;
        i++;

    } while (i <= n);

}

void QueueFillInc(int n, tLE* (&head), tLE* (&tail))
{
    int i = 1;
    tLE* p;
    head = tail = (struct tLE*)malloc(sizeof(struct tLE));
    head->next = tail->next = 0;
    tail->data = i;
    i++;
    do 
    {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = i;
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;
}

void QueueFillDec(int n, tLE* (&head), tLE* (&tail))
{
    int i = n;
    tLE* p;
    head = tail = (struct tLE*)malloc(sizeof(struct tLE));
    head->next = tail->next = 0;
    tail->data = i;
    i--;
    do 
    {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = i;
        tail->next = p;
        tail = p;
        i--;

    } while (i > 0);
    tail->next = 0;
}

void QueueFillRand(int n, tLE* (&head), tLE* (&tail))
{
    srand(time(NULL));
    int i = 1;
    tLE* p;
    head = tail = (struct tLE*)malloc(sizeof(struct tLE));
    head->next = tail->next = 0;
    tail->data = rand() % (n * 2) - n;
    i++;
    do 
    {
        p = (struct tLE*)malloc(sizeof(struct tLE));
        p->data = rand() % (n * 2) - n;
        tail->next = p;
        tail = p;
        i++;

    } while (i <= n);
    tail->next = 0;

}

int CheckSum(tLE* head)
{
    tLE* p;
    int sum = 0;
    for (p = head; p; p = p->next) 
    {
        sum += p->data;
    }
    return sum;
}

int RunNumber(tLE* head) 
{
    int sequence = 1;
    tLE* p;
    for (p = head; p->next; p = p->next) 
    {
        if (p->data > p->next->data) sequence++;
    }
    return sequence;
}

void PrintList(tLE*  head, tLE* tail = NULL)
{
    struct tLE* p;
    for (p = head; p; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void Swap_Elements() //доп.задание
{ 
    tLE* first = head;
    tLE* second = first->next;
    tLE* third = second->next;
    tLE* fourth = third->next;
    
    head = third;
    third->next = second;
    second->next = first;
    first->next = fourth;
 }

int main()
{
    printf("----------STACK----------\n");
    StackFillInc(n, head);
    printf("FillInc:\n");
    PrintList(head);
    Swap_Elements();
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));

    printf("\n");
    StackFillDec(n, head);
    printf("\nFillDec:\n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));

    printf("\n");
    StackFillRand(n, head);
    printf("\nFillRand:\n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));

    printf("\n\n");
    printf("----------QUEUE----------\n");
    QueueFillInc(n, head, tail);
    printf("FillInc:\n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));

    printf("\n");
    QueueFillDec(n, head, tail);
    printf("\nFillDec:\n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));

    printf("\n");
    QueueFillRand(n, head, tail);
    printf("\nFillRand:\n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));


    return 0;
}