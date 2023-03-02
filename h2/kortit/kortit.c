/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T12 Kortit
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "kortit.h"
#include <stdio.h>

const char *MAIDEN_NIMET[MAA_LKM + 1] = {
    "", "Hertta", "Ruutu", "Risti", "Pata"
};

const char *KORTTIEN_NIMET[MAA_KOKO + 1] = {
    "", "ässä", "kakkonen", "kolmonen", "nelonen", "viitonen",
    "kuutonen", "seiska", "kasi", "ysi", "kymppi", "jätkä",
    "rouva","kunkku"
};

/*
 * tulostaa parametrinaan saamansa kortin ruudulle merkkijonomuodossa.
 * Tulostus pohjautuu yllämainittuihin vakiomerkkijonotaulukoihin
 */
void tulostaKortti(Kortti kortti) {
    printf("%s%s",
           MAIDEN_NIMET[kortti.maa],
           KORTTIEN_NIMET[kortti.arvo]
           );
}

/* toimii samoin kuin tulostaKortti, mutta nyt tulostettava
 * kortti saadaan osoitinparametrin välityksellä
 */
void tulostaKorttiOs(const Kortti *korttiOs) {
    printf("%s%s",
           MAIDEN_NIMET[korttiOs->maa],
           KORTTIEN_NIMET[korttiOs->arvo]
           );

}

/*
int main()
{
    Kortti pakka[KORTTI_LKM];
    int i = 0;
    Maa m;
    Arvo a;

    for(m = HERTTA; m <= PATA; ++m)
    {
        for(a = ASSA; a <= KUNKKU; ++a)
        {
            pakka[i].maa = m;
            pakka[i].arvo = a;
            if(i % MAA_KOKO)
            {
                printf("%c", ((i % 4) == 0) ? '\n' : ' ');
            }
            if(i % 2)
            {
                tulostaKortti(pakka[i]);
            }
            else
            {
                tulostaKorttiOs(&pakka[i]);
            }
            i += 1;
        }
        printf("\n");
    }
    return 0;
}
        */

