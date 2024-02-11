#include "parsing.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct stack {
//     char c;
//     struct stack *next;
// };

// struct stack *push(struct stack *, char);
// char delete_symbol(struct stack **);
// int operation_priority(char);

// int main() {
//'+', '-', '*', '/', '!', '?', ':', ';', '@', '&'
// struct stack *operators = NULL;
// char input[80], outstring[80];
// int i = 0, j = 0;
void Parsing(char *input, char *outstring) {
    int i = 0, j = 0;
    struct stack *operators = NULL;
    printf("Запускаем модуль? y/n \n");
    while (input[i] != '\0' && input[i] != '=') {
        if (input[i] == ')') {
            while ((operators->c) != '(') outstring[j++] = delete_symbol(&operators);
            delete_symbol(&operators);
        } else if (input[i] == 'x' || (input[i] >= '0' && input[i] <= '9') || input[i] == '.')
            outstring[j++] = input[i];
        else if (input[i] == '(')
            operators = push(operators, '(');
        else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' ||
                 input[i] == '!' || input[i] == '?' || input[i] == ':' || input[i] == ';' ||
                 input[i] == '@' || input[i] == '&') {
            if (operators == NULL)
                operators = push(operators, input[i]);
            else {
                if (operation_priority(operators->c) < operation_priority(input[i]))
                    operators = push(operators, input[i]);
                else {
                    while ((operators != NULL) &&
                           (operation_priority(operators->c) >= operation_priority(input[i])))
                        outstring[j++] = delete_symbol(&operators);
                    operators = push(operators, input[i]);
                }
            }
        }
        i++;
    }

    while (operators != NULL) outstring[j++] = delete_symbol(&operators);
    outstring[j] = '\0';

    printf("%s\n", outstring);

    // for (i = 0; i < (int)strlen(outstring); i++) outstring[i] = '\0';
    // fflush(stdin);

    // return 0;
}

struct stack *push(struct stack *head, char a) {
    struct stack *p;
    if ((p = malloc(sizeof(struct stack))) == NULL) {
        printf("Sorry, not today:(");
        exit(-1);
    }
    p->c = a;
    p->next = head;
    return p;
}

char delete_symbol(struct stack **head) {
    struct stack *p;
    char a;
    if (*head == NULL)
        a = '\0';
    else {
        p = *head;
        a = p->c;
        *head = p->next;
        free(p);
    }
    return a;
}

int operation_priority(char a) {
    int d = 0;
    if (a == '(')
        d = 1;
    else if (a == '+' || a == '-')
        d = 2;
    else if (a == '*' || a == '/')
        d = 3;
    else if (a == '!' || a == '?' || a == ':' || a == ';' || a == '@' || a == '&')
        d = 4;
    return d;
}
