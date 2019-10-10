#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Size of alocated memory in MB
#define SIZE 10

int main(){
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(SIZE * 1024 * 1024), '0', SIZE * 1024 * 1024);
        sleep(1);
    }

    return 0;
}