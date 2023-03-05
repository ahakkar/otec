/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T5 Fibonaccin luvut #2
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 1
#define EXTEND_FACTOR 2

/* custom memory allocation funcs which brutally kill the program if mem (re)alloc fails */
#define XMALLOC(size) allocate_memory((size), __LINE__)
#define XREALLOC(ptr, size) reallocate_memory((ptr), (size), __LINE__)

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

char *fib_jono_mj(unsigned int n) {
    unsigned int num1 = 0, num2 = 1, fib;
    size_t size = INITIAL_SIZE;  /* initial size of the string */
    size_t len = 0;   /* length of the string */
    unsigned int i;
    unsigned int required_size;
    unsigned int printed = 1;
    char temp[20];
    char* str = (char*) XMALLOC(size * sizeof(char));  /* allocate memory for the string */

    if (n == 0) {
        str[0] = '\0';
        return str;
    }

    /* append the first two Fibonacci numbers */
    size *= 2;
    str = (char*) XREALLOC(str, size * sizeof(char));
    size = 8;
    str = (char*) XREALLOC(str, size * sizeof(char));
    len += sprintf(str + len, "0, 1");
    num1 = 0;
    num2 = 1;

    /* generate and append the remaining Fibonacci numbers */
    for (i = 2; i < n; i++) {
        fib = num1 + num2;
        num1 = num2;
        num2 = fib;

        sprintf(temp, " %d", fib);

        required_size = strlen(temp) + 1;  /* +1 for null terminator */

        /* double the size of the string if neccessary */
        if (len + required_size > size) {
            size *= EXTEND_FACTOR;
            str = (char*) XREALLOC(str, size * sizeof(char));
        }

        if(printed) {
           len += sprintf(str + len, ",");
        }

        /* append fibonacci number */
        len += sprintf(str + len, "%s", temp);

        printed = 1;
    }

    /* printf("size: %llu, length: %llu\n", size, len); */
    str = XREALLOC(str, len * sizeof(char) + 1);
    return str;
}

