#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Stack structure
// typedef struct {
//     double data[128];
//     int top;
// } Stack;

// Function prototypes
// void push(Stack *stack, double value);
// double pop(Stack *stack);
// int precedence(char operator);
// double binary_operation(double a, double b, char operation);
// double unary_operation(double a, char operation);

// int main() {
void calc(char *expression, double *values) {
    // char expression[128]; // Assuming the expression fits within MAX_STACK_SIZE
    // scanf("%s", expression);

    Stack stack;
    stack.top = -1;  // Initialize stack to be empty
    // double values[80];
    // printf("%s\n", expression);
    for (int j = 1; j <= 80; j++) {
        double x = j * 3.14 / 20;
        for (int i = 0; i < (int)strlen(expression); i++) {
            char token = expression[i];
            if (token >= '0' && token <= '9') {
                push_double(&stack, token - '0');  // Convert digit character to actual number
            } else if (token == 'x')
                push_double(&stack, x);
            else if (token == '+' || token == '-' || token == '*' || token == '/') {
                double b = pop(&stack);
                double a = pop(&stack);
                push_double(&stack, binary_operation(a, b, token));
            } else {
                double a = pop(&stack);
                push_double(&stack, unary_operation(a, token));
            }
        }
        values[j] = pop(&stack);
    }

    for (int j = 1; j <= 80; j++) printf("%lf\n", values[j]);
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

// int operation_prior(char a) {
//     int d = 0;
//     if (a == '(')
//         d = 1;
//     else if (a == '+' || a == '-')
//         d = 2;
//     else if (a == '*' || a == '/')
//         d = 3;
//     else if (a == '!' || a == '?' || a == ':' || a == ';' || a == '@' || a == '&')
//         d = 4;
//     return d;
// }

double binary_operation(double a, double b, char operation) {
    switch (operation) {
        ;
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
        ;
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
