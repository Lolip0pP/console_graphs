#include "str.h"

#include <stdio.h>
#include <string.h>

void replace_symbol(char* s) {
    printf("Print infix shit:\n");
    scanf("%s", s);

    if (s[0] == '-') s[0] = '~';
    str_replace(s, "cos", "?");
    str_replace(s, "sin", "!");
    str_replace(s, "tan", ":");
    str_replace(s, "ctg", ";");
    str_replace(s, "sqrt", "@");
    str_replace(s, "ln", "&");
    str_replace(s, "log", "&");
    str_replace(s, "(-", "(~");
    
    //printf("%d\n", norm(s));
    printf("%s\n", s);
}

void str_replace(char str[], char sub[], char nstr[]) {
    int strLen, subLen, nstrLen;
    int i = 0, j, k;
    int flag = 0, start, end;
    strLen = strlen(str);
    subLen = strlen(sub);
    nstrLen = strlen(nstr);

    for (i = 0; i < strLen; i++) {
        flag = 0;
        start = i;
        for (j = 0; str[i] == sub[j]; j++, i++)
            if (j == subLen - 1) flag = 1;
        end = i;
        if (flag == 0)
            i -= j;
        else {
            for (j = start; j < end; j++) {
                for (k = start; k < strLen; k++) str[k] = str[k + 1];
                strLen--;
                i--;
            }
            for (j = start; j < start + nstrLen; j++) {
                for (k = strLen; k >= j; k--) str[k + 1] = str[k];
                str[j] = nstr[j - start];
                strLen++;
                i++;
            }
        }
    }
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
