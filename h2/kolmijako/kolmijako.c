/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T15 Kolmijako
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "kolmijako.h"
#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE_1 12
#define TABLE_SIZE_2 7
bool debug = true;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2, int *p1, int *p2) {
    IntPari res;
    typedef unsigned int ui;
    int pienet1 = 0;
    int pienet2 = 0;
    ui i = 0 ;

    /* Vaihda vipuindeksit vipu1 ja vipu2 keskenään, jos t[vipu1] > t[vipu2]. */
    if (t[vipu1] > t[vipu2]) {
        swap(&vipu1, &vipu2);
    }

    if (debug) {
        printf("vipu1: %d, vipu2: %d\n", vipu1, vipu2);
        printf("t[vipu1]: %d t[vipu2]: %d \n\n", t[vipu1], t[vipu2]);
    }

    /* Selaa taulukko t alusta loppuun niin, että vertaat kunkin
     * indeksin i kohdalla arvoja t[i] ja t[vipu1] keskenään.
     * Jos t[i] < t[vipu1], vaihda alkiot t[i] ja t[pienet1]
     * keskenään ja kasvata arvoa pienet1 yhdellä. Lisäksi huomioitavaa:
     * jos vaihdon yhteydessä sattuu pätemään vipu1 == pienet1 tai
     * vipu2 == pienet1 eli vaihto siirtää vipualkion indeksin i
     * kohdalle, pitää asianomaisen vipualkion indeksi vipu1 tai
     * vipu2 päivittää arvoon i.
     */

    for(i = 0; i < n; i++) {
        if (t[i] < t[vipu1]) {
            swap(&t[i], &t[pienet1]);
            pienet1++;

            /* printf("swapped %d: %d & %d\n", i, t[i], t[pienet1]); */

            if (vipu1 == pienet1) {
                vipu1 = i;
            }
            else if (vipu2 == pienet1) {
                vipu2 = i;
            }
        }
    }

    swap(&t[pienet1], &t[vipu1]);
    /* missing some vipu2 adjustments */

    if (vipu2 == pienet1) {
        vipu2 = pienet1;
    }

    pienet2 = pienet1 + 1;
    for(i = pienet2; i < n; i++) {
        /* printf("vipu2: %d\n", t[vipu2]); */
        if (t[i] < t[vipu2]) {
            swap(&t[i], &t[pienet2]);
            pienet2++;
        }

        if (vipu2 == pienet2) {
            vipu2 = i;
        }
    }

    /*
    for(i = 0; i < TABLE_SIZE; ++i) {
        printf(" %d,", t[i]);
    }
    putchar("\n");
    */

    swap(&t[pienet2], &t[vipu2]);

    *p1 = pienet1;
    *p2 = pienet2;
    res.x = pienet1;
    res.y = pienet2;

    return res;
}

int partition(int arr[], int low, int high, int pivot, int *count) {
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            (*count)++;
            i++;
            j--;
        }
    }

    return i;
}

int quicksort(int arr[], int low, int high, int count) {
    if (low < high) {
        int pivot = arr[low];
        int p = partition(arr, low, high, pivot, &count);
        count = quicksort(arr, low, p - 1, count);
        count = quicksort(arr, p, high, count);
    }
    return count;
}


IntPari kolmijako2(unsigned int n, int t[], int index1, int index2, int *p1, int *p2) {
    IntPari res;
    int piste1 = 0;
    int piste2 = 0;
    int piste3 = 0;

    if (t[index1] > t[index2]) {
        printf("swapping\n");
        swap(&t[index1], &t[index2]);
        swap(&index1, &index2);
    }

    printf("%d %d\n", index1, index2);

    piste1 = quicksort(t, 0, n-1, piste1);
    /*
    piste2 = quicksort(t, index1 + 1, index2, piste2);
    piste3 = quicksort(t, index2 + 1, n-1, piste3);
    */

    printf("p1: %d\n", piste1);

    *p1 = piste1;
    *p2 = piste2;
    res.x = piste1;
    res.y = piste2;
    return res;
}


int main(void)
{
    /*test 1
    int test1[TABLE_SIZE_1] = {1, 7, 4, 5, 2, 8, 14, 3, 6, 13, 24, 9};
    int x = 0;
    int y = 0;

    IntPari ip = kolmijako(TABLE_SIZE_1, test1, 9, 3, &x, &y);
    int i = 0;

    printf("pienet1: %d ja %d\npienet2: %d ja %d\n", x, ip.x, y, ip.y);

    for(i = 0; i < TABLE_SIZE_1; ++i) {
        if (debug) { printf(" %d,", test1[i]); }
    }
    */


    int x = 0;
    int y = 0;
    int i = 0;

    /* test 2*/
    int test2[7] = {1, 7, 9, 5, 2, 8, 4};
    IntPari ip2 = kolmijako2(7, test2, 4, 1, &x, &y);
    printf("pienet1: %d ja %d\npienet2: %d ja %d\n", x, ip2.x, y, ip2.y);

    for(i = 0; i < TABLE_SIZE_2; ++i) {
        if (debug) { printf(" %d,", test2[i]); }
    }


    return 0;
}

