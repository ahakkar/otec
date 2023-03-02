/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T11 Lämpöasteet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "asteet.h"
#include <stdio.h>

int main()
{
    Lampotila a;
    Lampotila b;

    /*
    b.lampotila = 79.7;
    b.asteikko = Fahrenheit;
    printf("79.7 F on %.2f C\n", muunna(b, Celsius));

    */

    a.lampotila = -34.33;
    a.asteikko = Fahrenheit;
    b.lampotila = 35.30;
    b.asteikko = Celsius;

    printf("%.2f, %.2f, = %.2f\n", a.lampotila, b.lampotila, erotus(a, b, Fahrenheit));

    a.lampotila = -34.33;
    a.asteikko = Fahrenheit;
    b.lampotila = 35.30;
    b.asteikko = Celsius;

    printf("%.2f, %.2f, = %.2f\n", a.lampotila, b.lampotila, erotus(a, b, Fahrenheit));



    return 0;
}
