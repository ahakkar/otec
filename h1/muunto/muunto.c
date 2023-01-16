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
        /*printf("%c\n", tmp); */
        mj[len-1-i] = mj[i];
        mj[i] = tmp;
    }
}
