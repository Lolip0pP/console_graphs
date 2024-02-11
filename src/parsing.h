#ifndef PARSING_H
#define PARSING_H

struct stack {
    char data;
    struct stack *next;
};

struct stack *push(struct stack *, char);
char delete_symbol(struct stack **);
int operation_priority(char);
void parsing(char *input, char *outstring);

#endif
