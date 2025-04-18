#include <math.h>
#include <stdio.h>
void merge(int a[], int start, int q, int end) {
    int k, i, j, n1, n2;
    n1 = q - start + 1;
    n2 = end - q;
    int left[n1 + 1];
    int right[n2 + 1];
    for (i = 0; i < n1; i++) {
        left[i] = a[start + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = a[q + j + 1];
    }
    left[n1] = 8888888;
    right[n2] = 8888888;
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
void mergesort(int a[], int start, int end) {
    if (start < end) {
        int q = (start + end) / 2;
        mergesort(a, start, q);
        mergesort(a, q + 1, end);
        merge(a, start, q, end);
    }
}
int main() {
    int i, l;
    int a[1000] = {0};
    printf("Enter the length of the array: ");
    scanf("%d", &l);
    printf("Enter the elements of the array: ");
    for (i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, l - 1);
    printf("Sorted array: ");
    for (i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
}
