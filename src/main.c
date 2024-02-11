#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

struct stack {
    double c;
    struct stack *next;
};

struct stack *push(struct stack *, double a);
char delete_symbol(struct stack **);

struct stack *push(struct stack *head, double a) {
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
    double a;
    if (*head == NULL)
        a = 0;
    else {
        p = *head;
        a = p->c;
        *head = p->next;
        free(p);
    }
    return a;
}

double push_help(char c) {
    double d = 0;
    if(c == '1')
        d = 1.0;
    else if(c == '2')
        d = 2.0;
    else if(c == '3')
        d = 3.0;
    else if(c == '4')
        d = 4.0;
    else if(c == '5')
        d = 5.0;
    else if(c == '6')
        d = 6.0;
    else if(c == '7')
        d = 7.0;
    else if(c == '8')
        d = 8.0;
    else if(c == '9')
        d = 9.0;
    else if(c == '0')
        d = 0.0;
    return d;
}

double count_y(char output[80], struct stack *head, double x) {
    double result = 0;
    for (int i = 0; i < (int)strlen(output); i++) {
        if (output[i] >= '0' && output[i] <= '9') {
            head = push(head, push_help(output[i]));
            result = push_help(output[i]);
        }
        else if (output[i] == 'x') {
            head = push(head, x);
            result = x;
        } else if (output[i] == '+') {
            result = delete_symbol(&head);
            result += delete_symbol(&head);
        } else if (output[i] == '-') {
            result = delete_symbol(&head);
            result -= delete_symbol(&head);
        } else if (output[i] == '*') {
            result = delete_symbol(&head);
            result *= delete_symbol(&head);
        } else if (output[i] == '/') {
            result = delete_symbol(&head);
            result /= delete_symbol(&head);
        } else if (output[i] == '!') {
            result = sin(delete_symbol(&head));
        } else if (output[i] == '?') {
            result = cos(delete_symbol(&head));
        } else if (output[i] == ':') {
            result = tan(delete_symbol(&head));
        } else if (output[i] == ';') {
            result = 1/tan(delete_symbol(&head));
        } else if (output[i] == '&') {
            result = log(delete_symbol(&head));
        } else if (output[i] == '@') {
            result = sqrt(delete_symbol(&head));
        } else if (output[i] == '~') {
            result = -(delete_symbol(&head));
        }
    }
    return result;
}

int main() {
    char output[80] = {0};
    struct stack *head = NULL;
    double to_graph[80] = {0};
    //char temp[100];
    //char *point;
    
    scanf("%s", output);
    for (int j = 1; j <= 80; j++) {
        to_graph[j-1] = count_y(output, head, j * PI / 20);
    }
    
    for (int i = 0; i < 80; i++) {
        printf("%lf\n", to_graph[i]);
    }
    return 0;
}
