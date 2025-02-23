//7. P= M! = 1* 2* 3*...*M, M вводится с клавиатуры; (m=5, P=120)
#include <stdio.h>
#include <math.h>
int main() {
    int M;
    long long P = 1; 

    printf("Enter M: ");
    scanf_s("%d", &M);

    if (M >= 0) {
        for (int i = 1; i <= M; i++) {
            P *= i;
        }

        printf("%d! = %lld\n", M, P);
    }
    else {
        printf("Error!\n");
    }

    return 0;
}