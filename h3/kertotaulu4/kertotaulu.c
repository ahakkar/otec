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


int * calc_col_widths(uint size_x, uint x_min, uint y_max) {
    char buffer[20];
    int* col_widths = XMALLOC(size_x * sizeof(int)); /* sprintf returns int */
    uint i, cur_x;

    /* calculate first col's width outside for loop */
    col_widths[0] = sprintf(buffer, "%d", y_max);

    /* - Largest col value is current x value * y_max.
     * - Add an extra char to other cols for spacing. */
    for(i = 1, cur_x = x_min; i < size_x; i++, cur_x++) {
        col_widths[i] = sprintf(buffer, "%d", cur_x*y_max) + 1;
    }
    return col_widths;
}


int calc_row_width(int size_x, int *col_widths) {
    int i, row_width = 0;

    for(i = 0; i < size_x; i++) {
        row_width += col_widths[i];
    }
    return row_width;
}


char ** luo_kertotaulu_mjt(uint x_min, uint x_max, uint y_min, uint y_max) {
    char **table;
    int *col_widths;
    int size_x, size_y, row, col, factor1, factor2, row_width, offset;

    if (x_min > x_max || y_min > y_max) { return NULL; }

    size_x = x_max-x_min + EXTRA_SPACE;
    size_y = y_max-y_min + EXTRA_SPACE;

    /* Calculate widths and allocate memory for table */
    col_widths = calc_col_widths(size_x, x_min, y_max);
    row_width = calc_row_width(size_x, col_widths);
    table = (char **) XMALLOC(size_y * sizeof(char *));

    set_row_lables(table, size_y, y_min-1, col_widths, row_width);
    set_column_labels(table, size_x, x_min, col_widths);

    /* Populate the table with nums */
    for (row = 1, factor2 = y_min; row < size_y; row++, factor2++) {
        factor1 = x_min;        /* Reset factor1 and offset every row */
        offset = col_widths[0]; /* Reset offset every row */

        for (col = 1; col < size_x; col++, factor1++) {
            offset += sprintf(table[row] + offset, "%*d", col_widths[col], factor1 * factor2);
        }
    }

    free(col_widths);
    return table;
}


void set_row_lables(char ** table, int size_y, int factor2, int *col_widths, int row_width) {
    int row;
    for (row = 0; row < size_y; row++, factor2++) {
        /* Allocate memory for rows while setting the row lables */
        table[row] = (char*) XMALLOC((row_width + 1) * sizeof(char));
        row == 0 ? sprintf(table[row], "%*s", col_widths[0], "")
                 : sprintf(table[row], "%*d", col_widths[0], factor2);
    }
}


void set_column_labels(char ** table, int size_x, int factor1, int *col_widths) {
    int col;
    int offset = col_widths[0];
    for (col = 1; col < size_x; col++, factor1++) {
        offset += sprintf(table[0] + offset, "%*d", col_widths[col], factor1);
    }
}


/* a go at refactored version */
char ** luo_kertotaulu_mjt2(uint x_min, uint x_max, uint y_min, uint y_max) {
    /* Initialize vars */
    char **table;
    int *col_widths;
    int size_x, size_y, row, col, factor1, factor2, row_width, offset;

    /* Return if params are bad */
    if (x_min > x_max || y_min > y_max) { return NULL; }

    size_x = x_max-x_min + EXTRA_SPACE;
    size_y = y_max-y_min + EXTRA_SPACE;

    /* first calculate the width for each column */
    col_widths = calc_col_widths(size_x, x_min, y_max);
    row_width = calc_row_width(size_x, col_widths);

    /* allocate memory for rows */
    table = (char **) XMALLOC(size_y * sizeof(char *));

    /* allocate memory for cols and set row labels */
    factor2 = y_min-1 /* -1 because of the 0,0 case which is empty */;
    for (row = 0; row < size_y; row++) {
        table[row] = (char*) XMALLOC((row_width + 1) * sizeof(char));

        row == 0 ? sprintf(table[row], "%*s", col_widths[0], "")
                 : sprintf(table[row], "%*d", col_widths[0], factor2);

        factor2++;
    }

    /* set column labels */
    factor1 = x_min;
    offset = col_widths[0];
    for (col = 1; col < size_x; col++) {
        offset += sprintf(table[0] + offset, "%*d", col_widths[col], factor1);
        factor1++;
    }

    /* Populate the table with nums */
    factor2 = y_min;
    for (row = 1; row < size_y; row++) {
        factor1 = x_min;        /* Reset factor1 and offset every row */
        offset = col_widths[0]; /* row label column's width */

        /* Initialize each element of the pointer list */
        for (col = 1; col < size_x; col++) {
            offset += sprintf(table[row] + offset, "%*d", col_widths[col], factor1 * factor2);
            factor1++;
        }
        factor2++;
    }

    free(col_widths);
    return table;
}


/* original version */
char ** luo_kertotaulu_mjt3(uint x_min, uint x_max, uint y_min, uint y_max) {
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
