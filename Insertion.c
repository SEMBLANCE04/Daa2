//Insertion sort
#include <conio.h>
#include <stdio.h>
#include <time.h>
void main() {
    clock_t start_t, end_t;
    double total_t;
    int a[6];
    int i, j, l;
    int key;
    clrscr();
    start_t = clock();
    printf("starting of the program,start_t=%ld\n", start_t);
    printf("Enter length of an array = ");
    scanf("%d", &l);
    printf("Enter elements in an array = \n");
    for (i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }
    for (j = 1; j < l; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
    printf("Sorted array is = ");
    for (i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    end_t = clock();
    printf("\nEnd of the loop, end_t=%ld\n", end_t);
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU:%f\n", total_t);
    getch();
}
