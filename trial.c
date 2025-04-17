void merge(int array[], int start, int mid, int end){
    int n1, n2, i, j, k;

    n1 = mid - start + 1;
    n2 = end - mid;

    int left[n1 + 1];
    int right[n2 + 1];

    for(i=0;i<n1;i++){
        left[i] = array[start + i];
    }

    for(j=0;j<n2;j++){
        right[j] = array[mid + j + 1];
    }

    left[n1] = 8888888;
    right[n2] = 8888888;

    i = 0;
    j = 0;

    for(k=start;k<=end;k++){
        if(left[i] <= right[j]){
            array[k] = left[i++];
        } else {
            array[k] = right[j++];
        }
    }
    
}

void mergerSort(int array[], int start, int end){
    int mid = (start + end) / 2;

    if(start < end){
        mergerSort(array, start, mid);
        mergerSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void main(){
    int i, l;
    int array[1000] = {0};

    printf("Enter the length of the array: ");
    scanf("%d", &l);

    printf("Enter the elements of the array: ");

    for(i=0;i<l;i++){
        scanf("%d", &array[i]);
    }

    mergeSort(array, 0, l - 1);

    for(i=0;i<l;i++){
        printf("%d ", array[i]);
    }
}