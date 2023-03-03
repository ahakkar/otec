/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T3 Dynaamiset oliot
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef RECTANGLE_H
#define RECTANGLE_H

struct Point {
    int x;
    int y;
};

typedef struct Point Point;

struct Rectangle {
    int width;
    int height;
    Point origin;
};

typedef struct Rectangle Rectangle;

Rectangle * createRectangle(void);

Rectangle * createRectangle2(Point p);

Rectangle * createRectangle3(int w, int h);

Rectangle * createRectangle4(Point p, int w, int h);

void move(Rectangle *r, int x, int y);

int getArea(const Rectangle *r);


#endif
