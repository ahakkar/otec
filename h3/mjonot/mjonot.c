/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T2 Merkkijonotaulukko
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#include "mjonot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** kopioi_mjt(char **mjt, size_t lkm) {
    /* Allocate memory for the new list of strings */
    char **new_mjt = (char **) malloc(lkm * sizeof(char *));
    size_t i = 0;

    for (i = 0; i < lkm; i++) {
        size_t len = strlen(mjt[i]);
        new_mjt[i] = (char *) malloc((len + 1) * sizeof(char));
        memcpy(new_mjt[i], mjt[i], len+1);
    }

    return new_mjt;
}
