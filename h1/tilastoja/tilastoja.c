/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T10 Tilastoja
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

int PRINT_PRECISION = 6;

void min(int amt, char *argv[]) {
    double min_num = atof(argv[1]);
    int i = 0;

    while (i < amt) {
        if (atof(argv[i+1]) < min_num) {
            min_num = atof(argv[i+1]);
        }
        i++;
    }

    printf("Pienin: %.*f\n", PRINT_PRECISION, min_num);
}

void max(int amt, char *argv[]) {
    double max_num = atof(argv[1]);

    int i = 0;
    while (i < amt) {
        if (atof(argv[i+1]) > max_num) {
            max_num = atof(argv[i+1]);
        }
        i++;
    }

    printf("Suurin: %.*f\n", PRINT_PRECISION, max_num);
}

void unique(int amt, char *argv[]) {
    int i = 1;
    int j = 1;
    int count = 0;
    bool printed = false;

    /* do once */
    for(; i <= amt; i++) {
        count = 0;
        /* do repeatedly */
        for(j = 1; j <= amt; j++) {
            if (atof(argv[i]) == atof(argv[j])) {
                count++;
            }
        }
        if (count == 1) {
            if (!printed) {
                printf("Ainutlaatuiset:");
                printed = true;
            }
            printf(" %.*f", PRINT_PRECISION, atof(argv[i]));
        }
    }
    if(printed) {
        printf("\n");
    }
}

void most_often(int amt, char *argv[]) {


}

int main(int argc, char *argv[])
{
    min(argc-1, argv);
    max(argc-1, argv);
    unique(argc-1, argv);
    most_often(argc-1, argv);

    return 0;

}
