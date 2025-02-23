#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const int n = 20;

struct tData
{
    int Data;
};

struct StructList
{
    struct StructList* next;
    struct tData Data;
};

void AddedNewElemToList(struct StructList** head, int dataArray[], int index)
{
    struct StructList* p = (struct StructList*)malloc(sizeof(struct StructList));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->Data.Data = dataArray[index];
    p->next = NULL;
    if (*head == NULL)
    {
		*head = p;
    }
    else
    {
		struct StructList* temp = *head;
        while (temp->next != NULL)
        {
			temp = temp->next;
        }
		temp->next = p;
    }
}

void PrintList(struct StructList* head)
{
    struct StructList* p = head;
    printf(" ");
    while (p != NULL)
    {
        printf("%5d -> ", p->Data.Data);
        p = p->next;
    }
    printf("NULL\n");
}

int Hash(int k, int m)
{
    return k % m;
}


void FillRand(int* a, int n)
{
    for (int i = 0; i < n; i++) 
    {
        int random = 1 + rand() % (100);
        for (int j = 0; j < n; j++) 
        {
            if (random == a[j]) 
            {
                while (random == a[j]) 
                {
                    random = 1 + rand() % (100);
                }
            }
            else continue;
        } 
        a[i] = random;
    }
}

void PrintMas(int* a, int n)
{
    int i;
    printf("\tArray:\n\t");
    for (i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
}

void CheckCollisions(struct StructList** head, int m)
{
    srand(time(0));
    int m_values[] = { 11, 13, 17, 19, 23, 29, 31, 37, 83, 101 };

    printf("\tHash Table Size\t| Original Elements\t| Collisions\n");
    printf("\t------------------------------------------------------------------\n");

    for (int j = 0; j < sizeof(m_values) / sizeof(m_values[0]); j++)
    {
        int m = m_values[j];
        int collisions = 0;

        struct StructList** head = (struct StructList**)malloc(m * sizeof(struct StructList*));
        for (int i = 0; i < m; i++)
        {
            head[i] = NULL; //заполнение нулями 
        }

        int *array = (int*)malloc(n * sizeof(int));
        FillRand(array, n);

        for (int i = 0; i < n; i++)
        {
            int hash_id = Hash(array[i], m);
            if (head[hash_id] != NULL) //проверка на коллизии
            {
                collisions++;
            }
            AddedNewElemToList(&head[hash_id], array, i);
        }

        printf("\t%15d\t|\t%15d\t|\t%10d\n", m, n, collisions);

        free(array);
        free(head);
    }

}

int main()
{
    srand(time(0));
    int m = 11;

    struct StructList** head = (struct StructList**)malloc(m * sizeof(struct StructList*));
    for (int i = 0; i < m; i++)
    {
        head[i] = NULL;
    }

    int *array = (int*)malloc(n * sizeof(int));
    FillRand(array, n);
    PrintMas(array, n);
    printf("\n \tSize of hash-table: %d \n", m);

    for (int i = 0; i < n; i++)
    {
        int hash_id = Hash(array[i], m);
        AddedNewElemToList(&head[hash_id], array, i); 
    }

    for (int i = 0; i < m; i++)
    {
        printf("\n\t i = %2d  ->", i);
        PrintList(head[i]);
    }
    printf("\n\n");
	CheckCollisions(head, m);
    return 0;
}
