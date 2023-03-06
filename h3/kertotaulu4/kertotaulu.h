/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T6 Kertotaulu #4
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#ifndef KERTOTAULU_H
#define KERTOTAULU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

/* custom memory allocators with macros */
void* allocate_memory(size_t size, int line);
void* reallocate_memory(void* ptr, size_t size, int line);

/* calculate col width for each column */
int * calc_col_widths(uint size_x, uint x_min, uint y_max);

/* calculate one row's width. all rows are equal length */
int calc_row_width(int size_x, int *col_widths);

/* allocate memory for rows and set row labels */
void set_row_lables(char ** table, int size_y, int factor2, int *col_widths, int row_width);

/* set column labels */
void set_column_labels(char ** table, int size_x, int factor1, int *col_widths);

/* 2nd refactored version with separate functions for label setting */
char ** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d);


#endif
