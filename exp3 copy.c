#include <stdio.h>

// Function to merge two sorted subarrays into a single sorted subarray
void merge(int a[], int start, int q, int end) {
    int i, j, k;
    int n1 = q - start + 1;  // Size of the left subarray
    int n2 = end - q;        // Size of the right subarray

    int left[n1 + 1];   // Left subarray with an extra space for sentinel
    int right[n2 + 1];  // Right subarray with an extra space for sentinel

    // Copy elements into the left subarray
    for (i = 0; i < n1; i++) left[i] = a[start + i];
    // Copy elements into the right subarray
    for (j = 0; j < n2; j++) right[j] = a[q + 1 + j];

    // Sentinel values to mark the end of the subarrays
    left[n1] = 8888888;  // A very large value to act as infinity
    right[n2] = 8888888;

    i = 0;  // Index for the left subarray
    j = 0;  // Index for the right subarray
    // Merge the two subarrays back into the original array
    for (k = start; k <= end; k++) {
        if (left[i] <= right[j]) {
            a[k] =
                left[i++];  // Take the smaller element from the left subarray
        } else {
            a[k] =
                right[j++];  // Take the smaller element from the right subarray
        }
    }
}

// Function to perform merge sort on the array
void mergesort(int a[], int start, int end) {
    if (start < end) {
        int q = (start + end) / 2;  // Find the midpoint of the array
        mergesort(a, start, q);     // Recursively sort the left half
        mergesort(a, q + 1, end);   // Recursively sort the right half
        merge(a, start, q, end);    // Merge the two sorted halves
    }
}

// Function to find the kth smallest element in the array
int findKthSmallest(int arr[], int n, int k) {
    mergesort(arr, 0, n - 1);  // Sort the array using merge sort
    return arr[k - 1];  // Return the kth smallest element (1-based index)
}

int main() {
    int n, k;

    // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array of size n

    // Prompt the user to enter the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Prompt the user to enter the value of k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Validate the value of k
    if (k < 1 || k > n) {
        printf("Invalid value of k. Please enter a value between 1 and %d.\n",
               n);
        return 1;  // Exit the program if k is invalid
    }

    // Find the kth smallest element in the array
    int kthSmallest = findKthSmallest(arr, n, k);
    // Print the kth smallest element
    printf("The %dth smallest element is: %d\n", k, kthSmallest);

    return 0;
}
