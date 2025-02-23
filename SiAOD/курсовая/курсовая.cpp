#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <sstream>
bool flag = false;
int CHET = 1;

using namespace std;

struct Record
{
    char full_name[32];
    char street[18];
    unsigned short int house_number;
    unsigned short int apart_number;
    char date[10];
};

struct List
{
    Record data;
    List* next;
    List* Right;
    List* Left;
    List* Equal;
    int Bal;
};

struct line
{
    List* head = nullptr;
    List* tail = nullptr;
};

void free_list(List* head)
{
    List* p = head;
    while (p != NULL)
    {
        List* temp = p;
        p = p->next;
        delete temp;
    }
}

void read_file(List** head)
{
    free_list(*head);
    *head = nullptr;

    FILE* file = nullptr;
    errno_t err = fopen_s(&file, "testBase4.dat", "rb");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    Record temp;
    while (fread(&temp, sizeof(Record), 1, file))
    {
        List* newList = new List;
        newList->data = temp;
        newList->next = *head;
        *head = newList;
    }
    fclose(file);
}

void print_data(List* head)
{
    List* p = head;
    int i = 0;
    while (p != nullptr)
    {
        cout << " " << setw(5) << i + 1 << "|" << " "
            << p->data.full_name << "\t"
            << p->data.street << "\t"
            << p->data.house_number << "\t"
            << p->data.apart_number << "\t"
            << p->data.date << endl;
        p = p->next;
        i++;
        if (i % 20 == 0)
        {
            char ch;
            cout << "\nIf you want to exit, press 0" << endl;
            ch = _getch();
            if (ch == '0') break;
        }
    }
}

void print_data_all(List* head)
{
    List* p = head;
    int i = 0;
    while (p != nullptr)
    {
        cout << " " << setw(5) << i + 1 << "|" << " "
            << p->data.full_name << "\t"
            << p->data.street << "\t"
            << p->data.house_number << "\t"
            << p->data.apart_number << "\t"
            << p->data.date << endl;
        p = p->next;
        i++;
        if (i % 4000 == 0)
        {
            char ch;
            cout << "\nIf you want to exit, press 0" << endl;
            ch = _getch();
            if (ch == '0') break;
        }
    }
}

int compare_records(List* a, List* b)
{
    int cmp_full_name = strcmp(a->data.full_name, b->data.full_name);
    if (cmp_full_name < 0) return true;
    else if (cmp_full_name > 0) return false;

    int cmp_street = strcmp(a->data.street, b->data.street);
    return (cmp_street < 0);
}

void from_list_to_line(List*& person, line& queue)  //engueue добавление в очередь
{
    if (queue.head == nullptr) queue.head = person;
    else queue.tail->next = person;
    queue.tail = person;
    person = person->next;
    queue.tail->next = nullptr;
}

int Split(List*& S, List*& A, List*& B)
{
    A = S;
    B = S->next;
    int n = 1;
    List* k = A;
    List* p = B;
    while (p != nullptr)
    {
        n++;
        k->next = p->next;
        k = p;
        p = p->next;
    }
    return n;
}

void Merge(List*& A, int& q, List*& B, int& r, line& C)
{
    while ((q != 0) && (r != 0))
    {
        if (compare_records(A, B))
        {
            from_list_to_line(A, C);
            q--;
        }
        else
        {
            from_list_to_line(B, C);
            r--;
        }
    }
    while (q > 0)
    {
        from_list_to_line(A, C);
        q--;
    }
    while (r > 0)
    {
        from_list_to_line(B, C);
        r--;
    }
}

void MergeSort(List*& S)
{
    int q = 0, r = 0;
    List* A, * B;
    line C[2];

    int length = Split(S, A, B);
    int p = 1;

    while (p < length)
    {
        for (int i = 0; i < 2; i++)
        {
            C[i].head = nullptr;
            C[i].tail = nullptr;
        }

        int i = 0, m = length;
        while (m > 0)
        {
            if (m >= p) q = p; else q = m;
            m -= q;

            if (m >= p) r = p; else r = m;
            m -= r;

            Merge(A, q, B, r, C[i]);
            i = 1 - i;
        }

        A = C[0].head;
        B = C[1].head;
        p *= 2;
    }

    S = C[0].head;
}

void createIndexArray(List* head, List**& indexArray, int& size)
{
    List* p = head;
    size = 0;
    while (p != nullptr)
    {
        size++;
        p = p->next;
    }

    indexArray = new List * [size];
    p = head;
    for (int i = 0; i < size; i++)
    {
        indexArray[i] = p;
        p = p->next;
    }
}

