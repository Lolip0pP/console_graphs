#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char c;
    struct stack *next;
};

struct stack *push(struct stack *, char);
char delete_symbol(struct stack **);
int operation_priority(char);

int main() {
    //'+', '-', '*', '/', '!', '?', ':', ';', '@', '&'
    struct stack *operators = NULL;
    char a[80], outstring[80];
    int i = 0, j = 0;

    scanf("%s", a);

    while (a[i] != '\0' && a[i] != '=') {
        if (a[i] == ')') {
            while ((operators->c) != '(') outstring[j++] = delete_symbol(&operators);
            delete_symbol(&operators);
        } else if (a[i] == 'x' || (a[i] >= '0' && a[i] <= '9') || a[i] == '.')
            outstring[j++] = a[i];
        else if (a[i] == '(')
            operators = push(operators, '(');
        else if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*' || a[i] == '!' || a[i] == '?' ||
                 a[i] == ':' || a[i] == ';' || a[i] == '@' || a[i] == '&') {
            if (operators == NULL)
                operators = push(operators, a[i]);
            else {
                if (operation_priority(operators->c) < operation_priority(a[i]))
                    operators = push(operators, a[i]);
                else {
                    while ((operators != NULL) &&
                           (operation_priority(operators->c) >= operation_priority(a[i])))
                        outstring[j++] = delete_symbol(&operators);
                    operators = push(operators, a[i]);
                }
            }
        }
        i++;
    }

    while (operators != NULL) outstring[j++] = delete_symbol(&operators);
    outstring[j] = '\0';

    printf("%s\n", outstring);

    for (i = 0; i < (int)strlen(outstring); i++) outstring[i] = '\0';
    fflush(stdin);

    return 0;
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
