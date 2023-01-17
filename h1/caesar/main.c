/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T16 Caesarin koodi
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "caesar.h"

int main()
{
    char mj[] = "OHJELMOINNIN TEKNIIKKA PERKELE";
    char aakkosto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char korvaavat[] = "OIUGENYMSWXVALPKHBQCZDFJRT";
    caesarKoodaa(mj,
                 aakkosto,
                 korvaavat);

    printf("Tulos: %s\n", mj);

    caesarKoodaa(mj,
                 korvaavat,
                 aakkosto);

    printf("Tulos: %s\n", mj);

    return 0;
}