void binary_searchV2(List** indexArray, int size, char* key)
{
    int L = 0;
    int R = size - 1;
    int found_count = 0;
    while (L < R)
    {
        int m = (L + R) / 2;
        int cmp = strncmp(indexArray[m]->data.full_name, key, 3);
        if (cmp < 0) L = m + 1;
        else R = m;
    }

    if (strncmp(indexArray[R]->data.full_name, key, 3) == 0)
    {
        found_count++;
        cout << found_count << ". "
            << indexArray[R]->data.full_name << " "
            << indexArray[R]->data.street << " "
            << indexArray[R]->data.house_number << " "
            << indexArray[R]->data.apart_number << " "
            << indexArray[R]->data.date << endl;
        int right = R + 1;

        while (right < size && strncmp(indexArray[right]->data.full_name, key, 3) == 0)
        {
            found_count++;
            cout << found_count << ". "
                << indexArray[right]->data.full_name << " "
                << indexArray[right]->data.street << " "
                << indexArray[right]->data.house_number << " "
                << indexArray[right]->data.apart_number << " "
                << indexArray[right]->data.date << endl;
            right++;
        }
    }
    else
    {
        cout << "Element not found" << endl;
    }
    system("pause");
}

bool DBD(Record d, List*& p, bool& VR, bool& HR)
{
    if (p == NULL)
    {
        p = new List;
        p->data = d;
        p->Left = p->Right = p->Equal = NULL;
        p->Bal = 0;
        VR = true;
        return true;
    }
    else if ((strcmp(p->data.street, d.street) > 0) || (strcmp(p->data.street, d.street) == 0 && d.house_number < p->data.house_number))
    {
        if (DBD(d, p->Left, VR, HR))
        {
            if (VR)
            {
                if (p->Bal == 0)
                {
                    List* q = p->Left;
                    p->Left = q->Right;
                    q->Right = p;
                    p = q;
                    q->Bal = 1;
                    VR = false;
                    HR = true;
                }
                else
                {
                    p->Bal = 0;
                    VR = true;
                    HR = false;
                }
            }
            else
                HR = false;
        }
        else
            return false;
    }
    else if ((strcmp(p->data.street, d.street) < 0) || (strcmp(p->data.street, d.street) == 0 && d.house_number > p->data.house_number)) {
        if (DBD(d, p->Right, VR, HR))
        {
            if (VR)
            {
                p->Bal = 1;
                HR = true;
                VR = false;
            }
            else if (HR)
            {
                if (p->Bal == 1)
                {
                    List* q = p->Right;
                    p->Bal = 0;
                    q->Bal = 0;
                    p->Right = q->Left;
                    q->Left = p;
                    p = q;
                    VR = true;
                    HR = false;
                }
                else
                    HR = false;
            }
        }
        else
            return false;
    }
	else 
    {
        List* newEqual = new List;
        newEqual->data = d;
        newEqual->next = nullptr;
        newEqual->Equal = p->Equal;
        p->Equal = newEqual;

        return true;
    }
    return true;
}

void binary_search_all(List** indexArray, int size, char* key, List*& p)
{
    bool VR = true;
    bool HR = true;
    int L = 0;
    int R = size - 1;
    int found_count = 0;
    while (L < R)
    {
        int m = (L + R) / 2;
        int cmp = strncmp(indexArray[m]->data.full_name, key, 3);
        if (cmp < 0) L = m + 1;
        else R = m;
    }

    if (strncmp(indexArray[R]->data.full_name, key, 3) == 0)
    {
        found_count++;
        cout << found_count << ". "
            << indexArray[R]->data.full_name << " "
            << indexArray[R]->data.street << " "
            << indexArray[R]->data.house_number << " "
            << indexArray[R]->data.apart_number << " "
            << indexArray[R]->data.date << endl;
        DBD(indexArray[R]->data, p, VR, HR);
        int right = R + 1;

        while (right < size && strncmp(indexArray[right]->data.full_name, key, 3) == 0)
        {
            found_count++;
            cout << found_count << ". "
                << indexArray[right]->data.full_name << " "
                << indexArray[right]->data.street << " "
                << indexArray[right]->data.house_number << " "
                << indexArray[right]->data.apart_number << " "
                << indexArray[right]->data.date << endl;
            DBD(indexArray[right]->data, p, VR, HR);
            right++;
        }
    }
    else
        cout << "Element not found" << endl;
    system("pause");
}

void TreeRight(List* p, int& i)
{
    if (p != nullptr)
    {
        TreeRight(p->Left, i);
        cout << " " << setw(5) << ++i << "|" << " "
            << p->data.full_name << "\t"
            << p->data.street << "\t"
            << p->data.house_number << "\t"
            << p->data.apart_number << "\t"
            << p->data.date << endl;

        List* EqualNode = p->Equal;
        while (EqualNode != nullptr)
        {
            cout << " " << setw(5) << ++i << "|" << " "
                << EqualNode->data.full_name << "\t"
                << EqualNode->data.street << "\t"
                << EqualNode->data.house_number << "\t"
                << EqualNode->data.apart_number << "\t"
                << EqualNode->data.date << endl;
            EqualNode = EqualNode->Equal;
        }
        TreeRight(p->Right, i);
    }

}

