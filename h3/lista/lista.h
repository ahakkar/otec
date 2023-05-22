/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T7 Double-lista
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
struct DblSolmu {
    double data;
    struct DblSolmu *seur;
};

typedef struct DblSolmu DblSolmu;



struct DblLista {
    size_t n;
    DblSolmu *paa;
};

typedef struct DblLista DblLista;

DblSolmu * ds_luo(double data, DblSolmu *seur);

DblLista * dl_luo(void);

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo);

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo);

void dl_tuhoa(DblLista *dl);

double dl_poistaEdesta(DblLista *dl);

double dl_alkio(const DblLista *lista, size_t i);

double dl_poista(DblLista *lista, size_t i);

void dl_tulosta(const DblLista *lista);

int dl_koko(const DblLista *lista);

#endif
