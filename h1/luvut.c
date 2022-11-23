/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T2
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdbool.h>

int main() {  
    int i = 0;
    bool first = true;

    while (i < 100) {
        i++;
        if (i % 3 == 0 || i % 2 == 0 || i % 5 == 0) {
            continue;
        }
        if (i == 0) {
            printf("%d", i);
            first = false;  
            continue; 
        }
        printf(" %d", i);        
    }    
    printf("\n");
    return 0;
}