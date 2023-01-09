/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T4 ascii
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    while (a < b+1) {
        printf("%d: %c\n", a, a);
        a++;
    }
    return 0;

}
