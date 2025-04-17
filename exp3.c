#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    int L[n1], R[n2];        // Temporary arrays for left and right subarrays

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left; // Initial indices of subarrays and merged array

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to find the kth smallest element
int findKthSmallest(int arr[], int n, int k) {
    mergeSort(arr, 0, n - 1); // Sort the array using merge sort
    return arr[k - 1];        // Return the kth smallest element
}

int main() {
    int n, k;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the value of k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Validate k
    if (k < 1 || k > n) {
        printf("Invalid value of k. Please enter a value between 1 and %d.\n", n);
        return 1;
    }

    // Find and print the kth smallest element
    int kthSmallest = findKthSmallest(arr, n, k);
    printf("The %dth smallest element is: %d\n", k, kthSmallest);

    return 0;
}


