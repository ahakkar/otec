/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T11 Yhtalö
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int DEC_PRECISION = 3;

int main(int argc, char *argv[])
{
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    double res = sqrt(b*b - 4*a*c);

    if (res > 0) {
        printf("%.3f %.3f\n", (-b-res)/(2*a), (-b+res)/(2*a) );
    }
    else if (res == 0) {
        printf("%.3f\n", -b/(2*a));
    }
    else {
        printf("Ei ratkaisua\n");
    }

    return 0;
}
