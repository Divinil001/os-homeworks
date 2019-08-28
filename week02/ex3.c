#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

void isosceles_triangle(int n) {
    char string[BUFFER_SIZE];

    for (int i = 0; i < 2 * n; ++i) {
        string[i] = ' ';
    }
    string[2*n-1] = '\0';
    string[n-1] = '*';

    for (int i = 1; i < n; ++i) {
        printf("%s\n", string);
        string[n-1-i] = '*';
        string[n-1+i] = '*';
    }
    printf("%s\n", string);
}

void square(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            putc('*', stdout);
        }
        printf("\n");
    }
}

void right_triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            putc('*', stdout);
        }
        printf("\n");
    }
}

void rotated_triangle(int n) {
    char string[BUFFER_SIZE];
    for (int i = 0; i < n; ++i) {
        string[i] = ' ';
    }
    string[n] = '\0';

    for (int i = 0; i < n; ++i) {
        string[i] = '*';
        printf("%s\n", string);
    }

    for (int i = n-1; i > 0 ; --i) {
        string[i] = '\0';
        printf("%s\n", string);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Please, provide valid arguments\n");
        return 0;
    }

    char *nstr = argv[1];
    char *typestr = argv[2];
    int n, type;
    sscanf(nstr, "%d", &n);
    sscanf(typestr, "%d", &type);
    printf("%d\n", n);

    switch (type) {
        case 1 : isosceles_triangle(n); break;
        case 2 : right_triangle(n); break;
        case 3 : rotated_triangle(n); break;
        case 4 : square(n); break;
        default: printf("Unknown type of triangle.\nPlease, enter number from 1 to 4.\n");
    }
    return 0;
}
