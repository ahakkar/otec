
/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T16 Välilyönnit
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <ctype.h>

#include "ykkosvalit.h"

UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi) {    
    char ch;
    int was_space = 0;
    int was_newline = 0;
    int ch_written = 0;
    UintPari result = {0,0};

    FILE *read_file = fopen(syoteNimi, "r");
    FILE *write_file = fopen(tulosNimi, "w");

    if (read_file == NULL) {
        perror("Error opening file");
    }
    else if (write_file == NULL) {
        perror("Error writing to file");
    }

    while ((ch = fgetc(read_file)) != EOF) {
        result.x++;
 
        if (ch == 0x0a) { /* newline */
            fputc(0x0a, write_file);
            result.y++;
            was_newline = 1;
        }
        else if (ch == 0x20) { /* space */
            was_space = 1;
        } 
        else {
            if(!was_newline && was_space && ch_written) {
                fputc(0x20, write_file);
                result.y++;
            }
            fputc(ch, write_file);
            result.y++;
            was_space = 0;
            was_newline = 0;  
            ch_written = 1;          
        }
    }

    fclose(read_file);
    fclose(write_file);

    return result;
}

int main() {
    
    UintPari result = ykkosValit("data.input", "data.output");    
    printf("%u %u\n", result.x, result.y);

    return 0;
}
