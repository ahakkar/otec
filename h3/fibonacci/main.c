/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T1 Fibonakki
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int *fibonacci = fib_jono(15); /* 15 ensimmäistä fibonaccin lukua. */
    int i = 0;
    for(i = 0; i < 15; ++i)
    {
        printf(" %u", fibonacci[i]);
    }
    printf("\n");
    free(fibonacci); /* Dynaamisesti varatun muistin vapautus. */
    return 0;
}
