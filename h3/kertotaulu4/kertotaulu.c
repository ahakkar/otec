/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T6 Kertotaulu #4
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kertotaulu.h"

/* custom memory allocation funcs which brutally kill the program if mem (re)alloc fails */
#define XMALLOC(size) allocate_memory((size), __LINE__)
#define XREALLOC(ptr, size) reallocate_memory((ptr), (size), __LINE__)
#define EXTRA_SPACE 2

void* allocate_memory(size_t size, int line) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory in $function at line %d.\n", line);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* reallocate_memory(void* ptr, size_t size, int line) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory in $function at line %d.\n", line);
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

/* calculate col width for each column */
int * calc_col_widths(uint size_x, uint x_min, uint y_max) {
    char buffer[20];
    int* col_widths = XMALLOC(size_x * sizeof(int)); /* sprintf returns int */
    uint i, cur_x = 0;
    int col_width;

    cur_x = x_min;

    for(i = 0; i < size_x; i++) {
        /* calculate first col's width */
        if (i == 0) {
            col_width = sprintf(buffer, "%d", y_max);
        }
        /* Largest col value is current x value * y_max
         * add an extra char to other cols for spacing
         */
        else {
            col_width = sprintf(buffer, "%d", cur_x*y_max) + 1;
        }
        col_widths[i] = col_width;

        /* avoid widening the cols because of 1st col */
        if (i > 0) {
            cur_x++;
        }
    }

    return col_widths;
}

int calc_row_width(int size_x, int *col_widths) {
    int i, row_width = 0;
    for(i = 0; i < size_x; i++) {
        /* printf("col width %d: %d\n", i, col_widths[i]); */
        row_width += col_widths[i];
    }

    return row_width;
}

char ** luo_kertotaulu_mjt(uint x_min, uint x_max, uint y_min, uint y_max) {
    /* Initialize vars */
    char **table;
    int *col_widths;
    int size_x, size_y, row, col, factor1, factor2, row_width;
    int offset = 0;

    /* Return if params are bad */
    if (x_min > x_max || y_min > y_max) { return NULL; }

    size_x = x_max-x_min + EXTRA_SPACE;
    size_y = y_max-y_min + EXTRA_SPACE;
    factor2 = y_min;

    /* first calculate the width for each column */
    col_widths = calc_col_widths(size_x, x_min, y_max);
    row_width = calc_row_width(size_x, col_widths);

    table = (char **) XMALLOC(size_y * sizeof(char *));

    /* then populate the table with nums */
    for (row = 0; row < size_y; row++) {
        /* Allocate memory for a new pointer list*/
        table[row] = (char*) XMALLOC((row_width + 1) * sizeof(char));
        offset = 0; /* reset offset for each row */

        /* adjust factors for col and row title prints */
        factor1 = x_min - 1;
        if (row == 1) {
            factor2 = y_min;
        }

        /* Initialize each element of the pointer list */
        for (col = 0; col < size_x; col++) {

            if (row == 0 && col == 0) {
                offset += sprintf(table[row] + offset, "%*s", col_widths[col], "");
            }

            else if (row == 0) {
                offset += sprintf(table[row] + offset, "%*d", col_widths[col], factor1);
            }

            else if (col == 0) {
                offset += sprintf(table[row] + offset, "%*d", col_widths[col], factor2);
            }

            else {
                offset += sprintf(table[row] + offset, "%*d", col_widths[col], factor1 * factor2);
            }
            factor1++;
        }

        if (row > 0 && col > 0) {
            factor2++;
        }
    }

    free(col_widths);
    return table;
}
