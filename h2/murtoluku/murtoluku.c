/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T13 Murtoluvut
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "murtoluku.h"
#include <stdio.h>
#include <stdlib.h>

/* greatest common denominator */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Murtoluku supistettuML(int os, int nim) {
    Murtoluku res;
    res.os = os;
    res.nim = nim;

    if (os == 0 || nim == 0) {
        return res;
    }

    if (nim < 0) {
        res.nim *= -1;
        res.os *= -1;
    }

    res.nim /= abs(gcd(os, nim));
    res.os /= abs(gcd(os, nim));

    return res;
}

Murtoluku lisaaML(Murtoluku a, Murtoluku b) {
    Murtoluku res;
    res.os = a.os * b.nim + b.os * a.nim;
    res.nim = a.nim * b.nim;

    return supistettuML(res.os, res.nim);
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b) {
    Murtoluku res;
    res.os = a.os * b.nim - b.os * a.nim;
    res.nim = a.nim * b.nim;

    return supistettuML(res.os, res.nim);
}

Murtoluku kerroML(Murtoluku a, Murtoluku b) {
    Murtoluku res;
    res.os = a.os * b.os;
    res.nim = a.nim * b.nim;

    return supistettuML(res.os, res.nim);
}

Murtoluku jaaML(Murtoluku a, Murtoluku b) {
    Murtoluku res;
    res.os = a.os * b.nim;
    res.nim = a.nim * b.os;

    return supistettuML(res.os, res.nim);
}

void tulostaML(Murtoluku ml) {
    if (ml.os == 0) {
        printf("0");
    }
    else if (ml.nim == 1) {
        printf("%d", ml.os);
    }
    else {
        printf("%d/%d", ml.os, ml.nim);
    }
}
