/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T13 Tiedostoon tulostus
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>


void tulostaDblTaulu(
    double *taulu, 
    size_t lkm,
    const char *taulNimi, 
    int tarkkuus,
    const char *tiedNimi
) {
    FILE *write_file = fopen(tiedNimi, "w");
    size_t i = 0;

    for (i = 0; i < lkm; i++) {
        fprintf(write_file, "%s[%lu] = %.*f\n", taulNimi, i, tarkkuus, taulu[i]);
    }

    fclose(write_file);
}