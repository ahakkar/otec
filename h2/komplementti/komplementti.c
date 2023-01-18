/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T1 Kahden komplementti
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

/* 100101011 */
int main(int argc, char *argv[]) {
    char sign = argv[1][0];
    int i = 0;
    int len = (int) strlen(argv[1]);
    int sum = 0;

    do {
        if (argv[1][i] == '1') {
            /* first char 1 = negative, 0 = positive */
            if (sign == '1' && i == 0) {
                /* pow requires the sign to be before pow.. */
                sum += -pow(2, len-1-i);
            } else {
                sum += pow(2, len-1-i);
            }
        }
        i++;

    } while (i < len);

    printf("%d\n", sum);


    return 0;
}
