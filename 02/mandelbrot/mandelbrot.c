#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_SAMPLES 10000

void calc_mandelbrot(uint8_t image[Y][X]) {
    double x, y;    // coordinates of the point in the complex plane
    double cx, cy;    // scaled coordinates of the point in the complex plane
    double x_map[2] = {-2.5, 1}, y_map[2] = {-1, 1}, iteration_map[2] = {0, 255};    // mapping margins
    double iteration;
    uint8_t norm_iteration;
    double x_tmp;


    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            x = 0.0;
            y = 0.0;
            cx = x_map[0] + ((double) j / X) * (x_map[1] - x_map[0]);
            cy = y_map[0] + ((double) i / Y) * (y_map[1] - y_map[0]);

            iteration = 0;
            while (x * x + y * y <= 2 * 2 && iteration < MAX_SAMPLES) {
                x_tmp = x * x - y * y + cx;
                y = 2 * x * y + cy;
                x = x_tmp;
                iteration = iteration + 1;
            }

            norm_iteration = (uint8_t)  ((MAX_SAMPLES / iteration) * (iteration_map[1] - iteration_map[0]));
            image[i][j] = norm_iteration;
        }
    }
}


int main() {
	uint8_t image[Y][X];

    // only time execution speed of calc_mandelbrot
    clock_t begin = clock();

	calc_mandelbrot(image);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("execution time calc_mandelbrot: %f s\n", time_spent);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}