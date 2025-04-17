#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int x[100];  // Array to store queen positions

void printBoard(int n) {
    int i, j;
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i] == j)
                printf(" Q ");  // Place queen
            else
                printf(" . ");  // Empty space
        }
        printf("\n");
    }
}

int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        if (x[j] == i ||
            abs(x[j] - i) == abs(j - k))  // Check column and diagonals
            return 0;
    }
    return 1;
}

void NQueen(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {  // Try placing queen in each row
        if (place(k, i)) {      // Check if position is safe
            x[k] = i;           // Place queen
            if (k == n)         // If all queens are placed, print solution
                printBoard(n);
            else
                NQueen(k + 1, n);  // Recur to place next queen
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("N should be greater than or equal to 1.\n");
        return 1;
    }

    NQueen(1, n);  // Start placing queens from row 1
    return 0;
}