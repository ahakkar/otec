/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T9 Lajittelu
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "rectangle.h"

/* Compare area of rectangles*/
int rectAlaVrt(const void *a, const void *b) {
    const Rectangle *rect_a = *(const Rectangle **)a;
    const Rectangle *rect_b = *(const Rectangle **)b;
    double area_a = getArea(rect_a);
    double area_b = getArea(rect_b);

    if (area_a < area_b) {
        return -1;
    }
    else if (area_a > area_b) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Compare x, y coordinates of a Rectangle */
int rectXyVrt(const void *a, const void *b) {
    const Rectangle *rect_a = *(const Rectangle **)a;
    const Rectangle *rect_b = *(const Rectangle **)b;
    if (rect_a->origin.x == rect_b->origin.x) {
        return rect_a->origin.y - rect_b->origin.y;
    }
    else {
        return rect_a->origin.x - rect_b->origin.x;
    }
}

/* Compare width of rectangles in descending order */
int rectLeveysVrt(const void *a, const void *b) {
    const Rectangle *rect_a = *(const Rectangle **)a;
    const Rectangle *rect_b = *(const Rectangle **)b;
    return rect_b->width - rect_a->width;

}

/* Compare length of strings first, length descending
   compare alphabetically second, alphabetically ascending */
int mjPitAakkosVrt(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    if (len_a == len_b) {
        return strcmp(str_a, str_b);
    }
    else {
        return len_b - len_a;
    }

}