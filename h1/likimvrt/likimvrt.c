/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T20 Liukulukujen vertailu
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <math.h>

#include "likimvrt.h"

double toleranssi = 0.000001;

double lueToleranssi() {
    return toleranssi;
}

void asetaToleranssi(double uusiToleranssi) {
    toleranssi = uusiToleranssi;
}

int doubleVrt(double a, double b) {
    if (fabs(a) - fabs(b) < toleranssi ) {
        return 1;
    }

    return 0;
}


