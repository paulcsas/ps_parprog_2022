#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// compiled with: gcc serial.c -o serial -std=gnu11 -Wall -Wextra -lm -lpthread

double random_unity() {
    return rand() / ((double) RAND_MAX); // return normalized value between 0 and 1
}

double estimate_pi(long number_of_samples) {

    long hit_count = 0;
    double x, y;

    unsigned int seed = (unsigned int)(time(NULL));

    for (long count = 0; count < number_of_samples; count++) {
        // also used rand_r for this version, since it is faster than rand()
        x = rand_r(&seed) / ((double) RAND_MAX);
        y = rand_r(&seed) / ((double) RAND_MAX);

        if (sqrt((x * x) + (y * y)) < 1) {
            hit_count++;
        }
    }

    return 4 * hit_count / ((double) number_of_samples);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Provide sample size as argument\n");
        exit(1);
    }

    clock_t begin = clock();
    double pi = estimate_pi(atoi(argv[1]));
    clock_t end = clock();

    printf("My Pi is: %f\n", pi);

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("And it took me: %f s\n", time_spent);

    return EXIT_SUCCESS;
}