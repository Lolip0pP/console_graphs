#ifndef CALC_H
#define CALC_H

#define MAX_HEIGHT 25
#define MAX_WIDTH 80

typedef struct {
    double data[128];
    int top;
} Stack;

void push_double(Stack *stack, double value);
double pop(Stack *stack);
double binary_operation(double a, double b, char operation);
double unary_operation(double a, char operation);
void calc(char *outstring, double *values);

#endif
