
/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T13 Tiedostoon tulostus
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdlib.h>

#ifndef TULOSTUS_H
#define TULOSTUS_H

double round_to_precision(double value, int precision);

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi);

#endif