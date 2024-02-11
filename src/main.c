#include <stdio.h>

#include "calc.h"
#include "graph.h"
#include "parsing.h"
#include "str.h"

int main() {
    char input[128];
    replace_symbol(input);

    if (norm(input) == 0) {
        char outstring[128];
        double values[128];

        parsing(input, outstring);
        calc(outstring, values);
        graph(values);
    } else
        printf("Некорректный ввод.");
    return 0;
}
