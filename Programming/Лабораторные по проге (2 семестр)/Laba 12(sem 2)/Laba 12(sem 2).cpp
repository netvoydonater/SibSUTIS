#include "Include.h"

int main() {
    Base();

    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    vector<int> IntArray(n);
    vector<double> FloatArray(n);
    FillInt(IntArray.data(), n, -100, 100);
    FillFloat(FloatArray.data(), n, -100.0, 100.0);
    PrintIntArray(IntArray.data(), n);
    PrintFloatArray(FloatArray.data(), n);
    double FirstIntTime = timer(InsertSort, IntArray.data(), n);
    double FirstFloatTime = timer(InsertSort, FloatArray.data(), n);
    double SecondIntTime = timer(BubbleSort, IntArray.data(), n);
    double SecondFloatTime = timer(BubbleSort, FloatArray.data(), n);
    double ThirdIntTime = timer(SelectSort, IntArray.data(), n);
    double ThirdFloatTime = timer(SelectSort, FloatArray.data(), n);
    PrintIntArray(IntArray.data(), n);
    PrintFloatArray(FloatArray.data(), n);
    cout << "Время int значений InsertSort: " << fixed << setprecision(7) << FirstIntTime << endl;
    cout << "Время float значений InsertSort: " << fixed << setprecision(7) << FirstFloatTime << endl;
    cout << "Время int значений BubbleSort: " << fixed << setprecision(7) << SecondIntTime << endl;
    cout << "Время float значений BubbleSort: " << fixed << setprecision(7) << SecondFloatTime << endl;
    cout << "Время int значений SelectSort: " << fixed << setprecision(7) << ThirdIntTime << endl;
    cout << "Время float значений SelectSort: " << fixed << setprecision(7) << ThirdFloatTime << endl;
    return 0;
}
