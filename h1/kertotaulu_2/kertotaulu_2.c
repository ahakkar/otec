/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T9 kertotaulu #2
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
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

void print_row(int a, int b, int c, int *width_ptr) {
    /* row multi*/
    printf("%*d", *width_ptr, c);
    while (a <= b) {
        printf("%*d", *width_ptr, a*c);
        a++;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    int width = count_digits(b*d)+1;
    int *width_ptr = &width;

    int cur_col = a;
    int cur_row = c;

    if (argc != 5) {
        printf("invalid amount of params\n");
        return 1;
    }

    /* first row 5 15 3 7 */
    printf("%*c", width, ' ');
    while (cur_col <= b) {
        printf("%*d", width, cur_col);
        cur_col++;
    }
    printf("\n");

    while(cur_row <= d) {
        print_row(a, b, cur_row, width_ptr);
        cur_row++;
    }
    return 0;

}
