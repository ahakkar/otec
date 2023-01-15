/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T14 Geometria
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

#include "geometria.h"

int main(int argc, char *argv[])
{
    int i = 1;
    printf("Piin arvo: %0.19Lf\n", PII);
    for (; i < argc; i++) {
        printf("Säteen %f omaavan ympyrän ala ja pallon tilavuus: %0.10f ja %0.10f\n",
               atof(argv[i]),
               ympyranAla(atof(argv[i])),
               pallonTilavuus(atof(argv[i]))
               );
        printf("Säteen %f omaavan ympyrän piiri on %0.10Lf\n",
               atof(argv[i]),
               2*PII*atof(argv[i])
               );
    }


    return 0;
}
