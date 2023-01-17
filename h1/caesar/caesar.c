/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T16 Caesarin koodi
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

/* tehtävä on varsin suoraviivainen ratkaista, jos määrität UCHAR_MAX + 1
 * -alkioisen char-taulukon korvaus, jonka indeksien i = 0, ..., UCHAR_MAX
 * arvot alustat ensin tapaan korvaus[i] = i ja johon sen jälkeen lisäksi
 * asetat parametrien aakkosto ja korvaavat ilmaisemat tiedot siitä, mikä
 * kirjain pitäisi korvata milläkin. Tässä vain pitää muistaa kohdella
 * indeksejä etumerkittöminä. Taulukon korvaus arvojen asetukset voisivat
 * olla esimerkiksi muotoa korvaus[(unsigned char) aakkosto[i]] = korvaavat[i].
 */


void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[]) {
    int len = strlen(mj);
    int len2 = strlen(aakkosto);
    int i = 0;
    int j = 0;
    char repl[UCHAR_MAX+1];
    bool replaced = false;

    for(; i < len; i++) {
        replaced = false;
        for (j = 0; j < len2; j++) {
            if (mj[i] == aakkosto[j]) {
                repl[i] = korvaavat[j];
                replaced = true;
                break;
            }
        }
        if(!replaced) {
            repl[i] = mj[i];
        }
    }

    for(i = 0; i < len; i++) {
        mj[i] = repl[i];
    }
}


