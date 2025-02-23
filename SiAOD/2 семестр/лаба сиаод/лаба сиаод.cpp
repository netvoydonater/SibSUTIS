#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
const int n = 10;
int m, c;
int x;
void swap(int* x, int* y) //обмен двух значений 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//сортировки массивов
void SelectSort(int* num, int size)
{
    int min;
    c = 0, m = 0;
    for (int i = 0; i < size - 1; i++)
    {

        min = i;
        for (int j = i + 1; j < size; j++)
        {
            c += 1;
            if (num[j] < num[min])
                min = j;
        }
        swap(&num[i], &num[min]);
        m += 3;
    }
}

void BubbleSort(int A[], int size)
{
    c = 0, m = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            c++;;
            if (A[j - 1] > A[j])
            {
                swap(&A[j - 1], &A[j]);
                m += 3;
            }
        }
    }
}

void ShakerSort(int A[], int size)
{
    c = 0, m = 0;
    int left = 0, right = size - 1;
    int swapped = size;


    while ((left < right))
    {
        for (int i = right; i >= left + 1; i--)
        {
            c++;
            if (A[i] < A[i - 1])
            {
                swap(&A[i], &A[i - 1]);
                m += 3;
                swapped = i;
            }
        }
        left = swapped;
        for (int i = left; i <= right - 1; i++)
        {
            c++;
            if (A[i] > A[i + 1])
            {
                swap(&A[i], &A[i + 1]);
                m += 3;
                swapped = i;
            }
        }
        right = swapped;
    }
}

void InsertSort(int A[], int size)
{
    c = 0, m = 0;
    for (int i = 1; i < size; i++)
    {
        int t = A[i];
        int j = i - 1;
        m++;
        while (j >= 0 && A[j] > t)
        {
            A[j + 1] = A[j];
            j = j - 1;
            c++;
            if (A[j] <= t)
            {
                break;
            }
            m++;
        }
        A[j + 1] = t;
        m += 2;
    }
}

int Knuth_Sort(int i)
{
    if (i > 0)
    {
        return 2 * Knuth_Sort(i - 1) + 1;
    }
    else
    {
        return 1;
    }
}

void ShellSort(int A[], int size)
{
    m = 0, c = 0;
    int i, j, k, tmp, M;
    for (M = floor(log2(size)) - 1; M > 0; M--)
    {
        k = Knuth_Sort(M);
        for (i = k; i < size; i++)
        {
            tmp = A[i];
            m++;
            j = i - k;
            c++;
            while (j >= 0 && tmp < A[j])
            {
                c++;
                A[j + k] = A[j];
                m++;
                j -= k;
            }
            A[j + k] = tmp;
            m++;
        }

    }
}

int BinarySearch1(int A[], int size, int x)
{
   c = 0, m = 0;
   int left = 0, right = size - 1, Mid = 0;
   while (left <= right)
   {
       Mid = left + (right - left) / 2;
       c++;
       if (A[Mid] == x) return Mid;
       c++;
       if (A[Mid] < x) left = Mid + 1;
       else right = Mid - 1;
   }
   return -1;
}

int BinarySearch2(int A[], int size, int x)
{
    c = 0, m = 0;
    int left = 0, right = size - 1, Mid = 0;
    while (left < right)
    {
        Mid = left + (right - left) / 2;
        c++;
        if (A[Mid] < x) left = Mid + 1;
        else right = Mid;
    }
    c++;
    if (A[left] == x) return left;
    else return -1; 
}

void Heap(int A[], int left, int right)
{
    m++;
    int x = A[left];
    int i = left;
    while (1) 
    {
        int j = 2 * i;
        if (j > right) break;
        c++;
        if ((j < right) && (A[j + 1] <= A[j])) j += 1;
        c++;
        if (x <= A[j]) break;
        m++;
        A[i] = A[j];
        i = j;
    }
    m++;
    A[i] = x;
}

