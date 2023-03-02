/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T14 Päivämäärät
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#ifndef PVM_H
#define PVM_H

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


struct Pvm {
    int pv;
    int kk;
    int vuosi;
    char vk_pv[3];
};

typedef struct Pvm Pvm;

enum vkpv {
    ma,
    ti,
    ke,
    to,
    pe,
    la,
    su
};

Pvm * kasvataPvm(Pvm *pvm);
unsigned int pvmEro(const Pvm *a, const Pvm *b);
void tulostaPvm(Pvm *pvm);
int karkausvuosi(int vuosiluku);
int kkPituus(const char *kkNimi, int vuosiluku);

#endif
