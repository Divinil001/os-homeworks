#include <stdio.h>

void bubblesort(int arr[], size_t size){
    int swapped = 0;
    while(!swapped){
        swapped = 1;
        for (int i = 1; i < size; ++i) {
            if(arr[i] < arr[i-1]){
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                swapped = 0;
            }
        }
    }
}

int main(){
    const int size = 5;
    int array[5] = {3, 5, 1, 4, 2};

    printf("Array before sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    bubblesort(array, size);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
