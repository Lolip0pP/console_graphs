#include "parsing.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parsing(char *input, char *outstring) {
    int i = 0, j = 0;
    struct stack *operators = NULL;

    while (input[i] != '\0' && input[i] != '=') {
        //
        if (input[i] == ')') {
            while ((operators->data) != '(') outstring[j++] = delete_symbol(&operators);
            delete_symbol(&operators);
        }
        //
        else if (input[i] == 'x' || (input[i] >= '0' && input[i] <= '9') || input[i] == '.')
            outstring[j++] = input[i];
        //
        else if (input[i] == '(')
            operators = push(operators, '(');
        //
        else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' ||
                 input[i] == '!' || input[i] == '?' || input[i] == ':' || input[i] == ';' ||
                 input[i] == '@' || input[i] == '&' || input[i] == '~') {
            if (operators == NULL)
                operators = push(operators, input[i]);
            else {
                if (operation_priority(operators->data) < operation_priority(input[i]))
                    operators = push(operators, input[i]);
                else {
                    while ((operators != NULL) &&
                           (operation_priority(operators->data) >= operation_priority(input[i])))
                        outstring[j++] = delete_symbol(&operators);
                    operators = push(operators, input[i]);
                }
            }
        }
        i++;
    }

    while (operators != NULL) outstring[j++] = delete_symbol(&operators);
    outstring[j] = '\0';
}

struct stack *push(struct stack *head, char operator) {
    struct stack *pointer;
    if ((pointer = malloc(sizeof(struct stack))) == NULL) {
        printf("Sorry, not today:(");
        exit(-1);
    }
    pointer->data = operator;
    pointer->next = head;
    return pointer;
}

char delete_symbol(struct stack **head) {
    struct stack *pointer;
    char symbol;
    if (*head == NULL)
        symbol = '\0';
    else {
        pointer = *head;
        symbol = pointer->data;
        *head = pointer->next;
        free(pointer);
    }
    return symbol;
}

int operation_priority(char operator) {
    int d = 0;
    if (operator== '(')
        d = 1;
    else if (operator== '+' || operator== '-')
        d = 2;
    else if (operator== '*' || operator== '/')
        d = 3;
    else if (operator== '!' || operator== '?' || operator== ':' || operator== ';' || operator== '@' ||
             operator== '&' ||
             operator== '~')
        d = 4;
    return d;
}
