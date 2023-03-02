/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T13 Murtoluvut
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef MURTOLUKU_H
#define MURTOLUKU_H

struct Murtoluku {
    int os;
    int nim;
};

typedef struct Murtoluku Murtoluku;

Murtoluku supistettuML(int os, int nim);

Murtoluku lisaaML(Murtoluku a, Murtoluku b);

Murtoluku vahennaML(Murtoluku a, Murtoluku b);

Murtoluku kerroML(Murtoluku a, Murtoluku b);

Murtoluku jaaML(Murtoluku a, Murtoluku b);

void tulostaML(Murtoluku ml);

#endif
