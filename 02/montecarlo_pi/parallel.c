#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_THREADS 8         //number of threads
#define NUM_SAMPLES 500000000      //total number of samples
#define BILLION  1E9

// Based on the source https://github.com/ishanthilina/Pthreads-Monte-Carlo-Pi-Calculation/blob/master/pthread.c

void throw_guesses(long num_samples, long* hit_count, unsigned int *seed) {
    double x;
    double y;
    for (long count = 0; count < num_samples; count++) {
        x = rand_r(seed) / ((double) RAND_MAX);
        y = rand_r(seed) / ((double) RAND_MAX);
        if (sqrt((x * x) + (y * y)) < 1) {
            (*hit_count)++;
        }
    }
}

void* calc(void* thread_id) {

    long t_id = (long) thread_id;

    long* hit_count = (long *) malloc(sizeof(long));
    *hit_count = 0;

    double num_samples = NUM_SAMPLES/NUM_THREADS;

    unsigned int seed = (unsigned int)(time(NULL));

    throw_guesses(num_samples, hit_count, &seed);

    // if the sample size is not a multiple of the thread size
    // do the rest on thread 0
    if(t_id == 0) {
        int num_remaining = NUM_SAMPLES % NUM_SAMPLES;

        throw_guesses(num_remaining, hit_count, &seed);
    }

    pthread_exit((void *) hit_count);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long hit_total = 0;
    void* thread_result;

    // Calculate time taken by a request
    struct timespec requestStart, requestEnd;
    clock_gettime(CLOCK_REALTIME, &requestStart);

    // Create the threads
    for(long t = 0; t<NUM_THREADS; t++){
        int p = pthread_create(&threads[t], NULL, calc, (void *)t);
        if (p){
            printf("ERROR; return code from pthread_create() is %d\n", p);
            exit(-1);
        }
    }

    // Wait for the threads and combine results
    for(long t=0;t<NUM_THREADS;t++){
        pthread_join(threads[t], &thread_result);
        hit_total += *(long *)thread_result;
    }

    clock_gettime(CLOCK_REALTIME, &requestEnd);
    // Calculate time it took
    double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
                   + ( requestEnd.tv_nsec - requestStart.tv_nsec )
                     / BILLION;

    printf("My Pi is: %f\n", 4 * (double) hit_total / NUM_SAMPLES);
    printf("And it took me: %f s on %d threads\n", accum, NUM_THREADS);

    return EXIT_SUCCESS;
}