void Search_DBD(List* p, const char* X1, unsigned short int X2, int len)
{
    if (p == nullptr)
        return;
    if ((strncmp(p->data.street, X1, len) == 0) && p->data.house_number == X2) 
    {
        cout << " " << setw(5) << CHET << "|" << " "
            << p->data.full_name << "\t"
            << p->data.street << "\t"
            << p->data.house_number << "\t"
            << p->data.apart_number << "\t"
            << p->data.date << endl;
        bool Eq = false;
		CHET++;

        List* Equal = p->Equal;
        while (Equal != nullptr)
        {
            cout << " " << setw(5) << CHET << "|" << " "
                << Equal->data.full_name << "\t"
                << Equal->data.street << "\t"
                << Equal->data.house_number << "\t"
                << Equal->data.apart_number << "\t"
                << Equal->data.date << endl;
            Equal = Equal->Equal;
			Eq = true;
        }
        flag = true;
        if (Eq) CHET++;
    }

    Search_DBD(p->Left, X1, X2, len);
    Search_DBD(p->Right, X1, X2, len);
}


void Sort_probability(char* A, float* P, int L, int R)
{
    float x = P[(L + R) / 2];
    int i = L;
    int j = R;
    while (i <= j)
    {
        while (P[i] > x)
        {
            i++;
        }
        while (P[j] < x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(A[i], A[j]);
            swap(P[i], P[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        Sort_probability(A, P, L, j);
    if (i < R)
        Sort_probability(A, P, i, R);
}

int Med(float* P, int L, int R) // заменить на алгоритм А2
{
    float SL = 0;

    for (int i = L; i < R; i++)
    {
        SL = SL + P[i];
    }
    float SR = P[R];
    int m = R;
    while (SL >= SR)
    {
        m = m - 1;
        SL = SL - P[m];
        SR = SR + P[m];
    }

    return m;
}

int Algoritm_A2(float* P, int L, int R)
{
    float Summa = 0;
    float sum = 0;
    int i = 0;
    if (L <= R)
    {

        for (i = L; i < R; i++)
        {
            Summa = Summa + P[i];
        }
        for (i = L; i < R; i++)
        {
            if ((sum < Summa / 2) && (sum + P[i] >= Summa / 2))
                break;
            else
                sum = sum + P[i];
        }
    }
    return i;
}

void Fano(float* P, int L, int R, int k, int* Length, int** C)
{
    if (L < R)
    {
        k++;
        int m = Algoritm_A2(P, L, R);

        for (int i = L; i <= R; i++)
        {
            if (i <= m)
            {
                C[i][k] = 0;
                Length[i] = Length[i] + 1;
            }
            else
            {
                C[i][k] = 1;
                Length[i] = Length[i] + 1;
            }
        }

        Fano(P, L, m, k, Length, C);
        Fano(P, m + 1, R, k, Length, C);
    }
}

float CalculateEntropy(float* P, int n)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += P[i] * log2(P[i]);
    }
    return -result;
}

float CalculateAVG_L(int* Length, float* P, int n)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += Length[i] * P[i];
    }
    return result;
}

float checkKraft(int* Length, int n)
{
    float kraftSum = 0;
    for (int i = 0; i < n; i++)
    {
        kraftSum += pow(2, -Length[i]);
    }
    return kraftSum;
}

void printFanoCode(char* symbols, float* P, int* Length, int** C, int n)
{
    cout << "---------------------------------------------------------" << endl;
    cout << "| Number | Symbol | Probability | Length|   Code Word   |" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "| " << setw(6) << i + 1 << " | "
            << setw(6) << symbols[i] << " | "
            << setw(10) << fixed << setprecision(7) << P[i] << setw(4) << " | "
            << setw(5) << Length[i] << " | ";
        for (int j = 0; j < Length[i]; j++)
        {
            cout << C[i][j];
        }
        cout << setw(15 - Length[i]) << " |" << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    float countP = 0.0;
    for (int i = 0; i < n; i++)
    {
        countP += P[i];
    }
    cout << "\nSumma probabilities = " << fixed << setprecision(4) << countP;
}

void printTable(float entropy, float avgLength, float kraftCheck)
{
    float redundancy = avgLength - entropy;

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "|   Kraft   | Entropy | Average lenght | Redundancy |" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "| " << setw(9) << fixed << setprecision(5) << kraftCheck << " | "
        << setw(2) << fixed << setprecision(5) << entropy << " | "
        << setw(10) << fixed << setprecision(5) << avgLength << setw(7) << " | "
        << setw(10) << fixed << setprecision(5) << redundancy << " |" << endl;
    cout << "-----------------------------------------------------" << endl;
}

