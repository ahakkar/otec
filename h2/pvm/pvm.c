/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T14 Päivämäärät
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "pvm.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define VKPV_AMOUNT 7

const char *KK_NIMET[KK_LKM] = {
    "tammikuu",
    "helmikuu",
    "maaliskuu",
    "huhtikuu",
    "toukokuu",
    "kesäkuu",
    "heinäkuu",
    "elokuu",
    "syyskuu",
    "lokakuu",
    "marraskuu",
    "joulukuu"};


const char KK_PAIVAT[2][KK_LKM] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

const char vkpv_str[7][3] = {"ma\0", "ti\0", "ke\0", "to\0", "pe\0", "la\0", "su\0"};


int get_date_as_int(char *vk_pv) {
    int i = 0;
    for (; i < VKPV_AMOUNT; i++) {
        if (strcmp(vk_pv, vkpv_str[i]) == 0) {
            return i;
        }
    }
    return -1;
}


Pvm * kasvataPvm(Pvm *pvm) {
    int kkv = karkausvuosi(pvm->vuosi);
    int date_as_int = get_date_as_int(pvm->vk_pv);

    /* increase days */
    if (pvm->pv + 1 > KK_PAIVAT[kkv][pvm->kk-1]) {
        pvm->pv = 1;
    }
    else {
        pvm->pv += 1;
    }


    /* increase the date string by one
       first: check for sunday */
    if (date_as_int == VKPV_AMOUNT-1) {
        memcpy(pvm->vk_pv, vkpv_str[0], 3);
    }
    /* otherwise it's not sunday */
    else {
        memcpy(pvm->vk_pv, vkpv_str[date_as_int+1], 3);
    }

    /* increase months and years if neccessary */
    if (pvm->pv == 1) {
        if (pvm->kk + 1 > 12) {
            pvm->vuosi += 1;
            pvm->kk = 1;
        }
        else {
            pvm->kk +=1;
        }
    }

    return pvm;
}


int julian_day_number(const Pvm *date) {
    int a = (14 - date->kk) / 12;
    int y = date->vuosi + 4800 - a;
    int m = date->kk + 12*a - 3;
    return date->pv + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
}

/* convert dates to julian day numbers and calculate the absolute
 * difference between them */
unsigned int pvmEro(const Pvm *a, const Pvm *b) {
    int jd1 = julian_day_number(a);
    int jd2 = julian_day_number(b);
    return abs(jd2 - jd1);
}


void tulostaPvm(Pvm *pvm) {
    printf("%s %d.%d.%d", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}



/* Vuosi on karkausvuosi, jos se on jaollinen neljällä mutta ei sadalla,
 * ja lisäksi myös silloin, jos vuosi on jaollinen neljälläsadalla.
 */
int karkausvuosi(int v) {
    if ((v%4 == 0 && v%100 != 0) || v%400 == 0 ) {
        return 1;
    }
    return 0;
}


/*
int main(int argc, char *argv[])
{
    Pvm a = {28, 2, 1900, "ke"};
    Pvm b = {28, 2, 2016, "su"};
    Pvm c = {31, 12, 1960, "la"};
    printf("Pvm:n koko: %lu tavua\n", (unsigned long) sizeof(Pvm));
    printf("Päivämäärät ennen kasvattamista:\n");
    tulostaPvm(&a);
    printf("\n");  tulostaPvm(&b);  printf("\n");  tulostaPvm(&c);
    printf("\n");
    printf("Päivämäärät kasvattamisen jälkeen:\n");
    tulostaPvm(kasvataPvm(&a));
    printf("\n");  tulostaPvm(kasvataPvm(&b));  printf("\n");  tulostaPvm(kasvataPvm(&c));
    printf("\n");
    printf("Päivämäärien erot:\n");
    tulostaPvm(&a);  printf(" vs ");  tulostaPvm(&b);  printf(": %u\n", pvmEro(&a, &b));
    tulostaPvm(&b);  printf(" vs ");  tulostaPvm(&c);  printf(": %u\n", pvmEro(&b, &c));
    tulostaPvm(&a);  printf(" vs ");  tulostaPvm(&c);  printf(": %u\n", pvmEro(&a, &c));
    return 0;
}
*/

