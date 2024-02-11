#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 25
#define MAX_WIDTH 80

// int main() {
void graph(double *values) {
    // float values[80];
    // for(int i = 0; i<80; i++) {
    //     values[i] = -1+i*PI/20;
    // }

    int size = 80;
    //  = sizeof(values) / sizeof(values[0]);
    round_array_values(values, size);

    // int graph[25][80] = {0};
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (i == values[j])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }

    // return 0;
}

void round_array_values(double array[], int size) {
    for (int i = 0; i < size; i++) {
        double roundedValue = array[i] * 12 + 12;
        roundedValue = roundf(roundedValue);
        array[i] = roundedValue;
    }
}
