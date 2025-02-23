#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
const int n = 100;
int M;

struct tLE16
{
	tLE16* next;
	union {
		short int data;
		unsigned char Digit[sizeof(data)];
	};
};

struct tLE32
{
	tLE32* next;
	union {
		int data;
		unsigned char Digit[sizeof(data)];
	};
};

struct Queue16
{
	tLE16* head16;
	tLE16* tail16;
};

struct Queue32
{
	tLE32* head32;
	tLE32* tail32;
};

void QueueFillInc16(int n, tLE16* (&head16), tLE16* (&tail16))
{
    int i = 1;
    tLE16* p;
    head16 = tail16 = (struct tLE16*)malloc(sizeof(struct tLE16));
    head16->next = tail16->next = 0;
    tail16->data = i;
    i++;
    while (i <= n)
    {
        p = (struct tLE16*)malloc(sizeof(struct tLE16));
        p->data = i;
        tail16->next = p;
        tail16 = p;
        i++;

    }
    tail16->next = 0;
}

void QueueFillDec16(int n, tLE16* (&head16), tLE16* (&tail16))
{
    int i = n;
    tLE16* p;
    head16 = tail16 = (struct tLE16*)malloc(sizeof(struct tLE16));
    head16->next = tail16->next = 0;
    tail16->data = i;
    i--;
    while (i > 0)
    {
        p = (struct tLE16*)malloc(sizeof(struct tLE16));
        p->data = i;
        tail16->next = p;
        tail16 = p;
        i--;

    }
    tail16->next = 0;
}

void QueueFillRand16(int n, tLE16* (&head16), tLE16* (&tail16))
{
    srand(time(NULL));
    int i = 1;
    tLE16* p;
    head16 = tail16 = (struct tLE16*)malloc(sizeof(struct tLE16));
    head16->next = tail16->next = 0;
    tail16->data = rand() % (n * 2);
    i++;
    while (i <= n)
    {
        p = (struct tLE16*)malloc(sizeof(struct tLE16));
        p->data = rand() % (n * 2);
        tail16->next = p;
        tail16 = p;
        i++;

    }
    tail16->next = 0;
}


void QueueFillInc32(int n, tLE32* (&head32), tLE32* (&tail32))
{
    int i = 1;
    tLE32* p;
    head32 = tail32 = (struct tLE32*)malloc(sizeof(struct tLE32));
    head32->next = tail32->next = 0;
    tail32->data = i;
    i++;
    while (i <= n)
    {
        p = (struct tLE32*)malloc(sizeof(struct tLE32));
        p->data = i;
        tail32->next = p;
        tail32 = p;
        i++;

    }
    tail32->next = 0;
}

void QueueFillDec32(int n, tLE32* (&head32), tLE32* (&tail32))
{
    int i = n;
    tLE32* p;
    head32 = tail32 = (struct tLE32*)malloc(sizeof(struct tLE32));
    head32->next = tail32->next = 0;
    tail32->data = i;
    i--;
    while (i > 0)
    {
        p = (struct tLE32*)malloc(sizeof(struct tLE32));
        p->data = i;
        tail32->next = p;
        tail32 = p;
        i--;

    }
    tail32->next = 0;
}

void QueueFillRand32(int n, tLE32* (&head32), tLE32* (&tail32))
{
    srand(time(NULL));
    int i = 1;
    tLE32* p;
    head32 = tail32 = (struct tLE32*)malloc(sizeof(struct tLE32));
    head32->next = tail32->next = 0;
    tail32->data = rand() % (n * 2);
    i++;
    while (i <= n)
    {
        p = (struct tLE32*)malloc(sizeof(struct tLE32));
        p->data = rand() % (n * 2);
        tail32->next = p;
        tail32 = p;
        i++;

    }
    tail32->next = 0;
}


int CheckSum16(tLE16* head16)
{
    tLE16* p;
    int sum = 0;
    for (p = head16; p; p = p->next)
    {
        sum += p->data;
    }
    return sum;
}

int RunNumber16(tLE16* head16)
{
    int sequence = 1;
    tLE16* p;
    for (p = head16; p->next; p = p->next)
    {
        if (p->data > p->next->data)
            sequence++;
    }
    return sequence;
}

