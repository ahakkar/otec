/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T19 Etumerkittömät
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "unsigned.h"
#include <limits.h>
#include <stdio.h>

void ucharIntervalli(unsigned char sade, unsigned char askel) {

    int i = 0;
    unsigned char num;

    printf("unsigned char:");

    while (-sade + i*askel < 0) {
        num = UCHAR_MAX - sade + 1 + i*askel;
        printf(" %d", num);
        i++;
    }

    num = UCHAR_MAX - sade + 1 + i*askel;

    while (num < sade) {
        num = UCHAR_MAX - sade + 1 + i*askel;
        if (num <= sade) {
            printf(" %d", num);
        }
        i++;
    }

    putchar('\n');
}

void ushortIntervalli(unsigned short sade, unsigned short askel) {

    unsigned short num;
    int i = 0;

    printf("unsigned short:");

    while (-sade + i*askel < 0) {
        num = USHRT_MAX - sade + 1 + i*askel;
        printf(" %d", num);
        i++;
    }

    num = USHRT_MAX - sade + 1 + i*askel;

    while (num < sade) {
        num = USHRT_MAX - sade + 1 + i*askel;
        if (num <= sade) {
            printf(" %d", num);
        }
        i++;
    }

    putchar('\n');
}


void uintIntervalli(unsigned int sade, unsigned int askel) {

    int i = 0;
    unsigned int num = -sade + i*askel;

    printf("unsigned int:");

    while (num - askel > 0 && i < 10) {
        printf(" %u", num);
        i++;
        num = -sade + i*askel;
    }

    while (num < sade) {
        num = UINT_MAX - sade + 1 + i*askel;
        if (num <= sade) {
            printf(" %u", num);
        }
        i++;
    }

    putchar('\n');

}

void ulongIntervalli(unsigned long long sade, unsigned long long askel) {

    unsigned long num;
    unsigned long i = 0;

    printf("unsigned long:");

    num = ULONG_MAX - sade + 1 + i*askel;

    while (num < sade) {
        num = ULONG_MAX - sade + 1 + i*askel;
        if (num <= sade) {
            printf(" %lu", num);
        }
        i++;
    }

    putchar('\n');
}
