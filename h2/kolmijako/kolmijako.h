/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T15 Kolmijako
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#ifndef KOLMIJAKO_H
#define KOLMIJAKO_H

struct IntPari {
    int x;
    int y;
};

typedef struct IntPari IntPari;

IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2);

#endif
