/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H4 T4 Viikko
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define BUFFER_SIZE 80

void viikko(int pv, int kk, int vuosi) {
    struct tm date = {0};
    char buffer[BUFFER_SIZE];
    int i = 0;

    date.tm_mday = pv;
    date.tm_mon = kk-1;
    date.tm_year = vuosi-1900;
    mktime(&date);
    date.tm_mday -= (date.tm_wday + 6) % 7;
    mktime(&date);

    for (i = 0; i < 7; i++) {
        strftime(buffer, BUFFER_SIZE, "%A %d. %B %Y", &date);
        printf("%s\n", buffer);
        date.tm_mday++;
        mktime(&date);
    }
}

/* int main() {
    viikko(24, 5, 2023);
    return 0;
} */