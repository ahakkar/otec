/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H4 T3 Nykyaika
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define BUFFER_SIZE 80

int main() {
    time_t current_time;
    struct tm * time_info;
    char buffer[BUFFER_SIZE];

    setlocale(LC_TIME, "fi_FI"); 

    time(&current_time);
    time_info = localtime(&current_time);

    /* viikonpäivä kk.pv.vvvv klo hh:mm */
    strftime(buffer, BUFFER_SIZE, "%A %d.%m.%Y klo %H:%M", time_info);
    buffer[0] = toupper(buffer[0]);
    printf("%s\n", buffer);

    return 0;
}