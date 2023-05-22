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


/* Add a node at position i */
DblSolmu *dl_lisaa(DblLista *lista, size_t i, double arvo) {
    DblSolmu *s;
    DblSolmu *new_node;
    int list_size = dl_koko(lista);
    int j = 0;

    /* Add the data to the end of list if i is out of bounds */
    if(i >= list_size) {
        new_node = ds_luo(arvo, NULL);
        s = lista->paa;
        while(s->seur != NULL) {
            s = s->seur;
        }
        s->seur = new_node;
        return new_node;        
    }

    /* otherwise add it to the specified position */
    for(s = lista->paa; s != NULL; s = s->seur) {
        if(j == i) {
            new_node = ds_luo(arvo, s->seur);
            s->seur = new_node;
            return new_node;
        }
        j++;
    }
    /* still did not find anything? */
    return NULL;
}

/* returns value at node position i in the linked list */
double dl_alkio(const DblLista *lista, size_t i) {    
    DblSolmu *s;
    int list_size = dl_koko(lista);
    int j = 0;

    /* check if i is out of bounds */
    if(i >= list_size) {
        return 0;
    }

    for(s = lista->paa; s != NULL; s = s->seur) {
        if(j == i) {
            return s->data;
        }
        j++;
    }
    /* still did not find anything? */
    return 0;
}

double dl_poista(DblLista *lista, size_t i) {

}

/* calculates the list size and returns it*/
int dl_koko(const DblLista *lista) {
    int list_size = 0;
    DblSolmu *s;
    for(s = lista->paa; s != NULL; s = s->seur) {
        list_size++;
    }
    return list_size;
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

