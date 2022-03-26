#include <stdio.h>
#include <stdlib.h>

#include "hadamard.h"

// Comparison of cache behaviour between row major and column major oriented loops

// Perf execution:  perf stat ./hadamard

int main() {
    static uint32_t a[n][n];
    static uint32_t b[n][n];
    static uint32_t c[n][n];

    clock_t begin = clock();
    hadamard_v1(a, b, c);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent for hadamard_v1: %f s\n", time_spent);

	return EXIT_SUCCESS;
}