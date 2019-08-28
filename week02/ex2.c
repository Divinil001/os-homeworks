#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 512

int main() {
    char string[BUFFER_SIZE];

    printf("Enter your string:\n");
    fgets(string, sizeof(string), stdin);

    printf("Your reversed string:\n");
    int len = strlen(string);
    for (int i = len-2; i >= 0; i--) {
        putc(string[i], stdout);
    }
    printf("\n");

    return 0;
}
