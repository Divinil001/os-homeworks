#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


void * my_realloc(void * ptr, size_t new_size){
    if (ptr == NULL)
    {
        return malloc(new_size);
    }

    if (new_size == 0)
    {
        free(ptr);
        return ptr;
    }

    void *tmp = malloc(new_size);

    size_t size = malloc_usable_size(ptr);
    memcpy(tmp, ptr, size);

    free(ptr);

    return tmp;
}

int main(){
    // Copied code from the ex3 for testing purpose

	printf("Enter original array size: ");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = (int*)malloc(sizeof(int) * n1);
	int i;
	for(i=0; i<n1; i++){
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = my_realloc(a1, sizeof(int) * n2);

	for (size_t i = n1; i < n2; i++)
	{
		a1[i] = 0;
	}

	for(i=0; i<n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

    return 0;
}