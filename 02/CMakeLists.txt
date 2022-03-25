cmake_minimum_required(VERSION 3.21)
project(02 C)

set(CMAKE_C_STANDARD 11)

include_directories(mandelbrot)
include_directories(montecarlo_pi)

add_executable(02
        montecarlo_pi/parallel.c
        montecarlo_pi/serial.c
        mandelbrot/mandelbrot.c
        mandelbrot/stb_image_write.h)


