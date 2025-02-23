#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <locale>
#include <codecvt>

using namespace std;

const int num = 65536;


void Sort_probability(wchar_t* A, float* P, int L, int R)
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

int Med(float* P, int L, int R) {
    float SL = 0;


    for (int i = L; i < R; i++) {
        SL = SL + P[i];
    }
    float SR = P[R];
    int m = R;
    while (SL >= SR) {
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

void Fano(float* P, int L, int R, int k, int* Length, int** C, bool Flag) {
    if (L < R) {
        k++;
        int m;
        if (Flag)
            m = Med(P, L, R);
        else
            m = Algoritm_A2(P, L, R);

        for (int i = L; i <= R; i++) {
            if (i <= m)
            {
                C[i][k] = 0;
                Length[i] = Length[i] + 1;
            }
            else {
                C[i][k] = 1;
                Length[i] = Length[i] + 1;
            }

        }

        Fano(P, L, m, k, Length, C, Flag);
        Fano(P, m + 1, R, k, Length, C, Flag);
    }
}

float CalculateEntropy(float* P, int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += P[i] * log2(P[i]);
    }
    return -result;
}

float CalculateAVG_L(int* Length, float* P, int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += Length[i] * P[i];
    }
    return result;
}

float checkKraft(int* Length, int n) {
    float kraftSum = 0;
    for (int i = 0; i < n; i++) {
        kraftSum += pow(2, -Length[i]);
    }
    return kraftSum;
}

void printFanoCode(wchar_t* symbols, float* P, int* Length, int** C, int n) {
    wcout << L"---------------------------------------------------------" << endl;
    wcout << L"| Номер | Символ | Вероятность | Длина | Кодовое слово   |" << endl;
    wcout << L"---------------------------------------------------------" << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        wcout << L"| " << setw(3) << ++count << setw(4) << " |" << setw(5) << symbols[i] << setw(5)
            << L" | " << setw(8) << fixed << setprecision(4) << P[i] << setw(6)
            << L" | " << setw(3) << Length[i] << setw(5)
            << L" | ";
        for (int j = 0; j < Length[i]; j++)
            wcout << C[i][j];
        wcout << setw(17 - Length[i]) << L" |" << endl;
    }
    float countP = 0.0;
    for (int i = 0; i < n; i++)
    {
        countP += P[i];
    }
    wcout << L"---------------------------------------------------------" << endl << endl << L"Сумма вероятностей: " << fixed << setprecision(4) << countP;

}

void printTable2(float entropy, float avgLength, float kraftCheck) {
    float redundancy = avgLength - entropy;

    wcout << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
    wcout << L"| Неравенство Крафта   | Энтропия исходного текста | Средняя длина кодового слова | Избыточность кода   Фано   |" << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
    wcout << L"| " << setw(20) << kraftCheck << L" | "
        << setw(25) << fixed << setprecision(4) << entropy << L" | "
        << setw(27) << fixed << setprecision(4) << avgLength << L" | "
        << setw(25) << fixed << setprecision(4) << redundancy << L" |" << endl;
    wcout << L"---------------------------------------------------------------------------------------------------------------" << endl;
}


int main() {

    locale::global(locale("ru_RU.UTF-8"));
    wifstream file("text.txt");
    file.imbue(locale("ru_RU.UTF-8"));

    int n = 0;
    int Unique_Element = 0;
    unsigned int words[num] = { 0 };

    wchar_t ch;
    wcout << L"\nСимволы из файла:" << endl;
    while (file.get(ch)) {
        wcout << ch;
        n++;
        words[(int)ch]++;
    }
    wcout << endl;

    for (int i = 0; i < num; i++) {
        if (words[i] != 0)
            Unique_Element++;
    }

    wcout << L"\nКол-во символов: " << n << "\n" << L"Кол-во уникальных символов: " << Unique_Element << "\n";

    file.close();

    wchar_t* Symbols = new wchar_t[Unique_Element];
    float* P = new float[Unique_Element];
    int* Length = new int[Unique_Element];
    int** C = new int* [Unique_Element];
    for (int i = 0; i < Unique_Element; i++) {
        C[i] = new int[num](); // Инициализация нулями
    }
    int index = 0;
    for (int i = 0; i < num; i++) {
        if (words[i] != 0) {
            Symbols[index] = (wchar_t)i;
            P[index] = (float)words[i] / n;
            Length[index] = 0;
            index++;
        }
    }

    Sort_probability(Symbols, P, 0, Unique_Element - 1);
    float entropy = CalculateEntropy(P, Unique_Element);
    Fano(P, 0, Unique_Element - 1, -1, Length, C, true);
    float avgLength = CalculateAVG_L(Length, P, Unique_Element);
    float kraftCheck = checkKraft(Length, Unique_Element);

    printFanoCode(Symbols, P, Length, C, Unique_Element);
    printTable2(entropy, avgLength, kraftCheck);


    wchar_t* SymbolsA2 = new wchar_t[Unique_Element];
    float* P_A2 = new float[Unique_Element];
    int* Length_A2 = new int[Unique_Element];
    int** C_A2 = new int* [Unique_Element];
    for (int i = 0; i < Unique_Element; i++) {
        C_A2[i] = new int[num](); // Инициализация нулями
    }
    index = 0;
    for (int i = 0; i < num; i++) {
        if (words[i] != 0) {
            SymbolsA2[index] = (wchar_t)i;
            P_A2[index] = (float)words[i] / n;
            Length_A2[index] = 0;
            index++;
        }
    }
    Sort_probability(SymbolsA2, P_A2, 0, Unique_Element - 1);
    float entropyA2 = CalculateEntropy(P_A2, Unique_Element);
    Fano(P_A2, 0, Unique_Element - 1, -1, Length_A2, C_A2, false);
    float AVG_L_A2 = CalculateAVG_L(Length_A2, P_A2, Unique_Element);
    wcout << L"\nКод Фано с алгоритмом А2:" << endl;
    float kraftCheckA2 = checkKraft(Length_A2, Unique_Element);
    printFanoCode(SymbolsA2, P_A2, Length_A2, C_A2, Unique_Element);
    printTable2(entropyA2, AVG_L_A2, kraftCheckA2);

    delete[] P;
    delete[] Length;
    delete[] Symbols;
    for (int i = 0; i < Unique_Element; i++) {
        delete[] C[i];
    }
    delete[] C;

    delete[] P_A2;
    delete[] SymbolsA2;
    delete[] Length_A2;
    for (int i = 0; i < Unique_Element; i++) {
        delete[] C_A2[i];
    }
    delete[] C_A2;
    return 0;
}
