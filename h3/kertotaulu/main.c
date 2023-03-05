

#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

int main(int argc, char *argv[]) {
    if (argc < 5) {
        return 0;
    }

    Kertotaulu *kt = luoKertotaulu2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    uint i = 0;
    uint j = 0;

    for(i = 0; i <= (kt->d - kt->c + 1); ++i) {
        for(j = 0; j <= (kt->b - kt->a + 1); ++j) {
            if((i > 0) || (j > 0)) {
                printf("%4u", kt->kertotaulu[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
    tuhoaKertotaulu(kt);

    return 0;
}
