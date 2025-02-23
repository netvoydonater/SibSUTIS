#include <stdio.h>
#include <string.h>

struct Abonent 
{
    char surname[50];
    char name[50];
    char patronymic[50];
    char address[30];
};

void PrintStruct(struct Abonent contacts[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s, %s,  %s,  %s\n", contacts[i].surname, contacts[i].name, contacts[i].patronymic, contacts[i].address);
    }
    printf("\n");
}

void IndexSortSurname(struct Abonent contacts[], int Surname[], int size) 
{

    for (int i = 0; i < size - 1; i++) 
    {

        int M = i;

        for (int j = i + 1; j < size; j++)
        {

            if (strcmp(contacts[Surname[j]].surname, contacts[Surname[M]].surname) < 0) M = j;

        }
        if (M != i) 
        {
            int temp = Surname[i];
            Surname[i] = Surname[M];
            Surname[M] = temp;
        }

    }
}

void IndexSortAddress(struct Abonent contacts[], int Address[], int size) 
{

    for (int i = 0; i < size - 1; i++) 
    {

        int M = i;

        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(contacts[Address[j]].address, contacts[Address[M]].address) < 0) M = j;
        }
        if (M != i) 
        {
            int temp = Address[i];
            Address[i] = Address[M];
            Address[M] = temp;
        }

    }
}

int BinarySearchSurname(struct Abonent contacts[], int Surname[], int n, char x[]) //для курсача нужен второй вариант БП!!!!!
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (strcmp(contacts[Surname[mid]].surname, x) == 0) return Surname[mid];
        else if (strcmp(contacts[Surname[mid]].surname, x) < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int BinarySearchAddress(struct Abonent contacts[], int Address[], int n, char x[])
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (strcmp(contacts[Address[mid]].address, x) == 0) return Address[mid];
        else if (strcmp(contacts[Address[mid]].address, x) < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() 
{
    printf("-------INDEXATSIA-------\n\n");
    struct Abonent contacts[] =
    { 
        {"Gulak", "Pavvel", "Alexsandrovich", "Moskovskaya"},
        {"Lee", "Yana", "Igorevna", "Sibirskaya"},
        {"Stepanov", "Alexey", "Konstantinovich", "Mayakovskogo"},
        {"Podkorytova", "Aleksandra", "Valerevna", "Vybornaya"},
        {"Garaev", "Ilya", "Olegovich", "Gogolya"}
    };


    int Surname[] = { 0, 1, 2, 3, 4 };
    int n = sizeof(contacts) / sizeof(contacts[0]);
    PrintStruct(contacts, n);
    printf("Array index:  ");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", i);
    }

    IndexSortSurname(contacts, Surname, n);

    printf("\n\nSorted by surname: \n");
    for (int i = 0; i < n; i++) 
    {
        printf(" % s, % s, % s, %s\n", contacts[Surname[i]].surname, contacts[Surname[i]].name, contacts[Surname[i]].patronymic, contacts[Surname[i]].address);
    }
    printf("\n");

    printf("Index surname: ");
    for (int i : Surname)
        printf("%d  ", i);
    
    //бинарный поиск по фамилии
    char search_surname[] = "Podkorytova";
    int foundIndexSurname = BinarySearchSurname(contacts, Surname, n, search_surname);

    if (foundIndexSurname != -1)
        printf("\nFound contact with surname '%s' at index: %d\n", search_surname, foundIndexSurname);
    else
        printf("\nContact with surname '%s' not found.\n", search_surname);
        

    int Address[] = { 0, 1, 2, 3, 4 };
    IndexSortAddress(contacts, Address, n);
   
    printf("\n\nSorted by address:\n");
    for (int i = 0; i < n; i++) 
    {
        printf(" %s, %s,  %s,  %s\n", contacts[Address[i]].surname, contacts[Address[i]].name, contacts[Address[i]].patronymic, contacts[Address[i]].address);
    }
    printf("\n\nIndex address: ");
    for (int i : Address)
        printf("%d  ", i);
    

    //бинарный поиск по адресу
    char search_address[] = "Sibirskaya";
    int foundIndexAddress = BinarySearchAddress(contacts, Address, n, search_address);

    if (foundIndexAddress != -1)
        printf("\nFound contact with address '%s' at index: %d\n", search_address, foundIndexAddress);
    else
        printf("\nContact with address '%s' not found.\n", search_address);

    return 0;
}
