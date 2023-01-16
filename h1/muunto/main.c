#include "muunto.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;

    for(; i < argc; i++) {
        printf("%d: %s --> ", i, argv[i]);
        muunna(argv[i]);
        printf("%s\n", argv[i]);
    }
    return 0;
}
