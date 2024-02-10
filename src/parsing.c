#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct st {
    char c;
    struct st *next;
};

struct st *push(struct st *, char);
char delete_symbol(struct st **);
int operation_priority(char);

int main() {
    //'+', '-', '*', '/', '!', '?', ':', ';', '@', '&'
    struct st *OPERS = NULL;
    char a[80], outstring[80];
    int i = 0, j = 0;

    while (getchar() != 'n') {
        fflush(stdin);
        scanf("%s", a);
        
        while (a[i] != '\0' && a[i] != '=') {
            if (a[i] == ')') {
                while ((OPERS->c) != '(')
                    outstring[j++] = delete_symbol(&OPERS);
                delete_symbol(&OPERS);
            } else if (a[i] == 'x' || (a[i] >='0' && a[i]<='9'))
                outstring[j++] = a[i];
            else if (a[i] == '(')
                OPERS = push(OPERS, '(');
            else if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*' || a[i] == '!' || a[i] == '?' ||
                     a[i] == ':' || a[i] == ';' || a[i] == '@' || a[i] == '&') {
                if (OPERS == NULL)
                    OPERS = push(OPERS, a[i]);
                else {
                    if (operation_priority(OPERS->c) < operation_priority(a[i]))
                        OPERS = push(OPERS, a[i]);
                    else {
                        while ((OPERS != NULL) && (operation_priority(OPERS->c) >= operation_priority(a[i])))
                            outstring[j++] = delete_symbol(&OPERS);
                        OPERS = push(OPERS, a[i]);
                    }
                }
            }
            i++;
        }
        
        while (OPERS != NULL)
            outstring[j++] = delete_symbol(&OPERS);
        outstring[j] = '\0';
        printf("\n%s\n", outstring);
        fflush(stdin);
        printf("\nПовтоpить(y/n)?");
    }
    return 0;
}

struct st *push(struct st *HEAD, char a) {
    struct st *PTR;
    if ((PTR = malloc(sizeof(struct st))) == NULL) {
        puts("Sorry, not today:(");
        exit(-1);
    }
    PTR->c = a;
    PTR->next = HEAD;
    return PTR;
}

char delete_symbol(struct st **HEAD) {
    struct st *PTR;
    char a;
    if (*HEAD == NULL)
        a = '\0';
    else {
        PTR = *HEAD;
        a = PTR->c;
        *HEAD = PTR->next;
        free(PTR);
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
