#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define MAX_HEIGHT 25
#define MAX_WIDTH 80

void round_array_values(float array[], int size);

int main() {
    float values[80];
    for(int i = 0; i<80; i++) {
        values[i] = -1+i*PI/20;
    }
    
    int size = sizeof(values) / sizeof(values[0]);
    round_array_values(values, size);

    int graph[25][80] = {0};
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (i == values[j]) graph[i][j] = 1;
        }
    }

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (graph[i][j] == 1) {
                printf("*");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}

void round_array_values(float array[], int size) {
    for (int i = 0; i < size; i++) {
        float roundedValue = array[i] * 12 + 13;
        roundedValue = roundf(roundedValue);
        array[i] = roundedValue;
    }
}
