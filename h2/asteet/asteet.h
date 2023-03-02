/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T11 Lämpöasteet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef ASTEET_H
#define ASTEET_H

enum Asteikko {
    Celsius,
    Fahrenheit,
    Kelvin
};

typedef enum Asteikko Asteikko;

struct Lampotila {
    float lampotila;
    Asteikko asteikko;
};

typedef struct Lampotila Lampotila;

float muunna(Lampotila a, Asteikko b);

float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif
