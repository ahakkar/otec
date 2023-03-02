/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T12 Kortit
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#ifndef KORTIT_H
#define KORTIT_H

enum Maa {
    HERTTA = 1,
    RUUTU,
    RISTI,
    PATA
};

enum Arvo {
    ASSA = 1,
    KAKKONEN,
    KOLMONEN,
    NELONEN,
    VIITONEN,
    KUUTONEN,
    SEISKA,
    KASI,
    YSI,
    KYMPPI,
    JATKA,
    ROUVA,
    KUNKKU
};

struct Kortti {
    enum Maa maa;
    enum Arvo arvo;
};

enum Constants {
    MAA_LKM = 4,
    MAA_KOKO = 13,
    KORTTI_LKM = MAA_LKM * MAA_KOKO
};

const char *MAIDEN_NIMET[MAA_LKM + 1];

const char *KORTTIEN_NIMET[MAA_KOKO + 1];

typedef enum Maa Maa;
typedef enum Arvo Arvo;
typedef struct Kortti Kortti;

void tulostaKortti(Kortti kortti);
void tulostaKorttiOs(const Kortti *korttiOs);

#endif
