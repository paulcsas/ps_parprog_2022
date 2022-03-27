CFLAGS = -std=gnu11 -Wall -Wextra -lm -fopenmp

.PHONY: all
all: serial parallel_v2

.PHONY: clean
clean:
	$(RM) serial parallel parallel_v2 parallel_pk

serial: serial.c

parallel_v2: parallel_v2.c
