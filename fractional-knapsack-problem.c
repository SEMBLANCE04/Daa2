#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)arr[j].value / arr[j].weight;
            double ratio2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (value, weight): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in knapsack: %.2f\n", maxValue);

    return 0;
}
