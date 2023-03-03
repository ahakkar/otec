/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T1 Fibonakki
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "fibonacci.h"


#include <stdlib.h>

unsigned int* fib_jono(unsigned int n) {
    unsigned int* fibonacci = (unsigned int*) malloc(n * sizeof(unsigned int));
    unsigned int i;

    if (n == 0) {
        return fibonacci;
    }

    fibonacci[0] = 0;

    if (n == 1) {
        return fibonacci;
    }

    fibonacci[1] = 1;

    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    return fibonacci;
}
