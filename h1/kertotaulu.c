/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T3
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdbool.h>

int func_test(int param) {
    
}

int main() {  
    int i = 0;    
    bool first = true;

    while (i < 100) {
        i++;
        // don't print numbers which are divisible by 2,3,5
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