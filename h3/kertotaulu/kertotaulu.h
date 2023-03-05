/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T4 Kertotaulu #3
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef KERTOTAULU_H
#define KERTOTAULU_H

typedef unsigned int uint;

struct Kertotaulu {
    uint a;
    uint b;
    uint c;
    uint d;
    uint **kertotaulu;
};

typedef struct Kertotaulu Kertotaulu;

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d);
Kertotaulu * luoKertotaulu2(uint a, uint b, uint c, uint d);

void tuhoaKertotaulu(Kertotaulu *kt);

#endif
