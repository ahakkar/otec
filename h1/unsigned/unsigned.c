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
        num = -sade + i*askel;
        printf(" %d", num);
        i++;
    }

    num = -sade + i*askel;

    while (num < sade) {
        num = -sade + i*askel;
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
        num = -sade + i*askel;
        printf(" %d", num);
        i++;
    }

    num = -sade + i*askel;

    while (num < sade) {
        num = -sade + i*askel;
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

    while (num - askel < num) {
        printf(" %u", num);
        i++;
        num = -sade + i*askel;
    }

    while (num < sade) {
        num = -sade + i*askel;
        if (num <= sade) {
            printf(" %u", num);
        }
        i++;
    }

    putchar('\n');

}

void ulongIntervalli(unsigned long sade, unsigned long askel) {

    unsigned long i = 0;
    unsigned long num = -sade + i*askel;

    printf("unsigned long:");

    while (num - askel < num) {
        printf(" %lu", num);
        i++;
        num = -sade + i*askel;
    }

    while (num < sade) {
        num = -sade + i*askel;
        if (num <= sade) {
            printf(" %lu", num);
        }
        i++;
    }

    putchar('\n');
}
