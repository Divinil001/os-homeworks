#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter N:\n");
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}