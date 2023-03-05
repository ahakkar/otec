/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T6 Kertotaulu #4
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        return 1;
    }
    uint a = atoi(argv[1]);
    uint b = atoi(argv[2]);
    uint c = atoi(argv[3]);
    uint d = atoi(argv[4]);

    char **kertotaulu = luo_kertotaulu_mjt(a, b, c, d);
    uint i = 0;

    for(i = 0; i <= (d-c+1); ++i) {
        printf("%s\n", kertotaulu[i]);
        free(kertotaulu[i]);
    }

    free(kertotaulu);

    return 0;
}
