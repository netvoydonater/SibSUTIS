//2. Для значений i=1, 2,..,n вычислить число сочетаний из n по i и занести результаты в массив  С = { С1,С2,..,Сn }, используя Ci = n!/ (i!(n - i)!).Число n > 0 ввести с клавиатуры.Полученный массив       вывести на экран.
#include <stdio.h>
int fact(int n) {
    int q = 1;
    for (int i = 2; i <= n; i++) {
        q *= i;
    }
    return q;
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf_s("%d", &n); 
    int C[13];
    for (int i = 0; i < n; i++) {
        C[i] = fact(n) / (fact(i) * fact(n - i));
    }
    printf("C = [");
    for (int i = 0; i < n; i++) {
        printf(" %d ", C[i]);
    }
    printf("]");
    return 0;
}