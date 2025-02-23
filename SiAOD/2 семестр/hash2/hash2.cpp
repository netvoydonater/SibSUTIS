#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#define N 20
int collision = 0;
int collision1 = 0;

using namespace std;

void FillRand(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int random = 1 + rand() % 100;
        for (int j = 0; j < n; j++)
        {
            if (random == A[j])
            {
                while (random == A[j])
                {
                    random = 1 + rand() % 100;
                }
            }
            else continue;

        }
        A[i] = random;
    }
}

void PrintMas(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}

int Hash(int key, int m)
{
    return key % m;
}

bool CheckProbs(int d, int m, int key)
{
    if (d > m)
    {
        cout << "Hash-table overload! - " << key << endl;
        return false;
    }
    else
        return true;
}

bool HashLinearAppend(int key, int m, int* hash_table, bool checkGet)
{
    int H_k = Hash(key, m);
    int H1_k = Hash(key, m);
    int proba = 1;
    while (hash_table[H_k] != 0 && proba <= m)
    {
        H_k = Hash((H1_k + proba), m);
        proba++;
        collision++;

    }
    if (checkGet)
    {
        if (!CheckProbs(proba, m - 1, key)) return false;
    }
    else
    {
        if (proba > m - 1) return false;
    }
    hash_table[H_k] = key;
    return true;
}

bool HashQuadAppend(int key, int m, int* hash_table, bool checkGet)
{
    int H_k = Hash(key, m);
    int proba = 1;
    while (hash_table[H_k] != 0 && proba <= m)
    {
        H_k = Hash((H_k + proba), m);
        proba += 2;
        collision1++;
    }
    if (checkGet)
    {
        if (!CheckProbs(proba, m, key)) return false;
    }
    else
    {
        if (proba > m) return false;
    }

    hash_table[H_k] = key;
    return true;
}

void PrintHashTable(int* hash_table, int m)
{
    cout << endl << "---------------------------------------------------------------------------------------------------------" << endl << "Cell number\t|";
    for (int j = 0; j < m; j++)
    {
        cout << j << "\t|";

    }
    cout << endl << "---------------------------------------------------------------------------------------------------------" << endl << "Symbol\t\t|";
    for (int i = 0; i < m; i++)
    {
        cout << hash_table[i] << "\t|";
    }
    cout << endl << "---------------------------------------------------------------------------------------------------------" << endl;
}


void LinearSearch(int key, int m, int* hash_table)
{
    int H_k = Hash(key, m);
    int H1_k = Hash(key, m);
    int proba = 1;
    while (hash_table[H_k] != key && hash_table[H_k] != NULL && proba <= m) {
        H_k = Hash((H1_k + proba), m);
        proba++;
    }
    if (hash_table[H_k] == key) {
        cout << "Element " << key << " found in cell number: " << H_k << endl;
    }
    else {
        cout << "Element " << key << " not found!" << endl;
    }
}

void QuadraticSearch(int key, int m, int* hash_table)
{
    int H_k = Hash(key, m);
    int proba = 1;
    while (hash_table[H_k] != key && hash_table[H_k] != NULL && proba <= m + 1) {
        H_k = Hash((H_k + proba), m);
        proba += 2;
    }
    if (hash_table[H_k] == key)
    {
        cout << "Element " << key << " found in cell number: " << H_k << endl;
    }
    else {
        cout << "Element " << key << " not found!" << endl;
    }
}

void Print(int num)
{
    int a = 1;
    while (num > 9)
    {
        a++;
        num /= 10;
    }
    for (int i = 0; i < 8 - a; i++)
    {
        cout << " ";
    }
}

int main()
{
    srand(time(0));
    int m = 11;
    int* hash_table = new int[m];
    for (int i = 0; i < m; i++)
    {
        hash_table[i] = 0;
    }
    int n;
    cout << "THE ARRAY IS FILLED WITH NUMBERS FROM 1 TO 100. IF THERE IS 0 IN THE HASH TABLE, THIS MEANS THAT THIS CELL IS EMPTY!!!" << endl;
    cout << "Enter the number of elements: "; cin >> n;
    int* keys = new int[n];
    FillRand(keys, n);
    cout << endl << "\nLINEAR PROBS: \n";
    PrintMas(keys, n);
    for (int i = 0; i < n; i++)
    {
        if (!HashLinearAppend(keys[i], m, hash_table, true)) break;

    }
    cout << endl << " Collisions: " << collision << endl;
    PrintHashTable(hash_table, m);

    int* hash_table1 = new int[11];
    for (int i = 0; i < m; i++)
    {
        hash_table1[i] = 0;
    }

    int search_linear_key;
    cout << "Enter the number of elements: "; cin >> search_linear_key;
    LinearSearch(search_linear_key, m, hash_table);

    cout << endl << "\nQUADRATIC PROBS:\n";

    PrintMas(keys, n);
    for (int i = 0; i < n; i++) {
        if (!HashQuadAppend(keys[i], m, hash_table1, true))
            break;
    }
    cout << endl << " Collisions: " << collision1 << endl;
    PrintHashTable(hash_table1, m);

    int search_quadratic_key;
    cout << "Enter an item to search: ";
    cin >> search_quadratic_key;
    QuadraticSearch(search_quadratic_key, m, hash_table1);

    cout << endl << "\t\t\t\tCOLLISIONS TABLE" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Size of hash-table | num of source characters |   Num of collisions    |" << endl;
    cout << "                   |                          |--------------------------" << endl;
    cout << "                   |                          | Lin.probs | Quad.probs |" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    delete[] hash_table;
    int prime_num[] = { 11, 17, 23, 31, 47, 59, 67, 73, 83, 97 };
    int k = 0;
    for (auto i : prime_num)
    {
        collision = 0;
        collision1 = 0;
        int* keyl = new int[N];
        FillRand(keyl, N);
        int* hash_tables = new int[i];
        for (int j = 0; j < i; j++)
        {
            hash_tables[j] = 0;
        }
        cout << "\t   " << i << " \t   |\t\t" << N << "\t      |   ";
        for (int j = 0; j < N; j++)
        {
            if (!HashLinearAppend(keyl[j], i, hash_tables, false)) break;
        }
        cout << collision;
        Print(collision);
        cout << "|    ";
        for (int j = 0; j < n; j++) {
            if (!HashQuadAppend(keyl[j], i, hash_tables, false)) break;
        }
        cout << collision1;
        Print(collision1);
        cout << "|" << endl;
    }

    delete[] hash_table1;
    delete[] keys;


    return 0;
}