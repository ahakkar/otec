/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T7 Arvojen vaihto
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "vaihto.h"


int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);

    printf("%d %d %d\n", x, y, z);
    vaihda(&x, &y);

    printf("%d %d %d\n", x, y, z);
    jarjesta(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}

/*
  - Lue parametrin a osoittama arvo tavalliseen int-tyyppiseen apumuuttujaan.
  - Aseta parametrin b osoittama arvo parametrin a osoittamaan muuttujaan.
  - Aseta kohdan 1 apumuuttujan arvo parametrin b osoittamaan muuttujaan.
 */
void vaihda(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void jarjesta(int *a, int *b, int *c)
{
    if (*a > *b) {
        vaihda(a, b);
    }
    if (*b > *c) {
        vaihda(b, c);
    }
    if (*a > *b) {
        vaihda(a, b);
    }
}
