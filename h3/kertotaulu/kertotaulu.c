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

    kert->a = a;
    kert->b = b;
    kert->c = c;
    kert->d = d;

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


int main(int argc, char *argv[]) {
    if (argc < 5) {
        return 0;
    }

    Kertotaulu *kt = luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    uint i = 0;
    uint j = 0;

    for(i = 0; i <= (kt->d - kt->c + 1); ++i) {
        for(j = 0; j <= (kt->b - kt->a + 1); ++j) {
            if((i > 0) || (j > 0)) {
                printf("%4u", kt->kertotaulu[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
    tuhoaKertotaulu(kt);

    return 0;
}

