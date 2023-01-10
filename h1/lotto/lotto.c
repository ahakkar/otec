/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T8 lotto
 *
 * Antti Hakkarainen
 * K79735 vqanha
 * antti.i.hakkarainen@tuni.fi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int EXTRA_ARGS = 2;


void print_arr(int *arr) {
    int i = 0;
    for (i = 0; i < 7; i++) {
        printf(" %d", arr[i]);
    }
}

int main(int argc, char *argv[]) {
    int solution[7] = {0};
    int guess[7] = {0};
    int hits[7] = {0};
    int correct = 0;
    int i = 0;
    int j = 0;

    if (argc != 15) {
        printf("Need to provide exactly 14 int numbers.\n");
        return 1;
    }

    for (i = 0; i < 7; i++) {
        solution[i] = atoi(argv[i+1]);
        guess[i] = atoi(argv[i+8]);
    }

    printf("Voittorivi:");
    print_arr(solution);
    printf("\n");
    printf("Lottorivi:");
    print_arr(guess);
    printf("\n");

    /* compare guesses to solution */
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if(guess[i] == solution[j]) {
                hits[i] = guess[i];
                correct++;
            }
        }
    }

    /* print results */
    if (correct > 0) {
        printf("%d oikein:", correct);
        for (i = 0; i < 7; i++) {
            if (hits[i] != 0) {
                printf(" %d", hits[i]);
            }
        }
        printf("\n");
    }
    else {
        printf("Ei yhtään oikein!\n");
    }

    return 0;

}
