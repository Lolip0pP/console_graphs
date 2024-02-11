#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "graph.h"
#include "parsing.h"
#include "str.h"

int main() {
    char input[128], outstring[128];
    double values[128];
    replace_symbol(input);
    
    Parsing(input, outstring);
    calc(outstring, values);
    graph(values);
    return 0;
}
