#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 25
#define MAX_WIDTH 80

void graph(double *values) {
    int size = 80;
    round_array_values(values, size);

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (i == values[j])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}

void round_array_values(double array[], int size) {
    for (int i = 0; i < size; i++) {
        double rounded_value = array[i] * 12 + 12;
        rounded_value = roundf(rounded_value);
        array[i] = rounded_value;
    }
}
