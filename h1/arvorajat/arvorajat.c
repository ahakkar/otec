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

int main(int argc, char *argv[])
{
    int value;
    int i = 1;
    int sep = -1;

    for (; i < argc; i++) {
        value = atoi(argv[i]);
        sep = -1;

        printf("%d:", value);

        /* research the amount of separators needed */
        if (value >= -128 && value <= 127) {
            sep++;
        }
        if (value >= 0 && value <= 255) {
            sep++;
        }
        if (value >= -32768 && value <= 32767) {
            sep++;
        }
        if (value >= 0 && value <= 65535) {
            sep++;
        }
        if (value >= -2147483647 && value <= 2147483647) {
            sep++;
        }

        if (value >= SCHAR_MIN && value <= SCHAR_MAX) {
            printf(" signed char");
            if (sep > 0) {
                putchar(',');
                sep--;
            }
        }
        if (value >= 0 && value <= UCHAR_MAX) {
            printf(" unsigned char");
            if (sep > 0) {
                putchar(',');
                sep--;
            }
        }
        if (value >= SHRT_MIN && value <= SHRT_MAX) {
            printf(" short int");
            if (sep > 0) {
                putchar(',');
                sep--;
            }
        }
        if (value >= 0 && value <= USHRT_MAX) {
            printf(" unsigned short int");
            if (sep > 0) {
                putchar(',');
                sep--;
            }
        }
        if (value >= INT_MIN && value <= INT_MAX) {
            printf(" int");
            if (sep > 0) {
                putchar(',');
                sep--;
            }
        }

        /* new line for new number */
        putchar('\n');

    }

    return 0;
}
