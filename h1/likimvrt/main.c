/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T20 Liukulukujen vertailu
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

#include "likimvrt.h"

int main(void) {
    double d = 3*0.1;
    if (d == 0.3) {
        printf("Arvo d = %.20f on %.20f\n", d, 0.3);
    } else {
        printf("Arvo d = %.20f ei ole %.20f\n", d, 0.3);
    }

    printf("Toleranssi: %.20f\n", lueToleranssi());

    if (doubleVrt(d, 0.3)) {
        printf("Arvo d = %.20f on likimäärin %.20f\n", d, 0.3);
    } else {
        printf("Arvo d = %.20f ei ole likimäärin %.20f\n", d, 0.3);
    }

    asetaToleranssi(0.0000000000000000001);
    printf("Uusi toleranssi: %.20f\n", lueToleranssi());

    if (doubleVrt(d, 0.3)) {
        printf("Arvo d = %.20f on likimäärin %.20f\n", d, 0.3);
    } else {
        printf("Arvo d = %.20f ei ole likimäärin %.20f\n", d, 0.3);
    }

    return 0;
}
