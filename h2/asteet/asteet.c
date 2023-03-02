/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T11 Lämpöasteet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "asteet.h"
#include <stdio.h>

/* convert temperature from one scale to another */
float convert_temperature(float temp, enum Asteikko from, enum Asteikko to) {
    switch (from) {
        case Celsius:
            switch (to) {
                case Fahrenheit:
                    return temp * 9 / 5 + 32;
                case Kelvin:
                    return temp + 273.15;
                default:
                    return temp;
            }
        case Fahrenheit:
            switch (to) {
                case Celsius:
                    return (temp - 32) * 5 / 9;
                case Kelvin:
                    return (temp + 459.67) * 5 / 9;
                default:
                    return temp;
            }
        case Kelvin:
            switch (to) {
                case Celsius:
                    return temp - 273.15;
                case Fahrenheit:
                    return temp * 9 / 5 - 459.67;
                default:
                    return temp;
            }
        default:
            printf("Invalid temperature scale\n");
            return 0;
    }
}

float muunna(struct Lampotila a, enum Asteikko b) {
    return convert_temperature(a.lampotila, a.asteikko, b);
}

/*
 * do calculations in Kelvin and return whatever is wanted
 */
float erotus(struct Lampotila a, struct Lampotila b, enum Asteikko c) {
    float whatever_a = convert_temperature(a.lampotila, a.asteikko, c);
    float whatever_b = convert_temperature(b.lampotila, b.asteikko, c);

    return whatever_a - whatever_b;
}
