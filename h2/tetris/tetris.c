/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T9 Tetris
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <string.h>

const char EMPTY_ROW[10] = "          ";
const char FULL_ROW[10] = "xxxxxxxxxx";

/* Searches for empty or full rows:
 *  Empty row: increment row_to_clear, so we can ignore already
 *             cleared rows in beginning
 *  Full row: move all rows above one row lower
 *
 * After moving the rows, we clear one row starting from row_to_clear
 */
void paivita2(char ruudukko[20][10]) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 1;

    int row_to_clear = 0;
    int iterate_rows_above = 0;
    int rows = 20;
    int cols = 10;
    char str[11];

    /* loop through each row */
    for (i = 0; i < rows; i++) {
        /* construct a string from row's contents */
        for (j = 0; j < cols; j++) {
            str[j] = ruudukko[i][j];
        }
        str[cols] = '\0'; /* add null terminator */

        /* increment the starting row if we find empty rows at beginning */
        if(strcmp(str, EMPTY_ROW) == 0) {
            row_to_clear++;
        }

        /* if row is full, replace it with row above, or empty row */
        if(strcmp(str, FULL_ROW) == 0) {
            iterate_rows_above = i;
            k = 0;
            l = 1;

            /* move every row above current row, one row lower*/
            while (iterate_rows_above > 1) {
                for (j = 0; j < cols; j++) {
                    ruudukko[i-k][j] = ruudukko[i-l][j];
                }
                iterate_rows_above--;
                k++;
                l++;
            }

            /* clear a row */
            for (j = 0; j < cols; j++) {
                ruudukko[row_to_clear][j] = ' ';
            }

            row_to_clear++;
        }
    }
}

/* refactored version using memcpy and memset to read and write row contents */
void paivita(char ruudukko[20][10]) {
    /* use local variables instead of global */
    const char EMPTY_ROW[] = "          ";
    const char FULL_ROW[] = "xxxxxxxxxx";
    const int ROWS = 20;
    const int COLS = 10;

    char row_content[11];

    int row_to_clear = 0;
    int row = 0;
    int i = 0;

    /* iterate over each row */
    for (row = 0; row < ROWS; row++) {
        /* read current row to row_content variable */
        memcpy(row_content, ruudukko[row], COLS);

        row_content[COLS] = '\0'; /* add null terminator */

        /* Now compare the current row_contents with empty and full rows:
          First, increment the starting row if we find empty rows at beginning */
        if (strncmp(row_content, EMPTY_ROW, COLS) == 0) {
            row_to_clear++;
        }

        /* Secondly, if row is full, replace it with row above, or empty row */
        if (strncmp(row_content, FULL_ROW, COLS) == 0) {

            /* move every row above current row, one row lower*/
            for (i = row; i > 0; i--) {
                memcpy(ruudukko[i], ruudukko[i-1], COLS);
            }

            /* clear a row */
            memset(ruudukko[row_to_clear], ' ', COLS);

            row_to_clear++;
        }
    }
}




