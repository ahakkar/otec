/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T17 Anagrammit
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

#include "anagrammit.h"

int main()
{
    printf("%d\n", anagrammeja("arvo", "varo"));
    printf("%d\n", anagrammeja("ilta", "talli"));
    printf("%d\n", anagrammeja("elvis", "lives"));
    printf("%d\n", anagrammeja("abababbbaabbaabb","ababababbaabbaba"));
    printf("%d\n", anagrammeja("bbaabaabababbaababab" ,"aabbaabbaabbaabbaabb"));
    return 0;
}
