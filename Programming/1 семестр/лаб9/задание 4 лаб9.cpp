//4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isMagicSquare(int matrix[3][3]) {

    int sums[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    sums[0] = matrix[0][0] + matrix[0][1] + matrix[0][2];
    sums[1] = matrix[1][0] + matrix[1][1] + matrix[1][2];
    sums[2] = matrix[2][0] + matrix[2][1] + matrix[2][2];
    sums[3] = matrix[0][0] + matrix[1][0] + matrix[2][0];
    sums[4] = matrix[0][1] + matrix[1][1] + matrix[2][1];
    sums[5] = matrix[0][2] + matrix[1][2] + matrix[2][2];
    sums[6] = matrix[0][0] + matrix[1][1] + matrix[2][2];
    sums[7] = matrix[0][2] + matrix[1][1] + matrix[2][0];

    
    int i;
    for (i = 1; i < 8; i++) {
        if (sums[i] != sums[0]) {
            return false;
        }
    }

    return true;
}

int main() {
    int matrix[3][3];
    int iterations = 0;

    
    while (true) {
        
        int numbers[9];
        int i;
        for (i = 0; i < 9; i++) {
            numbers[i] = i + 1;
        }

        for (i = 0; i < 9; i++) {
            int randomIndex = rand() % 9;
            int temp = numbers[i];
            numbers[i] = numbers[randomIndex];
            numbers[randomIndex] = temp;
        }

        int row, col;
        int index = 0;
        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                matrix[row][col] = numbers[index++];
            }
        }

        iterations++;

        if (isMagicSquare(matrix)) {
            break;
        }
    }

    printf("Magic square:\n");
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            printf("%2d ", matrix[row][col]);
        }
        printf("\n");
    }
    printf("Generations: %d\n", iterations);

    return 0;
}
