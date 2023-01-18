/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T2 IEEE 754 -liukuluvut
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

int complement(int param, char *argv[])
{
    static const int BITS = 8+1; /* actually 8 */
    static const int BIAS = 127;
    int i = 1;
    int sum = 0;

    do {
        if (argv[param][i] == '1') {
            sum += pow(2, BITS-1-i);
        }
        i++;

    } while (i < BITS);

    return sum-BIAS;
}

double mantissa(int param, char *argv[])
{
    static const int BITS = 23; /* actually 24 but.. */
    int i = 0;
    double weight = 2;
    double sum = 0.0;

    for (; i < BITS; i++) {
        if (argv[param][9+i] == '1') {
            sum += (1/weight);
        }
        weight *= 2;
    }

    return sum+1;
}

double result(double val_mantissa, int val_complement, int sign) {
    return pow(-1, sign) * val_mantissa * pow(2, val_complement);
}

int main(int argc, char *argv[]) {
    int i = 1;
    int val_complement;
    double val_mantissa;
    int sign;
    double num;

    for(; i < argc; i++) {
        val_complement = complement(i, argv);
        val_mantissa = mantissa(i, argv);
        sign = argv[i][0] == '1' ? 1 : 0;
        num = result(val_mantissa, val_complement, sign);

        printf("%.15f\n", val_mantissa);
        printf("%d\n", val_complement);
        printf("%c\n", sign == 1 ? '-' : '+');
        printf("%.15f\n", num);
    }

    return 0;
}
