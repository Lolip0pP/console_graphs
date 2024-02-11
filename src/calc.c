#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc(char *outstring, double *values) {
    Stack stack;
    stack.top = -1;

    for (int j = 0; j < MAX_WIDTH; j++) {
        double x = j * M_PI / (MAX_WIDTH / 4);
        for (int i = 0; i < (int)strlen(outstring); i++) {
            char symbol = outstring[i];
            if (symbol >= '0' && symbol <= '9') {
                push_double(&stack, symbol - '0');
            } else if (symbol == 'x')
                push_double(&stack, x);
            else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
                double b = pop(&stack);
                double a = pop(&stack);
                push_double(&stack, binary_operation(a, b, symbol));
            } else {
                double a = pop(&stack);
                push_double(&stack, unary_operation(a, symbol));
            }
        }
        values[j] = pop(&stack);
    }
}

void push_double(Stack *stack, double value) {
    if (stack->top >= 127) {
        printf("Error: stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

double pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Error: stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

double binary_operation(double a, double b, char operation) {
    switch (operation) {
        case '+':
            a += b;
            break;
        case '-':
            a -= b;
            break;
        case '*':
            a *= b;
            break;
        case '/':
            a /= b;
            break;
        default:
            printf("Error: unknown operator %c.\n", operation);
            exit(EXIT_FAILURE);
    }
    return a;
}

double unary_operation(double a, char operation) {
    switch (operation) {
        case '~':
            a *= -1;
            break;
        case '!':
            a = sin(a);
            break;
        case '?':
            a = cos(a);
            break;
        case ':':
            a = tan(a);
            break;
        case ';':
            a = 1 / tan(a);
            break;
        case '@':
            a = sqrt(a);
            break;
        case '&':
            a = log(a);
            break;
        default:
            printf("Error: unknown operator %c.\n", operation);
            exit(EXIT_FAILURE);
    }
    return a;
}
