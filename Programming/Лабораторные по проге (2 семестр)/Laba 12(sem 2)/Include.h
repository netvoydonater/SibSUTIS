#pragma once
#ifndef SORTING_H 
#define SORTING_H 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;

void Base() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
}

int RandomInt(int a, int b) {
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}

void FillInt(int* Array, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        Array[i] = RandomInt(a, b);
    }
    cout << endl;
}

void FillFloat(double* Array, int size, double a, double b) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++) {
        Array[i] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
    }
    cout << endl;
}

void PrintIntArray(int* Array, int size) {
    for (int i = 0; i < size; i++) {
        cout << Array[i] << '\t';
    }
    cout << endl;
}

void PrintFloatArray(double* Array, int size) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << Array[i] << '\t';
    }
    cout << endl;
}

template <typename T> void BubbleSort(T* Array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Array[j] > Array[j + 1]) {
                swap(Array[j], Array[j + 1]);
            }
        }
    }
}

template <typename T> void SelectSort(T* Array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int MinIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (Array[j] < Array[MinIndex]) {
                MinIndex = j;
            }
        }
        swap(Array[i], Array[MinIndex]);
    }
}

template <typename T> void InsertSort(T* Array, int size) {
    for (int i = 1; i < size; i++) {
        T key = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
}

template <typename T> double timer(void (*tip_sort)(T*, int), T* Array, int size) {
    auto start = chrono::high_resolution_clock::now();
    tip_sort(Array, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

#endif