void CaseFano()
{
    int words[256] = { 0 };
    int totalNums = 0, uniqueSymbols = 0;
    char ch;

    ifstream file("testBase4.dat", ios::binary);

    if (!file.is_open())
    {
        cout << "Error#1. File \"testBase4.dat\" not found!" << endl;
    }

    while (file.read(&ch, sizeof(ch)))
    {
        totalNums++;
        words[(unsigned char)ch]++;
    }
    file.close();

    for (int i = 0; i < 256; i++)
    {
        if (words[i] != 0)
            uniqueSymbols++;
    }

    cout << "Unique symbols: " << uniqueSymbols << endl;
    cout << "Total symbols: " << totalNums << endl;

    float* P = new float[uniqueSymbols];
    char* symbols = new char[uniqueSymbols];
    int* Length = new int[uniqueSymbols];
    int** C = new int* [uniqueSymbols];
    for (int i = 0; i < uniqueSymbols; i++)
    {
        C[i] = new int[256](); // Инициализация нулями
    } // Матрица для кодов, 256 - максимальная длина кодового слова

    int index = 0;
    for (int i = 0; i < 256; i++)
    {
        if (words[i] != 0)
        {
            symbols[index] = (char)i;
            P[index] = (float)words[i] / totalNums;
            Length[index] = 0;
            index++;
        }
    }
    // Сортируем массив вероятностей и символов
    Sort_probability(symbols, P, 0, uniqueSymbols - 1);
    float entropy = CalculateEntropy(P, uniqueSymbols);
    Fano(P, 0, uniqueSymbols - 1, -1, Length, C);
    float avgLength = CalculateAVG_L(Length, P, uniqueSymbols);
    float kraftCheck = checkKraft(Length, uniqueSymbols);

    printFanoCode(symbols, P, Length, C, uniqueSymbols);
    printTable(entropy, avgLength, kraftCheck);
}


int main()
{
    List* records = nullptr;
    List** indexArray = nullptr;
    List* p = nullptr;
    int size = 0;
    char key[4];
    char answer_user;
    bool Flag = true;
    int i = 0;
    int Size = 256;
    char* street = new char[Size];
    unsigned short int house_number;
    int len = 0;
    read_file(&records);
    do
    {
        system("CLS");
        cout << "MENU" << endl
            << "1. Output 20 records\n"
            << "2. Sort the database\n"
            << "3. Output all records\n"
            << "4. Output sorted all records\n"
            << "5. Binary search\n"
            << "6. Binary B-tree by street and house number and search\n"
			<< "7. Fano code\n"
            << endl;
        answer_user = _getch();
        switch (answer_user)
        {
        case '1':
            system("CLS");
            cout << "\t\t\tThe database\n" << endl;
            print_data(records);
            break;

        case '2':
            system("CLS");
            cout << "\t\t\tSorted database\n" << endl;
            MergeSort(records);
            print_data(records);
            break;

        case '3':
            system("CLS");
            cout << "\t\t\tThe full database\n" << endl;
            print_data_all(records);
            break;

        case '4':
            system("CLS");
            cout << "\t\t\tSorted full database\n" << endl;
            MergeSort(records);
            createIndexArray(records, indexArray, size);
            print_data_all(records);
            break;

        case '5':
            system("CLS");
            cout << "Enter the key for search: ";
            MergeSort(records);
            cin.getline(key, 4);
            createIndexArray(records, indexArray, size);
            binary_searchV2(indexArray, size, key);
            break;

        case '6':
            MergeSort(records);
            cout << "Enter the key for search: ";
            cin.getline(key, 4);
            cout << "\n\t\t\t\t\tFound records\n\n";
            
            createIndexArray(records, indexArray, size);
            binary_search_all(indexArray, size, key, p);
            cout << endl << "---------------------------BINARY B-TREE (KEY OF SEARCH: STREET AND HOUSE NUMBER)----------------------------\n" << endl;
            TreeRight(p, i);

          

            cout << "Enter the street for search: ";
            cin.getline(street, Size);
            
            while (street[len] != '\0')
                len++;
			cout << "Enter the house number for search: ";
			cin >> house_number; 
            Search_DBD(p, street, house_number, len);
            CHET = 1;
            if (!flag)
            {
                cout << "No records were found matching the specified criteria.\n";
                flag = false;
            }

            system("pause");
            p = nullptr;
            break;

        case '7':
            CaseFano();
            system("pause");

        }

    } while (Flag);
	free_list(p);

    return 0;
}

