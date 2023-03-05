/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T4 Kertotaulu #3
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

/* refactored version to initialize vars first, then set them later */
Kertotaulu *luoKertotaulu2(uint a, uint b, uint c, uint d) {

    /* Initialize vars */
    Kertotaulu *kert;
    uint** list;
    int size_x, size_y, row, col, factor1, factor2;

    /* Return if params are bad */
    if (a > b || c > d) { return NULL; }

    /* Allocate memory and set vars */
    size_x = b-a+2;
    size_y = d-c+2;
    factor2 = c;
    kert = (Kertotaulu*) malloc(sizeof(Kertotaulu));
    list = (uint**) malloc(size_y * sizeof(uint*));

    for (row = 0; row < size_y; row++) {
        /* Allocate memory for a new pointer list */
        list[row] = (uint*) malloc(size_x * sizeof(uint));

        /* adjust factors for col and row title prints */
        if (row == 0) {
            factor1 = a;
        }
        else if (row == 1) {
            factor1 = a-1;
            factor2 = c;
        } else {
            factor1 = a-1;
        }

        /* Initialize each element of the pointer list */
        for (col = 0; col < size_x; col++) {
            /* ignore first cell */
            if (row == 0 && col == 0) {
                continue;
            }
            /* set row 0 to factor 1 */
            else if (row == 0) {
                list[row][col] = factor1;
            }
            /* set col 0 to factor 2 */
            else if (col == 0) {
                list[row][col] = factor2;
            }
            /* otherwise set the sum of factors */
            else {
                list[row][col] = factor1 * factor2;
            }
            factor1++;
        }
        if (row > 0 && col > 0) {
            factor2++;
        }
    }

    kert->a = a;
    kert->b = b;
    kert->c = c;
    kert->d = d;
    kert->kertotaulu = list;

    return kert;
}

/* Computes the factor for the given row and column indices */
uint computeFactor(uint col, uint row) {
    if (row == 1) {
        return col - 1;
    }
    else {
        return (col - 1) * (row - 1);
    }
}


Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d) {

    /* Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle)); */
    Kertotaulu *kert = (Kertotaulu*) malloc(sizeof(Kertotaulu));

    int size_x = b-a+2;
    int size_y = d-c+2;
    int row = 0;
    int col = 0;

    int factor1 = a;
    int factor2 = c;

    /* Allocate memory for a list of pointer lists */
    uint** list = (uint**) malloc(size_y * sizeof(uint*));

    if (a > b || c > d) {
        if (kert == NULL && list == NULL) {
            return NULL;
        }
        free(kert);
        free(list);
        return NULL;
    }

    for (row = 0; row < size_y; row++) {
        /* Allocate memory for a new pointer list */
        list[row] = (uint*) malloc(size_x * sizeof(uint));

        /* adjust factors for col and row title prints */
        if (row == 0) {
            factor1 = a;
        }
        else if (row == 1) {
            factor1 = a-1;
            factor2 = c;
        } else {
            factor1 = a-1;
        }

        /* Initialize each element of the pointer list */
        for (col = 0; col < size_x; col++) {
            /* ignore first cell */
            if (row == 0 && col == 0) {
                continue;
            }
            /* set row 0 to factor 1 */
            else if (row == 0) {
                list[row][col] = factor1;
            }
            /* set col 0 to factor 2 */
            else if (col == 0) {
                list[row][col] = factor2;
            }
            /* otherwise set the sum of factors */
            else {
                list[row][col] = factor1 * factor2;
            }
            factor1++;
        }
        if (row > 0 && col > 0) {
            factor2++;
        }
    }

    kert->a = a;
    kert->b = b;
    kert->c = c;
    kert->d = d;
    kert->kertotaulu = list;

    return kert;
}


void tuhoaKertotaulu(Kertotaulu *kt) {
    int i = 0;
    int size_y = kt->d - kt->c + 2;

    for (i = 0; i < size_y; i++) {
        free(kt->kertotaulu[i]);
    }

    free(kt->kertotaulu);
    free(kt);

}

