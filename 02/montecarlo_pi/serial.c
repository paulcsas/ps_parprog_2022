#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double random_unity() {
    return rand() / ((double) RAND_MAX); // return normalized value between 0 and 1
}

double estimate_pi(uint32_t number_of_samples) {
    srand(time(NULL));

    uint32_t hit_count = 0;

    for (uint32_t count = 0; count < number_of_samples; count++) {
        double x = random_unity();
        double y = random_unity();

        double r = sqrt((x * x) + (y * y));

        if (r < 1) {
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