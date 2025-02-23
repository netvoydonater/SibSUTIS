#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <locale>
#include <codecvt>

struct chanceSymbol
{
    wchar_t ch = 0;
    float chance = 0;
};

struct codeHuffman
{
    wchar_t ch = 0;
    float P = 0;
    int L = 0;
    wchar_t* codeword = nullptr;
};
unsigned short int Up(float*& P, unsigned int n, float x) {
    int j = 0;
    for (int i = n - 2; i > 0; i--) {
        if (P[i - 1] < x) {
            P[i] = P[i - 1];
        }
        else {
            j = i;
            break;
        }
    }
    P[j] = x;
    return j;
}

void Down(codeHuffman*& huffman, int n, int j) {

    wchar_t* S = new wchar_t[huffman[j].L + 1];
    for (int i = 0; i < huffman[j].L; i++)
        S[i] = huffman[j].codeword[i];

    int L = huffman[j].L;

    for (int i = j; i <= n - 2; i++) {
        delete[] huffman[i].codeword;
        huffman[i].codeword = new wchar_t[huffman[i + 1].L];
        for (int t = 0; t < huffman[i + 1].L; t++)
            huffman[i].codeword[t] = huffman[i + 1].codeword[t];
        huffman[i].L = huffman[i + 1].L;
    }

    delete[] huffman[n - 1].codeword;
    delete[] huffman[n].codeword;

    huffman[n - 1].L = L + 1;
    huffman[n].L = L + 1;
    huffman[n - 1].codeword = new wchar_t[huffman[n - 1].L];
    huffman[n].codeword = new wchar_t[huffman[n].L];

    for (int i = 0; i < L; i++)
        huffman[n - 1].codeword[i] = huffman[n].codeword[i] = S[i];

    huffman[n - 1].codeword[L] = '0';
    huffman[n].codeword[L] = '1';
}

void HuffmanCode(codeHuffman*& huffman, float*& Pi, int n) {
    if (n == 2) {
        huffman[0].codeword = new wchar_t[1];
        huffman[0].codeword[0] = '0';
        huffman[0].L = 1;
        huffman[1].codeword = new wchar_t[1];
        huffman[1].codeword[0] = '1';
        huffman[1].L = 1;
    }
    else {
        float q = Pi[n - 2] + Pi[n - 1];
        int j = Up(Pi, n, q);
        HuffmanCode(huffman, Pi, n - 1);
        Down(huffman, n - 1, j);
    }
}

codeHuffman* HuffmanCode(chanceSymbol* chanceSymbols, int numSymbols) {
    codeHuffman* huffman = new codeHuffman[numSymbols];
    float* Pi = new float[numSymbols];

    quickSortV2Huff(chanceSymbols, numSymbols - 1, 0, 1, 1);

    for (int i = 0; i < numSymbols; i++) {
        huffman[i].ch = chanceSymbols[i].ch;
        huffman[i].P = Pi[i] = chanceSymbols[i].chance;
    }

    HuffmanCode(huffman, Pi, numSymbols);

    return huffman;
}
