/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T7 Double-lista
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


/* my implementations */
DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo) {

}

double dl_alkio(const DblLista *lista, size_t i) {

}

double dl_poista(DblLista *lista, size_t i) {

}


/* premade funcs */
DblSolmu * ds_luo(double data, DblSolmu *seur) {
    DblSolmu *ds = malloc(sizeof(DblSolmu));
    ds->data = data;
    ds->seur = seur;
    return ds;
}


DblLista * dl_luo(void) {
    DblLista *dl = malloc(sizeof(DblLista));
    dl->n = 0;
    dl->paa = NULL;
    return dl;
}


DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo) {
    dl->paa = ds_luo(arvo, dl->paa);
    dl->n += 1;
    return dl->paa;
}


void dl_tuhoa(DblLista *dl) {
    while(dl->n > 0) {
        dl_poistaEdesta(dl);
    }
    free(dl);
}


double dl_poistaEdesta(DblLista *dl) {
    double arvo = 0;
    if(dl->n > 0) {
        DblSolmu *vanhaPaa = dl->paa;
        arvo = dl->paa->data;
        dl->paa = dl->paa->seur;
        free(vanhaPaa);
        dl->n -= 1;
    }
    return arvo;
}


void dl_tulosta(const DblLista *lista) {
    DblSolmu *s;
    printf("Lista:");
    for(s = lista->paa; s != NULL; s = s->seur) {
        printf(" %.1f", s->data);
    }
    printf("\n");
}

