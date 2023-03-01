/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T6 Kuukaudet
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef KUUKAUDET_H
#define KUUKAUDET_H

const int KARKAUSVUOSI = 1;
const int EI_KARKAUSVUOTTA = 0;

enum {
    TAMMIKUU,
    HELMIKUU,
    MAALISKUU,
    HUHTIKUU,
    TOUKOKUU,
    KESAKUU,
    HEINAKUU,
    ELOKUU,
    SYYSKUU,
    LOKAKUU,
    MARRASKUU,
    JOULUKUU
};

enum {
    KK_LKM = 12
};

extern const char *KK_NIMET[KK_LKM];
extern const char KK_PAIVAT[2][KK_LKM];

int karkausvuosi(int vuosiluku);
int kkPituus(const char *kkNimi, int vuosiluku);

#endif
