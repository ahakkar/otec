/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T19 Etumerkittömät
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
#include <limits.h>

#include "unsigned.h"

int main()
{    
    ucharIntervalli(150, 50);
    ucharIntervalli(40, 75);


    ushortIntervalli(45000, 15000);
    ushortIntervalli(65535, 65535);

    uintIntervalli(3300000000, 1100000000);
    uintIntervalli(400000, 750000);


    ulongIntervalli(9000000000000000000, 3000000000000000000);
    ulongIntervalli(400000000, 1500000000);


    return 0;
}
