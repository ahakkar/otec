/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H4 T8 Merkkijonojen yhdistäminen
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *yhdista(const char *mj, ...) {
    va_list args;
    const char *temp;
    char *result;
    size_t len = 0;

    /* Calculate the total length of the strings */
    va_start(args, mj);
    temp = mj;
    while (temp != NULL) {
        len += strlen(temp);
        temp = va_arg(args, const char*);
    }
    va_end(args);

    /* Allocate memory for the resulting string */
    result = (char *) malloc(len + 1);
    if (!result) return NULL;  /* Failed to allocate memory */
    
    /* Concatenate the strings */
    result[0] = '\0'; /* Ensure the result string is empty */
    va_start(args, mj);
    temp = mj;
    while (temp != NULL) {
        strcat(result, temp);
        temp = va_arg(args, const char*);
    }
    va_end(args);

    return result;
}