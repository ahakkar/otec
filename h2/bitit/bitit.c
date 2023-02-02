/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T3 Bittiesityksen luku
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

#include "bitit.h"

int main()
{
    int x = 2015;

    scharBitit(x);
    putchar('\n');
    shortBitit(x);
    putchar('\n');
    intBitit(x);
    putchar('\n');
    longBitit(x);

    return 0;
}

void scharBitit(signed char x)
{
    int i = CHAR_BIT-1;
    int j = 0;
    int one_count = 0;
    char str[CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    putchar('\n');
    printf("%d\n", CHAR_BIT-one_count);
    printf("%d\n", one_count);
}

void shortBitit(short x)
{
    int i = sizeof(short int)*CHAR_BIT-1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(short int)*CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(short int)*CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(short int)*CHAR_BIT-one_count);
    printf("%d\n", one_count);
}

void intBitit(int x)
{
    int i = sizeof(int)*CHAR_BIT-1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(int)*CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(int)*CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(int)*CHAR_BIT-one_count);
    printf("%d\n", one_count);
}

void longBitit(long x)
{
    int i = sizeof(long int)*CHAR_BIT-1;
    int j = 0;
    int one_count = 0;
    char str[sizeof(long int)*CHAR_BIT];
    printf("%ld\n", x);

    /* convert int to binary string char by char */
    for (; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(long int)*CHAR_BIT; i++) {
        if (str[i] == '1') {
            one_count++;
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    putchar('\n');
    printf("%d\n", (int) sizeof(long int)*CHAR_BIT-one_count);
    printf("%d\n", one_count);
}