int CheckSum32(tLE32* head32)
{
    tLE32* p;
    int sum = 0;
    for (p = head32; p; p = p->next)
    {
        sum += p->data;
    }
    return sum;
}

int RunNumber32(tLE32* head32)
{
    int sequence = 1;
    tLE32* p;
    for (p = head32; p->next; p = p->next)
    {
        if (p->data > p->next->data)
            sequence++;
    }
    return sequence;
}

void PrintList16(tLE16* head16, tLE16* tail16)
{
    struct tLE16* p;
    for (p = head16; p; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void PrintList32(tLE32* head32, tLE32* tail32)
{
    struct tLE32* p;
    for (p = head32; p; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void DigitalSort16(tLE16* (&S), tLE16* (&tail16), int& M, int dec = 0) 
{
    M = 0;
    int KDI[2] = { 1, 0 }; 
    int L = 2;
    tLE16* temp; 
    Queue16 q[256]; 
    tLE16* p; 
    unsigned char d; 
    int k; 

    for (int j = L - 1; j >= 0; j--) 
    {
        for (int i = 0; i < 256; i++) 
        {
            q[i].tail16 = (tLE16*)&(q[i].head16); 
        }
        p = S;  
        k = KDI[j];
        while (p != NULL)  
        {
            M++;
            d = p->Digit[k];
            q[d].tail16->next = p;
            q[d].tail16 = p;
            p = p->next;
        }
        temp = p = (tLE16*)&S;

        int i = 0;
        int sign = 1;
        if (dec == 1) 
        {
            i = 255;
            sign = -1;
        }

        while ((i > -1) && (i < 256)) 
        {
            if (q[i].tail16 != (tLE16*)&(q[i].head16)) 
            {
                M++;
                p->next = q[i].head16;
                p = q[i].tail16;
            }
            i += sign;
        }

        p->next = NULL;
        S = temp->next;
    }
    return;
}

void DigitalSort32(tLE32* (&S), tLE32* (&tail), int& M, int dec = 0) 
{
    M = 0;
    int KDI[4] = { 3, 2, 1, 0 };
    int L = 4;
    tLE32* temp;
    Queue32 q[256];
    tLE32* p;
    unsigned char d;
    int k;

    for (int j = L - 1; j >= 0; j--) 
    {
        for (int i = 0; i <= 255; i++) 
        {
            q[i].tail32 = (tLE32*)&(q[i].head32);
        }
        p = S;
        k = KDI[j];
        while (p != NULL) 
        {
            M++;
            d = p->Digit[k];
            q[d].tail32->next = p;
            q[d].tail32 = p;
            p = p->next;
        }
        temp = p = (tLE32*)&S;

        int i = 0;
        int sign = 1;
        if (dec == 1) 
        {
            i = 255;
            sign = -1;
        }

        while ((i > -1) && (i < 256)) 
        {
            if (q[i].tail32 != (tLE32*)&(q[i].head32))  
            {
                M++;
                p->next = q[i].head32;
                p = q[i].tail32;
            }
            i += sign;
        }

        p->next = NULL;
        S = temp->next;
    }
    return;
}


void DigitalSort_T_teor_16()
{
    int M_teor = 2 * (n + 256);
    printf("\nM(teor) = %d\n", M_teor);
}

void DigitalSort_T_teor_32()
{
    int M_teor = 4 * (n + 256);
    printf("\nM(teor) = %d\n", M_teor);
}

void DigitalSortTable16()
{
    int A[500];
    int i1, i2, i3, i4, i5;
    int r1, r2, r3, r4, r5;
    int d1, d2, d3, d4, d5;

    tLE16* head16 = NULL, * tail16 = NULL;
    tLE32* head32 = NULL, * tail32 = NULL;

    M = 0;
    QueueFillInc16(100, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    i1 = M;

    M = 0;
    QueueFillInc16(200, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    i2 = M;

    M = 0;
    QueueFillInc16(300, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    i3 = M;

    M = 0;
    QueueFillInc16(400, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    i4 = M;

    M = 0;
    QueueFillInc16(500, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    i5 = M;

    M = 0;
    QueueFillDec16(100, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    d1 = M;

    M = 0;
    QueueFillDec16(200, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    d2 = M;

    M = 0;
    QueueFillDec16(300, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    d3 = M;

    M = 0;
    QueueFillDec16(400, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    d4 = M;

    M = 0;
    QueueFillDec16(500, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    d5 = M;

    M = 0;
    QueueFillRand16(100, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    r1 = M;

    M = 0;
    QueueFillRand16(200, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    r2 = M;

    M = 0;
    QueueFillRand16(300, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    r3 = M;

    M = 0;
    QueueFillRand16(400, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    r4 = M;

    M = 0;
    QueueFillRand16(500, head16, tail16);
    DigitalSort16(head16, tail16, M, 0);
    r5 = M;




    printf("-----------------------------------------------------------------------------\n");
    printf("|    N    |                               M of Digital                      |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|/////////|       teor        |      Dec      |      Inc     |     Rand     |\n");
    printf("----------------------------------------------------------------------------\n");
    printf("|   100   |       712        |      %d      |     %d      |     %d      |\n", d1, i1, r1);
    printf("|   200   |       912        |      %d      |     %d      |     %d      |\n", d2, i2, r2);
    printf("|   300   |      1112        |      %d      |     %d      |     %d      |\n", d3, i3, r3);
    printf("|   400   |      1312        |      %d     |     %d     |     %d     |\n", d4, i4, r4);
    printf("|   500   |      1512        |      %d     |     %d     |     %d     |\n", d5, i5, r5);
    printf("----------------------------------------------------------------------------");
}

int main()
{
    tLE16* head16 = NULL, * tail16 = NULL;
    tLE32* head32 = NULL, * tail32 = NULL;
    printf("16: \n\n");
    printf("FillInc: \n");
    QueueFillInc16(n, head16, tail16);
    printf("\nElementary list: \n");
    PrintList16(head16, tail16);
    printf("\nSum numbers: %d", CheckSum16(head16));
    printf("\nSeries: %d", RunNumber16(head16));
    DigitalSort16(head16, tail16, M, 0);
    printf("\nFinal list: \n");
    PrintList16(head16, tail16);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_16();

    printf("\n\n");

    printf("FillDec: \n");
    QueueFillDec16(n, head16, tail16);
    printf("\nElementary list: \n");
    PrintList16(head16, tail16);
    printf("\nSum numbers: %d", CheckSum16(head16));
    printf("\nSeries: %d", RunNumber16(head16));
    DigitalSort16(head16, tail16, M, 0);
    printf("\nFinal list: \n");
    PrintList16(head16, tail16);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_16();

    printf("FillRand: \n");
    QueueFillRand16(n, head16, tail16);
    printf("\nElementary list: \n");
    PrintList16(head16, tail16);
    printf("\nSum numbers: %d", CheckSum16(head16));
    printf("\nSeries: %d", RunNumber16(head16));
    DigitalSort16(head16, tail16, M, 0);
    printf("\nFinal list: \n");
    PrintList16(head16, tail16);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_16();

    printf("\n\n\n");

    printf("32: \n\n");
    printf("FillInc: \n");
    QueueFillInc32(n, head32, tail32);
    printf("\nElementary list: \n");
    PrintList32(head32, tail32);
    printf("\nSum numbers: %d", CheckSum32(head32));
    printf("\nSeries: %d", RunNumber16(head16));
    DigitalSort32(head32, tail32, M, 0);
    printf("\nFinal list: \n");
    PrintList32(head32, tail32);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_32();

    printf("\n\n");

    printf("FillDec: \n");
    QueueFillDec32(n, head32, tail32);
    printf("\nElementary list: \n");
    PrintList32(head32, tail32);
    printf("\nSum numbers: %d", CheckSum32(head32));
    printf("\nSeries: %d", RunNumber32(head32));
    DigitalSort32(head32, tail32, M, 0);
    printf("\nFinal list: \n");
    PrintList32(head32, tail32);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_32();

    printf("FillRand: \n");
    QueueFillRand32(n, head32, tail32);
    printf("\nElementary list: \n");
    PrintList32(head32, tail32);
    printf("\nSum numbers: %d", CheckSum32(head32));
    printf("\nSeries: %d", RunNumber32(head32));
    DigitalSort32(head32, tail32, M, 0);
    printf("\nFinal list: \n");
    PrintList32(head32, tail32);
    printf("\nM = %d\n", M);
    DigitalSort_T_teor_32();

    DigitalSortTable16();
    
    return 0;
}

