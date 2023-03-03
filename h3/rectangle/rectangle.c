/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T3 Dynaamiset oliot
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Rectangle * createRectangle(void) {
    Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle));
    Point* pt = (Point*) malloc(sizeof(Point));

    rect->width = 0;
    rect->height = 0;
    pt->x = 0;
    pt->y = 0;

    rect->origin = *pt;
    free(pt);

    return rect;

}

Rectangle * createRectangle2(Point p) {
    Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle));

    rect->width = 0;
    rect->height = 0;
    rect->origin = p;

    return rect;
}

Rectangle * createRectangle3(int w, int h) {
    Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle));
    Point* pt = (Point*) malloc(sizeof(Point));

    rect->width = w;
    rect->height = h;
    pt->x = 0;
    pt->y = 0;

    rect->origin = *pt;
    free(pt);

    return rect;
}

Rectangle * createRectangle4(Point p, int w, int h) {
    Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle));

    rect->width = w;
    rect->height = h;
    rect->origin = p;

    return rect;
}

void move(Rectangle *r, int x, int y) {
    r->origin.x = x;
    r->origin.y = y;
}

int getArea(const Rectangle *r) {
    return r->height*r->width;
}
