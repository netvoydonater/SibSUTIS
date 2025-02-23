#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int n = 20;
int M, C;

struct tLE
{
    tLE* next;
    int data;
}*head, * tail;

struct Queue
{
	tLE* head;
	tLE* tail;
};

void StackFillInc(int n, tLE* (&head))
{
    int i = n;
    tLE* p;
    p = NULL;
    do
    {

        head = (struct tLE*)malloc(sizeof(struct tLE));
        head->next = p;
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

void StackFillRand(int n, tLE* (&head), tLE* (&tail))
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
        ;
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
        if (p->data > p->next->data)
            sequence++;
    }
    return sequence;
}

void PrintList(tLE* head, tLE* tail = NULL)
{
    struct tLE* p;
    for (p = head; p; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void Merge(tLE** a, int q, tLE** b, int r, Queue* c, int& C, int& M) //слияние
{
    while (q != 0 && r != 0)
    {
        C++;
        if ((*a)->data <= (*b)->data)
        {
            M++;
            c->tail->next = *a;
            c->tail = *a;
            *a = (*a)->next;
            q--;
        }
        else
        {
            M++;
            c->tail->next = *b;
            c->tail = *b;
            *b = (*b)->next;
            r--;
        }
    }
    while (q > 0)
    {
        M++;
        c->tail->next = *a;
        c->tail = *a;
        *a = (*a)->next;
        q--;
    }
    while (r > 0)
    {
        M++;
        c->tail->next = *b;
        c->tail = *b;
        *b = (*b)->next;
        r--;
    }
}

int Split(tLE* S, tLE** a, tLE** b, int& M) //расщепление 
{
    tLE* k, * p;
    *a = S;
    *b = S->next; 
    int n = 1;
    k = *a;
    p = *b;
    while (p != NULL)
    {
        n++;
        k->next = p->next;
        k = p;
        p = p->next;
    }
    M += n;
    return n;
}

void MergeSort(tLE* (&S), tLE* (&tail), int& C, int& M)
{
    C = 0, M = 0;
    tLE* a;
    tLE* b;
    int n = Split(S, &a, &b, M);
    int p = 1; // предполагаемый размер серии
    int q, r;  // фактический размер серий a и b
    Queue c[2];
    while (p < n)
    {
        c[0].tail = (tLE*)&(c[0].head);
        c[1].tail = (tLE*)&(c[1].head);

        int i = 0;
        int m = n; // текущее кол-во элементов в a и b
        while (m > 0)
        {
            if (m >= p)
                q = p;
            else
                q = m;

            m = m - q;

            if (m >= p)
                r = p;
            else
                r = m;

            m = m - r;
            Merge(&a, q, &b, r, &c[i], C, M);
            i = 1 - i;
        }
        a = c[0].head;
        b = c[1].head;
        p = 2 * p;
    }
    c[0].tail->next = NULL;
    S = c[0].head;
    tail = c[0].tail;
}

void Merge_MC_Teor() //подсчёт теоретической трудоёмкости
{
    int C_teor = n * ceil(log2(n)), M_teor = n * ceil(log2(n));
    int T_teor = C_teor + M_teor;
    printf("\nM(teor) + C(teor) = %d", T_teor);
}

void MergeSortTable()
{
    int A[500];
    int i1, i2, i3, i4, i5;
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;

    M = 0, C = 0;
    StackFillInc(100, head);
    MergeSort(head, tail, C, M);
    i1 = M + C;

    M = 0, C = 0;
    StackFillInc(200, head);
    MergeSort(head, tail, C, M);
    i2 = M + C;

    M = 0, C = 0;
    StackFillInc(300, head);
    MergeSort(head, tail, C, M);
    i3 = M + C;

    M = 0, C = 0;
    StackFillInc(400, head);
    MergeSort(head, tail, C, M);
    i4 = M + C;

    M = 0, C = 0;
    StackFillInc(500, head);
    MergeSort(head, tail, C, M);
    i5 = M + C;

    M = 0, C = 0;
    StackFillDec(100, head);
    MergeSort(head, tail, C, M);
    d1 = M + C;

    M = 0, C = 0;
    StackFillDec(200, head);
    MergeSort(head, tail, C, M);
    d2 = M + C;

    M = 0, C = 0;
    StackFillDec(300, head);
    MergeSort(head, tail, C, M);
    d3 = M + C;

    M = 0, C = 0;
    StackFillDec(400, head);
    MergeSort(head, tail, C, M);
    d4 = M + C;

    M = 0, C = 0;
    StackFillDec(500, head);
    MergeSort(head, tail, C, M);
    d5 = M + C;

    M = 0, C = 0;
    StackFillRand(100, head, tail);
    MergeSort(head, tail, C, M);
    r1 = M + C;

    M = 0, C = 0;
    StackFillRand(200, head, tail);
    MergeSort(head, tail, C, M);
    r2 = M + C;

    M = 0, C = 0;
    StackFillRand(300, head, tail);
    MergeSort(head, tail, C, M);
    r3 = M + C;

    M = 0, C = 0;
    StackFillRand(400, head, tail);
    MergeSort(head, tail, C, M);
    r4 = M + C;

    M = 0, C = 0;
    StackFillRand(500, head, tail);
    MergeSort(head, tail, C, M);
    r5 = M + C;

    printf("-----------------------------------------------------------------------------\n");
    printf("|    N    |                             c + m of Merge                      |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|/////////|       teor        |      Dec      |      Inc     |     Rand     |\n");
    printf("----------------------------------------------------------------------------\n");
    printf("|   100   |       664         |      %d     |     %d     |     %d     |\n", d1, i1, r1);
    printf("|   200   |       1529        |      %d     |     %d     |     %d     |\n", d2, i2, r2);
    printf("|   300   |       2469        |      %d     |     %d     |     %d     |\n", d3, i3, r3);
    printf("|   400   |       3458        |      %d     |     %d     |     %d     |\n", d4, i4, r4);
    printf("|   500   |       4483        |      %d     |     %d     |     %d     |\n", d5, i5, r5);
    printf("----------------------------------------------------------------------------");
}

int main()
{
    printf("-----------STACK----------\n");
    StackFillInc(n, head);
    printf("FillInc: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();

    printf("\n\n");

    StackFillDec(n, head);
    printf("FillDec: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();

    printf("\n\n");

    StackFillRand(n, head, tail);
    printf("FillRand: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();

    printf("\n\n\n"); 
    

    printf("----------QUEUE----------");
    QueueFillInc(n, head, tail);
    printf("\nFillInc: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();

    printf("\n\n");

    QueueFillDec(n, head, tail);
    printf("\nFillDec: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();

    printf("\n\n");

    QueueFillRand(n, head, tail);
    printf("FillRand: \n");
    printf("Elementary list: \n");
    PrintList(head);
    printf("\nSum numbers: %d", CheckSum(head));
    printf("\nSeries: %d", RunNumber(head));
    MergeSort(head, tail, C, M);
    printf("\nFinal list: \n");
    PrintList(head);
    printf("\nC = %d, M = %d\n", C, M);
    printf("\nC + M = %d\n", C + M);
    Merge_MC_Teor();
    printf("\n\n");

    MergeSortTable();


    return 0;
}