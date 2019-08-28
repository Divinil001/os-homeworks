#include <stdio.h>

void swap(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int main() {
    int first, second;

    printf("Please, enter first integer:\n");
    scanf("%d", &first);
    printf("Please, enter second integer:\n");
    scanf("%d", &second);

    printf("Your first integer is %d. Your second integer is %d\n", first, second);
    printf("Swapping...\n");
    swap(&first, &second);
    printf("Now your first integer is %d. Your second integer is %d\n", first, second);
    return 0;
}
