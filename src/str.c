#include "str.h"

#include <stdio.h>
#include <string.h>

void replace_symbol(char* input) {
    printf("Print infix expression:\n");
    scanf("%100s", input);

    // Подготовка к посимвольному считыванию следующими модулямиы
    if (input[0] == '-') input[0] = '~';
    str_replace(input, "cos", "?");
    str_replace(input, "sin", "!");
    str_replace(input, "tan", ":");
    str_replace(input, "ctg", ";");
    str_replace(input, "sqrt", "@");
    str_replace(input, "ln", "&");
    str_replace(input, "log", "&");
    str_replace(input, "(-", "(~");
}

void str_replace(char str[], char sub[], char nstr[]) {
    int str_len = strlen(str), sub_len = strlen(sub), nstr_len = strlen(nstr);
    int i = 0, j, k;

    for (i = 0; i < str_len; i++) {
        int flag = 0, start = i, end = 0;
        for (j = 0; str[i] == sub[j]; j++, i++)
            if (j == sub_len - 1) flag = 1;
        end = i;
        if (flag == 0)
            i -= j;
        else {
            for (j = start; j < end; j++) {
                for (k = start; k < str_len; k++) str[k] = str[k + 1];
                str_len--;
                i--;
            }
            for (j = start; j < start + nstr_len; j++) {
                for (k = str_len; k >= j; k--) str[k + 1] = str[k];
                str[j] = nstr[j - start];
                str_len++;
                i++;
            }
        }
    }
}

int norm(char* s) {
    const char dict[] = {'+', '-', '*', '/', '!', '?', ':', ';', '@', '&', 'x', '1', '2',
                         '3', '4', '5', '6', '7', '8', '9', '0', '(', ')', '.', '~'};
    int d = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < (int)strlen(s); i++) {
        d = 1;
        for (int j = 0; j < 25; j++) {
            if (s[i] == dict[j]) d = 0;
        }
        if (d == 1) break;
        if (s[i] == '(') count1 += 1;
        if (s[i] == ')') count2 += 1;
    }
    if (count1 != count2) d = 2;
    return d;
}
