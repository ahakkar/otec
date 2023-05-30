/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H4 T5 Päivämäärien erotus
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define SECONDS_IN_A_DAY 86400

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
    if (year % 4 != 0) {
        return 0;
    }
    else if (year % 100 != 0) {
        return 1;
    }
    else if (year % 400 != 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int parse_date(const char* date_str, struct tm* date) {
    int day, month, year;
    if (sscanf(date_str, "%d.%d.%d", &day, &month, &year) != 3) {
        return -1;
    }

    if (month < 1 || month > 12) {
        return -1;
    }

    if (day < 1) {
        return -1;
    }
    if (month == 2 && is_leap_year(year)) {
        if (day > 29) {
            return -1;
        }
    }
    else if (day > days_in_month[month - 1]) {
        return -1;
    }

    date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = day;
    
    return 0;
}

long pvm_ero(const char* date1_str, const char* date2_str) {
    struct tm date1 = {0}, date2 = {0};
    time_t time1, time2;
    long difference;

    if (parse_date(date1_str, &date1) != 0) {
        printf("Invalid date: %s\n", date1_str);
        return -1;
    }
    if (parse_date(date2_str, &date2) != 0) {
        printf("Invalid date: %s\n", date2_str);
        return -1;
    }

    time1 = mktime(&date1);
    time2 = mktime(&date2);

    difference = (long)(difftime(time1, time2) / SECONDS_IN_A_DAY);
    return difference < 0 ? -difference : difference;
}

int main() {
    long days = pvm_ero("26.04.2016", "09.05.2013");
    if (days != -1) {
        printf("Difference: %ld days\n", days);
    }
    return 0;
}