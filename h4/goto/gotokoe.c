/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H4 T1 Gotokoe
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int max2D(int **t2d, int kork, int lev) {
    int x = 0, y = 0;
    int max = t2d[0][0];

    start:
        if (t2d[y][x] > max) max = t2d[y][x];       
        x++;
        if (x < lev) goto start;

        x = 0;
        y++;
        if (y < kork) goto start;

    return max;
}