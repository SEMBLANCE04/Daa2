/**
 * @file exp2.c
 * @brief Implementation of the Merge Sort algorithm in C.
 *
 * This program demonstrates the use of the Merge Sort algorithm to sort an array of integers.
 * Merge Sort is a divide-and-conquer algorithm that recursively divides the array into halves,
 * sorts each half, and then merges the sorted halves back together.
 *
 * The program takes input from the user for the length of the array and its elements,
 * sorts the array using Merge Sort, and then prints the sorted array.
 *
 * @author Shridharkhare
 * @date YYYY-MM-DD
 */

#include <math.h>
#include <stdio.h>

/**
 * @brief Merges two sorted subarrays into a single sorted subarray.
 
 * This function takes two sorted subarrays, `left` and `right`, and merges them into a single
 * sorted subarray. The subarrays are part of the main array `a` and are defined by the indices
 * `start`, `q`, and `end`.
 *
 * @param a The array containing the subarrays to be merged.
 * @param start The starting index of the first subarray.
 * @param q The ending index of the first subarray and the midpoint of the two subarrays.
 * @param end The ending index of the second subarray.
 */
void merge(int a[], int start, int q, int end) {
    int k, i, j, n1, n2;

    // Calculate the sizes of the two subarrays
    n1 = q - start + 1;
    n2 = end - q;

    // Create temporary arrays to hold the left and right subarrays
    int left[n1 + 1];
    int right[n2 + 1];

    // Copy elements into the left subarrayBro
    for (i = 0; i < n1; i++) {
        left[i] = a[start + i];
    }

    // Copy elements into the right subarray
    for (j = 0; j < n2; j++) {
        right[j] = a[q + j + 1];
    }

    // Add sentinel values (a very large number) to the end of both subarrays
    left[n1] = 8888888;
    right[n2] = 8888888;

    // Merge the two subarrays back into the main array
    i = 0;
    j = 0;
    for (k = start; k <= end; k++) {
        if (left[i] <= right[j]) {
            a[k] = left[i++];
        } else {
            a[k] = right[j++];
        }
    }
}

/**
 * @brief Recursively sorts an array using the Merge Sort algorithm.
 *
 * This function divides the array into two halves, recursively sorts each half, and then
 * merges the sorted halves using the `merge` function.
 *
 * @param a The array to be sorted.
 * @param start The starting index of the array or subarray to be sorted.
 * @param end The ending index of the array or subarray to be sorted.
 */
void mergesort(int a[], int start, int end) {
    if (start < end) {
        // Find the midpoint of the current subarray
        int q = (start + end) / 2;

        // Recursively sort the left half
        mergesort(a, start, q);

        // Recursively sort the right half
        mergesort(a, q + 1, end);

        // Merge the two sorted halves
        merge(a, start, q, end);
    }
}

/**
 * @brief The main function of the program.
 *
 * This function prompts the user to input the length of the array and its elements,
 * sorts the array using the Merge Sort algorithm, and prints the sorted array.
 *
 * @return Returns 0 upon successful execution.
 */
int main() {
    int i, l;
    int a[1000] = {0};

    // Prompt the user to enter the length of the array
    printf("Enter the length of the array: ");
    scanf("%d", &l);

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array using Merge Sort
    mergesort(a, 0, l - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
}
