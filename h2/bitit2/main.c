/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T4 Bittiesityksen kääntö
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#include "bitit.h"
int main()
{
    long int lx = 2015;
    signed char cx = lx;
    short sx = lx;
    int ix = lx;

    tulosta_schar_bitit(cx);
    kaannaScharBitit(&cx);
    tulosta_schar_bitit(cx);    
    printf("\n");

    tulosta_short_bitit(sx);
    kaannaShortBitit(&sx);
    tulosta_short_bitit(sx);
    printf("\n");

    tulosta_int_bitit(ix);
    kaannaIntBitit(&ix);
    tulosta_int_bitit(ix);
    printf("\n");

    tulosta_long_bitit(lx);
    kaannaLongBitit(&lx);
    tulosta_long_bitit(lx);

    return 0;
}
