#ifndef CALC_H
#define CALC_H

typedef struct {
    double data[128];
    int top;
} Stack;

void push_double(Stack *stack, double value);
double pop(Stack *stack);
// int operation_priority(char a);
double binary_operation(double a, double b, char operation);
double unary_operation(double a, char operation);
void calc(char *expression, double *values);

#endif