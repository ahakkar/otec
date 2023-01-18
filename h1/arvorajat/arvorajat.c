/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T18 Arvorajat
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


/* Toteuta ohjelma, joka tulostaa kunkin saamansa varsinaisen
 * komentoriviparametrin osalta tiedon, mihin kaikkiin
 * kokonaislukutyypeistä signed char, unsigned char, short int,
 * unsigned short int ja int kyseisen komentoriviparametri
 * n esittämä luku voitaisiin tallettaa rikkomatta kyseisen
 * muuttujatyypin lukuvälin ala- tai ylärajaa.
 */

/* intro struct for limit data*/
struct limit {
    char str[20];
    int min;
    int max;
};

/* create array with limits */
static const struct limit limits[5] = {
    {"signed char", SCHAR_MIN, SCHAR_MAX },
    {"unsigned char", 0, UCHAR_MAX },
    {"short int", SHRT_MIN, SHRT_MAX },
    {"unsigned short int", 0, USHRT_MAX},
    {"int", INT_MIN, INT_MAX}
};

static const int MAX_LIMITS = 5;

int main(int argc, char *argv[])
{
    int value;
    int i = 1; 
    int j = 0;
    bool first = true;

    /* loop through the cmdline params, once */
    for (; i < argc; i++) {
        value = atoi(argv[i]);
        first = true;

        printf("%d:", value);

        /* loop through the defined limits, multiple times */
        for (j = 0; j < MAX_LIMITS; j++) {
            if (value >= limits[j].min && value <= limits[j].max) {
                if (!first) putchar(',');
                else first = false;
                printf(" %s", limits[j].str);
            }
        }
        /* new line for new number */
        putchar('\n');
    }

    return 0;
}
