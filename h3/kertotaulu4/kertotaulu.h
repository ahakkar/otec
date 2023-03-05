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

void* allocate_memory(size_t size, int line);

void* reallocate_memory(void* ptr, size_t size, int line);

int * calc_col_widths(uint size_x, uint x_min, uint y_max);

int calc_row_width(int size_x, int *col_widths);

char ** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d);


#endif
