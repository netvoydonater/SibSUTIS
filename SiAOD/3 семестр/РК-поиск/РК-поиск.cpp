#include <iostream>
#include <string>
#include <vector>
#include<iomanip>

using namespace std;
int countHol;
//C - сравнение
//q - простое число, на которое мы делим (mod q)
void Select_search(const string& haystack, const string& needle, vector<int>& indices, int& C) 
{
    int n = haystack.length();
    int m = needle.length();
    for (int i = 0; i <= n - m; ++i) 
    {
        int j;
        for (j = 0; j < m; ++j) 
        {
            C++;
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == m) 
            indices.push_back(i);
    }
}

int Hash(const string& str, int q)
{
    int h = 0;
    for (char ch : str) 
    {
        h = (h * 256 + ch) % q;
    }
    return h;
}

void Rabin_Karp(const string& haystack, const string& needle, vector<int>& indices, int& C, int q)
{
    int n = haystack.length();
    int m = needle.length();
    if (m > n) return;

    int needle_hash = Hash(needle, q);
    int haystack_hash = Hash(haystack.substr(0, m), q);
    int h = 1;
    for (int i = 0; i < m - 1; ++i) h = (h * 256) % q;

    for (int i = 0; i <= n - m; ++i) 
    {
        if (haystack_hash == needle_hash) 
        {
            bool Flag = true;
            for (int j = 0; j < m; ++j)
            {
                C++;
                if (haystack[i + j] != needle[j])
                {
                    countHol++;
                    Flag = false;
                    break;
                }
            }
            if (Flag) indices.push_back(i);
        }
        if (i < n - m) 
        {
            haystack_hash = (256 * (haystack_hash - haystack[i] * h) + haystack[i + m]) % q;
            if (haystack_hash < 0) 
                haystack_hash += q;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    string needle;
    string text = { "3141592653589793" };
    cout << text << endl;

    cout << "Введите строку для поиска: ";
    getline(cin, needle);
    cout << "\n\n-------------МЕТОД ПРЯМОГО ПОИСКА-------------\n";
    int C = 0;
    vector<int> indices;
    Select_search(text, needle, indices, C);

    if (indices.empty()) 
        cout << "Подстрока не найдена." << endl;
    else
    {
        cout << "Индексы начала вхождений подстроки: ";
        for (int index : indices) 
        {
            cout << index << " ";
        }
        cout << endl;
    }
    cout << "\nКоличество сравнений в методе прямого поиска: " << C;

    cout << "\n\n---------------МЕТОД РАБИНА-КАРПА-----------------\n";
    int C_RK = 0;
    vector<int> index_RK;
    Rabin_Karp(text, needle, index_RK, C_RK, 11);

    if (index_RK.empty()) 
        cout << "Подстрока не найдена." << endl;
    else 
    {
        cout << "Индексы начала вхождений подстроки: ";
        for (int index : index_RK)
        {
            cout << index << " ";
        }
    }
    cout << "\nКоличество сравнений в методе Рабина-Карпа: " << C_RK << "\nХолостные срабатывания 11 : " << countHol << endl;
    C_RK = 0;
    countHol = 0;
    vector<int> index_RK_13;
    Rabin_Karp(text, needle, index_RK_13, C_RK, 13);

    if (index_RK_13.empty())
        cout << "Подстрока не найдена." << endl;
    else 
    {
        cout << "\n\nИндексы начала вхождений подстроки: ";
        for (int index : index_RK_13) 
        {
            cout << index << " ";
        }

    }
    cout << "\nКоличество сравнений в методе Рабина-Карпа: " << C_RK << "\nХолостные срабатывания 13: " << countHol << endl;
    C_RK = 0;
    countHol = 0;
    vector<int> index_RK_17;
    Rabin_Karp(text, needle, index_RK_17, C_RK, 31);

    if (index_RK_17.empty()) {
        cout << "Подстрока не найдена." << endl;
    }
    else 
    {
        cout << "\n\nИндексы начала вхождений подстроки: ";
        for (int index : index_RK_17) 
        {
            cout << index << " ";
        }

    }
    cout << "\nКоличество сравнений в методе Рабина-Карпа: " << C_RK << "\nХолостные срабатывания 17: " << countHol << endl;
    return 0;
}