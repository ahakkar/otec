/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T5 UTF-8 koodaus
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

#include "utf8.h"

int main()
{
    unsigned int koodit[6] = {228, 49340, 49457, 12477, 12491, 12540};
    unsigned char utf8[5];
    int i = 0;

    for(i = 0; i < 6; ++i) {
        utf8_koodaa(koodit[i], utf8);
        printf("%s\n", utf8);
    }
    return 0;
}
