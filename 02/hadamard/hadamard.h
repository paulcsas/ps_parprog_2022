#include <stdint.h>
#include <time.h>

#ifndef INC_02_HADAMARD_H
#define INC_02_HADAMARD_H

#define n 10000

void hadamard_v1(uint32_t a[n][n], uint32_t b[n][n], uint32_t c[n][n]){
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

void hadamard_v2(uint32_t a[n][n], uint32_t b[n][n], uint32_t c[n][n]){
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < n; ++i) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

#endif //INC_02_HADAMARD_H
