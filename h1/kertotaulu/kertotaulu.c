/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T3 kertotaulu
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdbool.h>

int main() {

    int MAX_VALUE = 15;
    int num = 1;
    int multi = 1;

    printf("   x");

    while (num < MAX_VALUE+1) {
        printf("%4d", num);
        num++;
    }
    printf("\n");

    num = 1;

    while (multi < MAX_VALUE+1) {
        printf("%4d", multi);
        while (num < MAX_VALUE+1) {
            printf("%4d", multi*num);
            num++;
        }
        printf("\n");
        multi++;
        num = 1;
    }
    return 0;

}
