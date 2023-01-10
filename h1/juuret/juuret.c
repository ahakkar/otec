/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T7 juuret
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int EXTRA_ARGS = 2;

int main(int argc, char *argv[]) {

    int prec = atof(argv[1]);
    int i = 0;

    while (i < argc-EXTRA_ARGS) {
        printf("sqrt(%.*f) = %.*f\n",
               prec, atof(argv[i+EXTRA_ARGS]),
               prec, sqrt(atof(argv[i+EXTRA_ARGS])));
        i++;
    }
    return 0;

}
