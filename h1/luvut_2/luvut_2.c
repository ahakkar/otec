/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T6 luvut_2
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int EXTRA_ARGS = 3;

bool check_num(int num, int amt, char *argv[]) {
    int i = 0;
    while (i < amt) {
        /* printf("(%d, %d)", num, atoi(argv[i+amt])); */
        if (num % atoi(argv[i+EXTRA_ARGS]) == 0) {
            return false;
        }
        i++;
    }

    return true;
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int amt = argc-EXTRA_ARGS;
    bool first = true;

    while (a <= b) {
        if (check_num(a, amt, argv)) {
            if (first) {
                printf("%d", a);
                first = false;
            } else {
                printf(" %d", a);
            }
        }
        a++;
    }
    if(!first) {
        printf("\n");
    }
    return 0;

}

