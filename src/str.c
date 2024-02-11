#include "str.h"

#include <stdio.h>
#include <string.h>

// int main() {
void replace_symol(char* buf, char* s) {
    // char buf[80];
    // char s[80];
    printf("Print infix shit:\n");
    scanf("%s", s);

    if (s[0] == '-') s[0] = '~';
    str_replace(buf, sizeof(buf) - 1, s, "cos", "?");
    str_replace(s, sizeof(s) - 1, buf, "sin", "!");
    str_replace(buf, sizeof(buf) - 1, s, "tan", ":");
    str_replace(s, sizeof(s) - 1, buf, "ctg", ";");
    str_replace(buf, sizeof(buf) - 1, s, "sqrt", "@");
    str_replace(s, sizeof(s) - 1, buf, "ln", "&");
    str_replace(buf, sizeof(buf) - 1, s, "(-", "(~");

    // printf("%d\n", norm(s));
    printf("%s\n", buf);

    // return 0;
}

char* str_replace(char* hey, int num, const char* str, const char* orig, const char* rep) {
    const char* p;
    size_t len1 = strlen(orig);
    size_t len2 = strlen(rep);
    char* tmp = hey;
    num -= 1;
    while ((p = strstr(str, orig)) != NULL) {
        num -= (p - str) + len2;
        if (num < 1) break;
        strncpy(hey, str, (size_t)(p - str));
        hey += p - str;
        strncpy(hey, rep, len2);
        hey += len2;
        str = p + len1;
    }

    for (; (*hey = *str) && (num > 0); --num) {
        hey++;
        str++;
    }
    return tmp;
}

int norm(char* s) {
    char dict[] = {'+', '-', '*', '/', '!', '?', ':', ';', '@', '&', 'x', '1',
                   '2', '3', '4', '5', '6', '7', '8', '9', '0', '(', ')', '.'};
    int d = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < (int)strlen(s); i++) {
        d = 1;
        for (int j = 0; j < 23; j++) {
            if (s[i] == dict[j]) d = 0;
        }
        if (d == 1) break;
        if (s[i] == '(') count1 += 1;
        if (s[i] == ')') count2 += 1;
    }
    if (count1 != count2) d = 1;
    return d;
}