void HeapSort(int A[], int size)
{
    c = 0, m = 0;
    int left, right;
    left = floor((size - 1) / 2);
    while (left >= 0) 
    {
        Heap(A, left, size - 1);
        left--;
    }
    right = size - 1;
    while (right > 0) 
    {
        swap(&A[0], &A[right]);
        m += 3;
        right--;
        Heap(A, 0, right);
    }
}

void QuickSortV1(int A[], int left, int right)
{
    int x = A[left], i = left, j = right;
    while (i < j)
    {
        while (A[i] < x)
        {
            c++;
            i++;
        }
        while (A[j] > x)
        {
            c++;
            j--;
        }
        if (i <= j)
        {
            c++;
            m += 3;
            swap(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    if (left < j)
    {
        c++;
        QuickSortV1(A, left, j);
    }
    if (i < right)
    {
        c++;
        QuickSortV1(A, i, right);
    }
}

void Quick_teor_mc()
{
    int c_teor = (n * n + 5 * n + 4) / 2, m_teor = 3 * (n - 1);
    int t_teor = c_teor + m_teor;
    printf("\nm(teor) + c(teor) = %d", t_teor);

}

//для курсовой работы
void QuickSortV2(int A[], int left, int right)
{
    int x = A[(left + right)] / 2, i = left, j = right;
    while (left < right)
    {
        while (A[i] < x)
        {
            c++;
            i++;
        }
        while (A[j] > x)
        {
            c++;
            j--;
        }
        if (i <= j)
        {
            c++;
            m += 3;
            swap(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    if (j - left < right - i)
    {
        c++;
        QuickSortV2(A, left, j);
        left = i;
    }
    else if (j - right > right - i)
    {
        c++;
        QuickSortV2(A, i, right);
        right = j;
    }
}


struct Abonent
{
    char surname[50];
    char name[50];
    char patronymic[50]; //отчество 
    char adress[15];
};
//сортировка массивов структур
int less(const struct Abonent* x, const struct Abonent* y, char* type) //surname - главный ключ, который можно поменять
{
        if (strcmp(x->surname, y->surname) == 0)
            return strcmp(x->name, y->name) < 0;
        return strcmp(x->surname, y->surname) < 0;
}

void PrintStrict(const struct Abonent* contacts, int size)
{
    for (int i = 0; i < size; i++)
        printf("%s\t%s\t%s\t%s\n", contacts[i].surname, contacts[i].name, contacts[i].patronymic, contacts[i].adress);
}

void SelectSortAbonent(struct Abonent* contacts, int size, char* type)
{
    for (int i = 0; i < size - 1; i++)
    {
        int M = i;
        for (int j = i + 1; j < size; j++)
            if (less( &contacts[j], &contacts[M], type)) M = j;
        if (M != i)
        {
            struct Abonent temp = contacts[i];
            contacts[i] = contacts[M];
            contacts[M] = temp;
        }
    }
}



void FillInc(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
}

void FillDec(int A[], int n)
{
    int value = n;
    for (int i = 0; i < n; i++)
    {
        A[i] = value;
        value--;
    }
}

void FillRand(int A[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % (n * 2);
    }
}

void Printmas(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

/*void InsertShellTable()
{
    int A[500];

    int i1, i2, i3, i4, i5;
    int sh1, sh2, sh3, sh4, sh5;

    FillRand(A, 100);
    InsertSort(A, 100);
    i1 = c + m;

    FillRand(A, 200);
    InsertSort(A, 200);
    i2 = c + m;

    FillRand(A, 300);
    InsertSort(A, 300);
    i3 = c + m;

    FillRand(A, 400);
    InsertSort(A, 400);
    i4 = c + m;

    FillRand(A, 500);
    InsertSort(A, 500);
    i5 = c + m;

    FillRand(A, 100);
    ShellSort(A, 100);
    sh1 = c + m;

    FillRand(A, 200);
    ShellSort(A, 200);
    sh2 = c + m;

    FillRand(A, 300);
    ShellSort(A, 300);
    sh3 = c + m;

    FillRand(A, 400);
    ShellSort(A, 400);
    sh4 = c + m;

    FillRand(A, 500);
    ShellSort(A, 500);
    sh5 = c + m;

    printf("+---------+----------------------+-------------------------+\n");
    printf("|    N    |       Insert m + c   |       Shell m + c       |\n");
    printf("|---------|----------------------|-------------------------|\n");
    printf("|   100   |         %d         |           %d          |\n", i1, sh1);
    printf("|---------|----------------------|-------------------------|\n");
    printf("|   200   |         %d        |           %d          |\n", i2, sh2);
    printf("|---------|----------------------|-------------------------|\n");
    printf("|   300   |         %d        |           %d          |\n", i3, sh3);
    printf("|---------|----------------------|-------------------------|\n");
    printf("|   400   |         %d        |           %d         |\n", i4, sh4);
    printf("|---------|----------------------|-------------------------|\n");
    printf("|   500   |        %d        |           %d         |\n", i5, sh5);
    printf("|---------|----------------------|-------------------------|\n");
}*/


/*void InsertTable()
{
    int A[500];
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;
    int i1, i2, i3, i4, i5;

    FillDec(A, 100);
    InsertSort(A, 100);
    d1 = c + m;

    FillDec(A, 200);
    InsertSort(A, 200);
    d2 = c + m;

    FillDec(A, 300);
    InsertSort(A, 300);
    d3 = c + m;

    FillDec(A, 400);
    InsertSort(A, 400);
    d4 = c + m;

    FillDec(A, 500);
    InsertSort(A, 500);
    d5 = c + m;

    FillInc(A, 100);
    InsertSort(A, 100);
    i1 = c + m;

    FillInc(A, 200);
    InsertSort(A, 200);
    i2 = c + m;

    FillInc(A, 300);
    InsertSort(A, 300);
    i3 = c + m;

    FillInc(A, 400);
    InsertSort(A, 400);
    i4 = c + m;

    FillInc(A, 500);
    InsertSort(A, 500);
    i5 = c + m;

    FillRand(A, 100);
    InsertSort(A, 100);
    r1 = c + m;

    FillRand(A, 200);
    InsertSort(A, 200);
    r2 = c + m;

    FillRand(A, 300);
    InsertSort(A, 300);
    r3 = c + m;

    FillRand(A, 400);
    InsertSort(A, 400);
    r4 = c + m;

    FillRand(A, 500);
    InsertSort(A, 500);
    r5 = c + m;

    printf("--------------------------------------------------------\n");
    printf("|    N    |              c(f) + m(f) of Insert         |\n");
    printf("--------------------------------------------------------\n");
    printf("|/////////|     Dec       |     Rand    |     Inc      |\n");
    printf("--------------------------------------------------------\n");
    printf("|   100   |     %d     |    %d     |     %d      |\n", d1, r1, i1);
    printf("|   200   |     %d     |    %d    |     %d      |\n", d2, r2, i2);
    printf("|   300   |     %d     |    %d    |     %d      |\n", d3, r3, i3);
    printf("|   400   |     %d    |    %d    |     %d     |\n", d4, r4, i4);
    printf("|   500   |     %d    |    %d   |     %d     |\n", d5, r5, i5);
    printf("--------------------------------------------------------");

}*/

/*void GeneralTable()
{
    int A[500];
    int s1, s2, s3, s4, s5;
    int b1, b2, b3, b4, b5;
    int sh1, sh2, sh3, sh4, sh5;
    int i1, i2, i3, i4, i5;

    SelectSort(A, 100);
    s1 = c + m;

    SelectSort(A, 200);
    s2 = c + m;

    SelectSort(A, 300);
    s3 = c + m;

    SelectSort(A, 400);
    s4 = c + m;

    SelectSort(A, 500);
    s5 = c + m;

    BubbleSort(A, 100);
    b1 = c + m;

    BubbleSort(A, 200);
    b2 = c + m;

    BubbleSort(A, 300);
    b3 = c + m;

    BubbleSort(A, 400);
    b4 = c + m;

    BubbleSort(A, 500);
    b5 = c + m;

    ShakerSort(A, 100);
    sh1 = c + m;

    ShakerSort(A, 200);
    sh2 = c + m;

    ShakerSort(A, 300);
    sh3 = c + m;

    ShakerSort(A, 400);
    sh4 = c + m;

    ShakerSort(A, 500);
    sh5 = c + m;

    InsertSort(A, 100);
    i1 = c + m;

    InsertSort(A, 200);
    i2 = c + m;

    InsertSort(A, 300);
    i3 = c + m;

    InsertSort(A, 400);
    i4 = c + m;

    InsertSort(A, 500);
    i5 = c + m;

    printf("-----------------------------------------------------------------------------\n");
    printf("|    N    |                            c(f) + m(f)                          |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|/////////|     Select     |     Bubble    |     Shaker      |    Insert    |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|   100   |     %d       |    %d       |     %d          |     %d      |\n", s1, b1, sh1, i1);
    printf("|   200   |     %d      |    %d      |     %d         |     %d      |\n", s2, b2, sh2, i2);
    printf("|   300   |     %d      |    %d      |     %d         |     %d      |\n", s3, b3, sh3, i3);
    printf("|   400   |     %d      |    %d      |     %d         |     %d     |\n", s4, b4, sh4, i4);
    printf("|   500   |     %d     |    %d     |     %d         |     %d     |\n", s5, b5, sh5, i5);
    printf("-----------------------------------------------------------------------------");

}*/


/*void GeneralBinarySearchTable()
{
    int A[1000];
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;

    FillRand(A, 100);
    BinarySearch1(A, 100, x);
    a1 = c;

    FillRand(A, 200);
    BinarySearch1(A, 200, x);
    a2 = c;

    FillRand(A, 300);
    BinarySearch1(A, 300, x);
    a3 = c;

    FillRand(A, 400);
    BinarySearch1(A, 400, x);
    a4 = c;

    FillRand(A, 500);
    BinarySearch1(A, 500, x);
    a5 = c;

    FillRand(A, 600);
    BinarySearch1(A, 600, x);
    a6 = c;

    FillRand(A, 700);
    BinarySearch1(A, 700, x);
    a7 = c;

    FillRand(A, 800);
    BinarySearch1(A, 800, x);
    a8 = c;

    FillRand(A, 900);
    BinarySearch1(A, 900, x);
    a9 = c;

    FillRand(A, 1000);
    BinarySearch1(A, 1000, x);
    a10 = c;





    FillRand(A, 100);
    BinarySearch2(A, 100, x);
    b1 = c;

    FillRand(A, 200);
    BinarySearch2(A, 200, x);
    b2 = c;

    FillRand(A, 300);
    BinarySearch2(A, 300, x);
    b3 = c;

    FillRand(A, 400);
    BinarySearch2(A, 400, x);
    b4 = c;

    FillRand(A, 500);
    BinarySearch2(A, 500, x);
    b5 = c;

    FillRand(A, 600);
    BinarySearch2(A, 600, x);
    b6 = c;

    FillRand(A, 700);
    BinarySearch2(A, 700, x);
    b7 = c;

    FillRand(A, 800);
    BinarySearch2(A, 800, x);
    b8 = c;

    FillRand(A, 900);
    BinarySearch2(A, 900, x);
    b9 = c;

    FillRand(A, 1000);
    BinarySearch2(A, 1000, x);
    b10 = c;

    printf("________________________________________________________________\n");
    printf("|   N   |       C  (version 1)      |      C  (version 2)       |\n");
    printf("|_______|___________________________|___________________________|\n");
    printf("|  100  |          %d               |           %d               |\n", a1, b1);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  200  |          %d               |           %d               |\n", a2, b2);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  300  |          %d               |           %d              |\n", a3, b3);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  400  |          %d               |           %d              |\n", a4, b4);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  500  |          %d               |           %d              |\n", a5, b5);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  600  |          %d               |           %d              |\n", a6, b6);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  700  |          %d               |           %d              |\n", a7, b7);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  800  |          %d               |           %d              |\n", a8, b8);
    printf("|_______|___________________________|___________________________|\n");
    printf("|  900  |          %d               |           %d              |\n", a9, b9);
    printf("|_______|___________________________|___________________________|\n");
    printf("| 1000  |          %d               |           %d              |\n", a10, b10);
    printf("|_______|___________________________|___________________________|\n");


}*/

/*void HeapTable()
{
    int A[500];
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;
    int i1, i2, i3, i4, i5;
    c = 0, m = 0;
    FillDec(A, 100);
    Heap(A, 0, 99);
    d1 = c + m;

    c = 0, m = 0;
    FillDec(A, 200);
    Heap(A, 0, 199);
    d2 = c + m;

    c = 0, m = 0;
    FillDec(A, 300);
    Heap(A, 0, 299);
    d3 = c + m;

    c = 0, m = 0;
    FillDec(A, 400);
    Heap(A, 0, 399);
    d4 = c + m;

    c = 0, m = 0;
    FillDec(A, 500);
    Heap(A, 0, 499);
    d5 = c + m;

    c = 0, m = 0;
    FillInc(A, 100);
    Heap(A, 0, 99);
    i1 = c + m;
     
    c = 0, m = 0;
    FillInc(A, 200);
    Heap(A, 0, 199);
    i2 = c + m;

    c = 0, m = 0;
    FillInc(A, 300);
    Heap(A, 0, 299);
    i3 = c + m;

    c = 0, m = 0;
    FillInc(A, 400);
    Heap(A, 0, 399);
    i4 = c + m;

    c = 0, m = 0;
    FillInc(A, 500);
    Heap(A, 0, 499);
    i5 = c + m;

    c = 0, m = 0;
    FillRand(A, 100);
    Heap(A, 0, 99);
    r1 = c + m;

    c = 0, m = 0;
    FillRand(A, 200);
    Heap(A, 0, 199);
    r2 = c + m;

    c = 0, m = 0;
    FillRand(A, 300);
    Heap(A, 0, 299);
    r3 = c + m;

    c = 0, m = 0;
    FillRand(A, 400);
    Heap(A, 0, 399);
    r4 = c + m;

    c = 0, m = 0;
    FillRand(A, 500);
    Heap(A, 0, 499);
    r5 = c + m;

    printf("----------------------------------------------------------------------\n");
    printf("|    N    |  c + m teory   |            c(f) + m(f) of Heap          |\n");
    printf("----------------------------------------------------------------------\n");
    printf("|/////////|////////////////|   Dec   |      Inc      |     Rand      |\n");
    printf("----------------------------------------------------------------------\n");
    printf("|   100   |       21       |   %d     |       %d      |       %d      |\n", d1, i1, r1);
    printf("|   200   |       24       |   %d     |       %d      |      %d       |\n", d2, i2, r2);
    printf("|   300   |       26       |   %d     |       %d      |      %d       |\n", d3, i3, r3);
    printf("|   400   |       27       |   %d     |       %d      |       %d     |\n", d4, i4, r4);
    printf("|   500   |       28       |   %d     |       %d      |       %d     |\n", d5, i5, r5);
    printf("---------------------------------------------------------------------");

}*/

/*void HeapSortTable()
{
    int A[500];
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;
    int i1, i2, i3, i4, i5;

    FillDec(A, 100);
    HeapSort(A, 100);
    d1 = c + m;

    FillDec(A, 200);
    HeapSort(A, 200);
    d2 = c + m;

    FillDec(A, 300);
    HeapSort(A, 300);
    d3 = c + m;

    FillDec(A, 400);
    HeapSort(A, 400);
    d4 = c + m;

    FillDec(A, 500);
    HeapSort(A, 500);
    d5 = c + m;

    FillInc(A, 100);
    HeapSort(A, 100);
    i1 = c + m;

    FillInc(A, 200);
    HeapSort(A, 200);
    i2 = c + m;

    FillInc(A, 300);
    HeapSort(A, 300);
    i3 = c + m;

    FillInc(A, 400);
    HeapSort(A, 400);
    i4 = c + m;

    FillInc(A, 500);
    HeapSort(A, 500);
    i5 = c + m;

    FillRand(A, 100);
    HeapSort(A, 100);
    r1 = c + m;

    FillRand(A, 200);
    HeapSort(A, 200);
    r2 = c + m;

    FillRand(A, 300);
    HeapSort(A, 300);
    r3 = c + m;

    FillRand(A, 400);
    HeapSort(A, 400);
    r4 = c + m;

    FillRand(A, 500);
    HeapSort(A, 500);
    r5 = c + m;

    printf("-------------------------------------------------------\n");
    printf("|    N    |           c(f) + m(f) of HeapSort         |\n");
    printf("-------------------------------------------------------\n");
    printf("|/////////|     Dec      |    Rand    |      Inc      |\n");
    printf("-------------------------------------------------------\n");
    printf("|   100   |     %d     |    %d    |     %d      |\n", d1, r1, i1);
    printf("|   200   |     %d     |    %d    |     %d      |\n", d2, r2, i2);
    printf("|   300   |     %d     |    %d    |     %d      |\n", d3, r3, i3);
    printf("|   400   |     %d    |    %d   |     %d     |\n", d4, r4, i4);
    printf("|   500   |     %d    |    %d   |     %d     |\n", d5, r5, i5);
    printf("-------------------------------------------------------");

}*/

void QuickSortTable()
{
    int A[500];
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;
    int i1, i2, i3, i4, i5;

    c = 0, m = 0;
    FillDec(A, 100);
    QuickSortV1(A, 0, 99);
    d1 = c + m;

    c = 0, m = 0;
    FillDec(A, 200);
    QuickSortV1(A, 0, 199);
    d2 = c + m;

    c = 0, m = 0;
    FillDec(A, 300);
    QuickSortV1(A, 0, 299);
    d3 = c + m;

    c = 0, m = 0;
    FillDec(A, 400);
    QuickSortV1(A, 0, 399);
    d4 = c + m;

    c = 0, m = 0;
    FillDec(A, 500);
    QuickSortV1(A, 0, 499);
    d5 = c + m;

    c = 0, m = 0;
    FillInc(A, 100);
    QuickSortV1(A, 0, 99);
    i1 = c + m;

    c = 0, m = 0;
    FillInc(A, 200);
    QuickSortV1(A, 0, 199);
    i2 = c + m;

    c = 0, m = 0;
    FillInc(A, 300);
    QuickSortV1(A, 0, 299);
    i3 = c + m;

    c = 0, m = 0;
    FillInc(A, 400);
    QuickSortV1(A, 0, 399);
    i4 = c + m;

    c = 0, m = 0;
    FillInc(A, 500);
    QuickSortV1(A, 0, 499);
    i5 = c + m;

    c = 0, m = 0;
    FillRand(A, 100);
    QuickSortV1(A, 0, 99);
    r1 = c + m;

    c = 0, m = 0;
    FillRand(A, 200);
    QuickSortV1(A, 0, 199);
    r2 = c + m;

    c = 0, m = 0;
    FillRand(A, 300);
    QuickSortV1(A, 0, 299);
    r3 = c + m;

    c = 0, m = 0;
    FillRand(A, 400);
    QuickSortV1(A, 0, 399);
    r4 = c + m;

    c = 0, m = 0;
    FillRand(A, 500);
    QuickSortV1(A, 0, 499);
    r5 = c + m;

    printf("--------------------------------------------------------\n");
    printf("|    N    |              c(f) + m(f) of Quick          |\n");
    printf("--------------------------------------------------------\n");
    printf("|/////////|     Dec       |     Rand    |     Inc      |\n");
    printf("--------------------------------------------------------\n");
    printf("|   100   |     %d      |    %d     |     %d     |\n", d1, r1, i1);
    printf("|   200   |     %d     |    %d     |     %d    |\n", d2, r2, i2);
    printf("|   300   |     %d     |    %d     |     %d    |\n", d3, r3, i3);
    printf("|   400   |     %d     |    %d     |     %d    |\n", d4, r4, i4);
    printf("|   500   |     %d    |    %d     |     %d   |\n", d5, r5, i5);
    printf("--------------------------------------------------------");

}



int CheckSum(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}

int RunNumber(int A[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int A[n];
    FillRand(A, n);
    printf("FillRand");
    printf("\nElementary array: ");
    Printmas(A, n);
    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));
    QuickSortV1(A, 0, n - 1);
    printf("\n\nFinal array: ");
    Printmas(A, n);



    /*int x = 5;
    int index = BinarySearch2(A, n, x);
    if (index != -1)
    {
        printf("\nKey X = %d found at index %d\n", x, index);
    }
    else
    {
        printf("\nKey X = %d not found\n", x);
    }*/
    


    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));
    printf("\n\n");
    Quick_teor_mc();
    printf("\nc = %d, m = %d\n\n", c, m);
    printf("\n c + m = %d\n\n", c + m);
    printf("\n");



    FillInc(A, n);
    printf("FillInc");
    printf("\nElementary array: ");
    Printmas(A, n);
    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));
    printf("\n\nFinal array: ");
    QuickSortV1(A, 0, n - 1);
    Printmas(A, n);
    printf("\n\n");
    Quick_teor_mc();
    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));

    printf("\nc = %d, m = %d\n\n", c, m);
    printf("\n c + m = %d\n\n", c + m);

    FillDec(A, n);
    printf("FillDec");
    printf("\nElementary array: ");
    Printmas(A, n);
    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));
    printf("\n\nFinal array: ");
    QuickSortV1(A, 0, n - 1);
    Printmas(A, n);
    printf("\nSum numbers: %d", CheckSum(A, n));
    printf("\nSeries: %d", RunNumber(A, n));
    printf("\n\n");
    Quick_teor_mc();
    printf("\nc = %d, m = %d\n\n", c, m);
    printf("\n c + m = %d\n\n", c + m);



    //InsertTable();

    /*printf("\n");
    printf("\nGeneral table:\n");
    printf("\n");
   */
   //GeneralTable();
    //printf("\n");
    //printf("\n Insert and Shell Table:\n");
    //printf("\n");
    //printf("\n Binary Search Table: \n");
    //GeneralBinarySearchTable();
    //InsertShellTable();



    /*printf("Before sorting: \n");
    char type[50];
    struct Abonent contacts[] =
    {
        {"Gulak", "Pavvel", "Alexsandrovich", "Moskovskaya"},
        {"Lee", "Yana", "Igorevna", "Sibirskaya"},
        {"Stepanov", "Alexey", "Konstantinovich", "Mayakovskogo"},
        {"Podkorytova", "Aleksandra", "Valerevna", "Vybornaya"},
        {"Garaev", "Ilya", "Olegovich", "Gogolya"}
    };
    int n = sizeof(contacts) / sizeof(contacts[0]);

    PrintStrict(contacts, n);
    SelectSortAbonent(contacts, n, type);
    printf("\nAfter sorting: \n");
    PrintStrict(contacts, n);
 */
    printf("\n\n");
    QuickSortTable();
    return 0;
}