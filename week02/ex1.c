#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int max_int;
    float max_float;
    double max_double;

    max_int = INT_MAX;
    max_float = FLT_MAX;
    max_double = DBL_MAX;

    printf("Size of max_int is %d and its value is %d\n", sizeof(max_int), max_int);
    printf("Size of max_float is %d and its value is %f\n", sizeof(max_float), max_float);
    printf("Size of max_double is %d and its value is %f\n", sizeof(max_double), max_double);

    return 0;
}