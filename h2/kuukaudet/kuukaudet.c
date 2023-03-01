/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T6 Kuukaudet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "kuukaudet.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* Vuosi on karkausvuosi, jos se on jaollinen neljällä mutta ei sadalla,
 * ja lisäksi myös silloin, jos vuosi on jaollinen neljälläsadalla.
 */
int karkausvuosi(int v) {
    if ((v%4 == 0 && v%100 != 0) || v%400 == 0 ) {
        return 1;
    }
    return 0;
}


/* helper func to convert strings to uppercase */
char* string_to_uppercase(const char *str) {
    char *result = malloc(strlen(str) + 1);
    int i = 0;

    if (result == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (; str[i]; i++) {
        result[i] = toupper((unsigned char)str[i]);
    }

    result[strlen(str)] = '\0';
    return result;
}

/*
 * Funktio char kkPituus(const char *kkNimi, int vuosiluku), joka palauttaa
 * tiedon siitä, kuinka monta päivää parametrin kkNimi ilmaisemassa kuukaudessa
 * on parametrin vuosiluku ilmaisemana vuonna. Jos kkNimi ei vastaa mitään
 * taulukossa KK_NIMET määritettyä kuukaudennimeä, palautetaan virhettä
 * kuvaava palautusarvo -1. Kuukauden nimeä tulee verrata kirjainten
 * koosta välittämättä. Toteutuksesi saa pohjautua funktioon tolower,
 * vaikkei se toimikaan kunnolla esimerkiksi 'ä'-kirjainten kanssa.
 */

int kkPituus(const char *kkNimi, int vuosiluku) {
    int i = 0;
    int rval = -1; /* -1 = month was not found from the month list */

    for (; i < KK_LKM; i++) {
        /* temp vars for uppercase strings since we can't edit const vars */
        char *str1 = string_to_uppercase(kkNimi);
        char *str2 = string_to_uppercase(KK_NIMET[i]);

        /* compare months, if month is found, return the amount of dates in a month */
        if (strcmp(str1, str2) == 0) {
            if (karkausvuosi(vuosiluku)) {
                rval = KK_PAIVAT[KARKAUSVUOSI][i];
                continue;
            }
            rval =  KK_PAIVAT[EI_KARKAUSVUOTTA][i];
        }

        free(str1);
        free(str2);
    }

    return rval;
}


int main()
{
    printf("Helmikuu 2016: %d päivää\n", kkPituus("Helmikuu", 2016));
    printf("Helmikuu 2100: %d päivää\n", kkPituus("helmikuu", 2100));
    printf("Helmi kuu 2100: %d päivää\n", kkPituus("helmi kuu", 2100));

    return 0;
}

