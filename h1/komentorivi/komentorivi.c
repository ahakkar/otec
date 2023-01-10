/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T5 komentorivi
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i = 1;

    while (i < argc) {
        printf("%d: %s (pituus: %d)\n", i, argv[i], (int) strlen(argv[i]));
        i++;
    }
    return 0;

}
