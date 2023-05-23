

/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T16 Välilyönnit
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef YKKOSVALIT_H
#define YKKOSVALIT_H


struct UintPari {
    unsigned int x;
    unsigned int y;
};

typedef struct UintPari UintPari;


UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi);

#endif