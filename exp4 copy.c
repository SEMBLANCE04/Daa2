/**
 * @file exp4.c
 * @brief Implementation of the 0/1 Knapsack Problem using Dynamic Programming in C.
 *
 * This program solves the 0/1 Knapsack Problem using a bottom-up dynamic programming approach.
 * The problem involves selecting items with given weights and values to maximize the total value
 * without exceeding the capacity of the knapsack.
 *
 * The program takes input from the user for the number of items, their values and weights, and
 * the capacity of the knapsack. It then calculates and outputs the maximum value that can be
 * obtained.
 *
 * @author Shridharkhare
 * @date YYYY-MM-DD
 */

#include <stdio.h>

/**
 * @brief Finds the maximum of two integers.
 *
 * This function compares two integers and returns the larger of the two.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The maximum of the two integers.
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * @brief Solves the 0/1 Knapsack Problem using Dynamic Programming.
 *
 * This function calculates the maximum value that can be obtained by selecting items
 * such that their total weight does not exceed the given capacity of the knapsack.
 *
 * @param W The capacity of the knapsack.
 * @param wt An array containing the weights of the items.
 * @param val An array containing the values of the items.
 * @param n The number of items.
 * @return The maximum value that can be obtained.
 */
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

/**
 * @brief The main function of the program.
 *
 * This function prompts the user to input the number of items, their values and weights,
 * and the capacity of the knapsack. It then calculates and prints the maximum value that
 * can be obtained using the 0/1 Knapsack Problem solution.
 *
 * @return Returns 0 upon successful execution.
 */
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
