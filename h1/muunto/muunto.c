/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H1 T15 Muunto
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "muunto.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void muunna(char mj[]) {
    int len = strlen(mj);
    int i = 0;
    char tmp;

    for (; i < len; i++) {
        if (mj[i] >= 'a' && mj[i] <= 'z') {
            mj[i] = toupper(mj[i]);
            continue;
        }
        mj[i] = tolower(mj[i]);
    }
    for(i = 0; i < len/2; i++) {
        tmp = mj[len-1-i];
        mj[len-1-i] = mj[i];
        mj[i] = tmp;
    }
}
