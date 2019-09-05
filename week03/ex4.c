#include <stdlib.h>
#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high; ++j) {
        if(arr[j] < pivot){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    return i;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}


int main(){
    int array[6] = {3, 1, 4, 2, 1, 5};
    const int size = 6;

    printf("Array before sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    quicksort(array, 0, size-1);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
