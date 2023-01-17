/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T17 Anagrammit
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

#include "anagrammit.h"


int anagrammeja(char mj1[], char mj2[]) {

    int len = strlen(mj1);
    int i = 0;
    int j = 0;
    int c_mj1 = 0;
    int c_mj2 = 0;

    /* diff lengths automatically fail */
    if (len != (int) strlen(mj2)) {
        return 0;
    }

    for (; i < len; i++ ) {
        c_mj1 = 0;
        c_mj2 = 0;
        /* count letter i in mj1 */
        for (j = 0; j < len; j++) {
            if (mj1[i] == mj1[j]) {
                c_mj1++;
            }
        }

        /* check if mj2 has n counts of the same letter */
        for (j = 0; j < len; j++) {
            if (mj1[i] == mj2[j]) {
                c_mj2++;
            }
        }

        /* if counts don't match it's not an anagram */
        if (c_mj1 != c_mj2) {
            return 0;
        }
    }

    return 1;
}
