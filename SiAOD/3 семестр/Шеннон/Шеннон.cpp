#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <locale>
#include <codecvt>

using namespace std;

const int num = 65536;

struct Symbol
{
	wchar_t ch = 0;
	float chance = 0;
};

struct Shannon
{
	wchar_t ch = 0;
	float P = 0;
	float Q = 0;
	unsigned short int L = 0;
	char* code_word = 0;
};

void QuickSortV2(Symbol*& A, int R, int L, unsigned short int field, bool reverse) 
{
    while (L < R)
    {
        float x;
        if (field == 0)
            x = A[L].ch;
        else if (field == 1)
            x = A[L].chance;

        int i = L;
        int j = R;
        while (i <= j) 
        {
            if (field == 0) 
            {
                if (reverse) 
                {
                    while (A[i].ch > x)
                        i++;
                    while (A[j].ch < x)
                        j--;
                }
                else
                {
                    while (A[i].ch < x)
                        i++;
                    while (A[j].ch > x)
                        j--;
                }
            }
            else if (field == 1)
            {
                if (reverse)
                {
                    while (A[i].chance > x)
                        i++;
                    while (A[j].chance < x)
                        j--;
                }
                else 
                {
                    while (A[i].chance < x)
                        i++;
                    while (A[j].chance > x)
                        j--;
                }
            }
            if (i <= j) 
            {
                Symbol temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }
        if (j - L > R - i)
        {
            QuickSortV2(A, R, i, field, reverse);
            R = j;
        }
        else 
        {
            QuickSortV2(A, j, L, field, reverse);
            L = i;
        }
    }
}

Shannon* ShannonCode(Symbol* Symbols, int n)
{
    QuickSortV2(Symbols, n - 1, 0, 1, true);
    Shannon* C = new Shannon[n];

    C[0].ch = Symbols[0].ch;
    C[0].P = Symbols[0].chance;
    C[0].L = ceil(-log2(C[0].P));
    C[0].Q = 0;

    for (int i = 1; i < n; i++)
    {
        C[i].ch = Symbols[i].ch;
        C[i].P = Symbols[i].chance;
        C[i].L = ceil(-log2(C[i].P));
        C[i].Q = C[i - 1].Q + C[i - 1].P;
    }

    for (int i = 0; i < n; i++) 
    {
        float Qtemp = C[i].Q;
        C[i].code_word = new char[C[i].L];
        for (int j = 0; j < C[i].L; j++)
        {
            Qtemp = Qtemp * 2;
            C[i].code_word[j] = (char)(floor(Qtemp) + 48);
            if (Qtemp >= 1) Qtemp = Qtemp - 1;
        }
    }

    return C;
}

float Entropy(Symbol* A, int n)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (A[i].chance * log2(A[i].chance));
    }
    return -result;
}

float AVG_Length(Shannon* A, int n)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += A[i].L * A[i].P;
    }
    return result;
}


void printShannonCode(Shannon* C, int n) 
{
    wcout << L"\nКод Шеннона:" << endl;
    wcout << L"---------------------------------------------------------" << endl;
    wcout << L"|  Символ   | Вероятность |  Длина |   Кодовое слово    |" << endl;
    wcout << L"---------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) 
    {
        wcout << L"| " << setw(6) << C[i].ch
            << L"    | " << setw(10) << fixed << setprecision(4) << C[i].P
            << L"  | " << setw(6) << C[i].L
            << L" | ";
        for (int j = 0; j < C[i].L; j++)
            wcout << C[i].code_word[j];
        wcout << setw(20 - C[i].L) << L" |" << endl;
    }
    float countP = 0.0;
    for (int i = 0; i < n; i++)
        countP += C[i].P;

    wcout << L"---------------------------------------------------------" << endl << endl << L"Сумма вероятностей: " << fixed << setprecision(4) << countP;
}

float Kraft(Shannon* C, int n)
{
    float kraft_sum = 0;
    for (int i = 0; i < n; i++)
    {
        kraft_sum += pow(2, -C[i].L);
    }
	return kraft_sum;
}

void printSummary(float entropy, float avgLength, float kraftCheck)
{
    float redundancy = avgLength - entropy;

    wcout << L"\nРезультаты:" << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
    wcout << L"| Неравество Крафта   | Энтропия исходного текста | Средняя длина кодового слова | Избыточность кода Шеннона |" << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
    wcout << L"| " << setw(20) << kraftCheck << L" | "
        << setw(25) << fixed << setprecision(4) << entropy << L" | "
        << setw(27) << fixed << setprecision(4) << avgLength << L" | "
        << setw(25) << fixed << setprecision(4) << redundancy << L" |" << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
}

int main()
{
    locale::global(locale("ru_RU.UTF-8"));

    wifstream file("onlyletters.txt");
    file.imbue(locale("ru_RU.UTF-8"));

    int n = 0;
    int nUnique = 0;
    unsigned int words[num] = { 0 };

    wchar_t ch;
    wcout << L"\nСимволы из файла onlyletters.txt (отрывок из романа Б.Стокера <<Дракула>>):" << endl;
    while (file.get(ch))
    {
        wcout << ch;
        n++;
        words[(int)ch]++;
    }
    wcout << endl;

    for (int i = 0; i < num; i++)
    {
        if (words[i] != 0)
            nUnique++;
    }

    wcout << L"\nКол-во символов: " << n << "\n"
        << L"Кол-во уникальных символов: " << nUnique << "\n";

    file.close();

    Symbol* Symbols = new Symbol[nUnique];
    int temp = 0;
    for (int i = 0; i < num; i++)
    {
        if (words[i] != 0)
        {
            Symbols[temp].ch = (wchar_t)i;
            Symbols[temp].chance = (float)words[i] / n;
            temp++;
        }
    }

    float entropy = Entropy(Symbols, nUnique);
    Shannon* C = ShannonCode(Symbols, nUnique);
    float AVGLshannon = AVG_Length(C, nUnique);

    printShannonCode(C, nUnique);

    float kraftCheck = Kraft(C, nUnique);
    printSummary(entropy, AVGLshannon, kraftCheck);

    wifstream file1("100.txt");
    file1.imbue(locale("ru_RU.UTF-8"));

    int encodedLength = 0;
    int originalLength = 0;

    wcout << L"\nКодирование файла 100.txt:" << endl;
    while (file1.get(ch))
    {
        for (int i = 0; i < nUnique; i++)
        {
            if (C[i].ch == ch)
            {
                for (int j = 0; j < C[i].L; j++)
                {
                    wcout << C[i].code_word[j];
                }
                wcout << L" ";
                encodedLength += C[i].L;
                originalLength += 8;
                break;
            }
        }
    }
    file1.close();

    float compressionRatio = encodedLength / (float)originalLength; 

    wcout << L"\n\nДлина закодированной послед-ти для файла 100.txt: " << encodedLength;
    wcout << L"\nИсходная длина послед-ти (в битах): " << originalLength;
    wcout << L"\nКоэффициент сжатия данных: " << compressionRatio << endl;
    delete[] Symbols;
    for (int i = 0; i < nUnique; i++)
    {
        delete[] C[i].code_word;
    }
    delete[] C;

    return 0;
}

