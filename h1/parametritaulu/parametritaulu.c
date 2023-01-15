/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T13 Parametritaulu
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

int count_digits(int num) {
    int result = 0;
    while(num != 0) {
       num /= 10;
       result++;
    }
    return result;
}

void print_n(int times, char c, bool nl) {
    int i = 0;
    for (; i < times; i ++) {
        putchar(c);
    }
    if (nl) { printf("\n"); }
}

int main(int argc, char *argv[]) {

    int ROW_PADDING = 6;
    int col0_width = count_digits(argc)+1;
    int col1_width = 0;
    int i = 1;

    /* calculate col2 width */
    for (; i < argc; i++) {
        if ((int) strlen(argv[i]) > col1_width) {
            col1_width = strlen(argv[i]);
        }
    }

    /* print the table */
    print_n(ROW_PADDING+col0_width+col1_width, '#', true);

    for (i = 1; i < argc; i++) {
        printf("#%*d | %-*s #\n", col0_width, i, col1_width, argv[i]);
        /* avoid printing extra dividers */
        if (i < argc-1) {
            putchar('#');
            print_n(col0_width+1, '-', false);
            putchar('+');
            print_n(col1_width+2, '-', false);
            putchar('#');
            printf("\n");
        }
    }
    print_n(ROW_PADDING+col0_width+col1_width, '#', true);

    return 0;
}
