#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack Problem using Dynamic Programming
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];  // DP Table

    // Build table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0; // Base case: No item or zero capacity
            else if (wt[i - 1] <= w) // If the item can fit in the knapsack
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w]; // Exclude the item
        }
    }
    return K[n][W]; // Maximum value that can be stored
}
// Main function
int main() {
    int i, n, W;
    int val[20], wt[20]; // Arrays to store values and weights

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input values and weights of items
    printf("Enter value and weight of items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &val[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &wt[i]);
    }

    // Input capacity of knapsack
    printf("Enter size of knapsack: ");
    scanf("%d", &W);
    // Output the maximum value that can be obtained
    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));
    return 0;
}
