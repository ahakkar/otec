/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T10 Kolmiulotteiset pisteet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "piste3d.h"
#include <math.h>
#include <stdio.h>


double etaisyys(Piste3D a, Piste3D b) {
    return sqrt(
                pow(a.x-b.x, 2) +
                pow(a.y-b.y, 2) +
                pow(a.z-b.z, 2)
                );
}

void tulosta(Piste3D p, int res) {
    printf("(%.*f, %.*f, %.*f)", res, p.x, res,  p.y, res, p.z);
}
