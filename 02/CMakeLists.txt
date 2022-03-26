cmake_minimum_required(VERSION 3.21)
project(02 C)

set(CMAKE_C_STANDARD 11)

include_directories(mandelbrot)
include_directories(hadamard)
include_directories(montecarlo_pi)

add_executable(02
        hadamard/hadamard.c
        hadamard/hadamard_v1.c
        hadamard/hadamard_v2.c
        montecarlo_pi/parallel.c
        montecarlo_pi/serial.c
        mandelbrot/mandelbrot.c
        mandelbrot/stb_image_write.h
        hadamard/hadamard.h)


