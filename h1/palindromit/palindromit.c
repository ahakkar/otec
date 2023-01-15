/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T12 Palindromit
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

bool check_pal(char word[]) {    
    int word_len = strlen(word);
    int i = 0;

    for(; i < word_len/2; i++) {
        if (tolower(word[i]) != tolower(word[word_len-i-1])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    int i = 1;

    for(; i < argc; i++) {        
        printf("\"%s\": %s\n",
               argv[i],
               check_pal(argv[i]) ? "on palindromi" : "ei ole palindromi");
    }

    return 0;    
}
