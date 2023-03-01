/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T4 Bittiesityksen kääntö
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

/*
 This code first stores the value pointed to by ptr in a local variable x
 The loop then iterates over each bit in x, from the least significant
 bit to the most significant bit. For each bit, the result variable is
 updated by first isolating the bit with the & operator and the 1 value,
 and then shifting it to the appropriate position with the << operator.
 Finally, the result is stored back into the memory location pointed
 to by ptr.

 This code performs an in-place bit swap, so the original value pointed to by
 ptr will be modified. Note that this assumes that ptr points to a valid
 location in memory, and that you have the necessary permissions to modify
 the memory location. If you don't, the operation may result in a segmentation
 fault or other undefined behavior.
*/

void kaannaScharBitit(signed char *ptr) {
    char x = *ptr;
    char result = 0;
    int i = 0;

    for (; i < CHAR_BIT; ++i) {
        result |= ((x >> i) & 1) << (CHAR_BIT-1 - i);
    }

    *ptr = result;
}

void tulosta_schar_bitit(signed char x) {
    int i;
    int j = 0;
    char str[CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (i = CHAR_BIT-1; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < CHAR_BIT; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

void kaannaShortBitit(short *ptr) {
    static const int SIZE = sizeof(short int)*CHAR_BIT;
    short x = *ptr;
    short result = 0;
    int i = 0;

    for (; i < SIZE; ++i) {
        result |= ((x >> i) & 1) << (SIZE-1 - i);
    }

    *ptr = result;
}

void tulosta_short_bitit(short x) {
    int i;
    int j = 0;
    char str[sizeof(short)*CHAR_BIT];
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (i = sizeof(short)*CHAR_BIT-1; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(short)*CHAR_BIT; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}


void kaannaIntBitit(int *ptr)
{
    static const int SIZE = sizeof(int)*CHAR_BIT;
    int x = *ptr;
    int result = 0;
    int i = 0;

    for (; i < SIZE; ++i) {
        result |= ((x >> i) & 1) << (SIZE-1 - i);
    }

    *ptr = result;
}

void tulosta_int_bitit(int x) {
    int i;
    int j = 0;
    char str[sizeof(int)*CHAR_BIT];
    memset(str, 0, sizeof(str)); /* initialize array with zeroes */
    printf("%d\n", x);

    /* convert int to binary string char by char */
    for (i = sizeof(int)*CHAR_BIT-1; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(int)*CHAR_BIT; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}



void kaannaLongBitit(long *ptr)
{
    static const int SIZE = sizeof(long)*CHAR_BIT;
    long x = *ptr;
    long result = 0;
    int i = 0;

    for (; i < SIZE; ++i) {
        result |= ((x >> i) & 1) << (SIZE-1 - i);
    }

    *ptr = result;
}

void tulosta_long_bitit(long x) {
    int i;
    int j = 0;
    char str[sizeof(long)*CHAR_BIT];
    printf("%ld\n", x);

    /* convert int to binary string char by char */
    for (i = sizeof(long)*CHAR_BIT-1; i >= 0; i--) {
        if ((x >> i) & 1) {
            str[j] = '1';
        } else {
            str[j] = '0'; }
        j++;
    }
    /* print the binary string char by char */
    for (i = 0; i < (int) sizeof(long)*CHAR_BIT; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

#include <limits.h>
