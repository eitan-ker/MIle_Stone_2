//
// Created by eizzker on 18/01/2020.
//

#include "Point.h"

Point::Point(double r, double c) {
    this->row = r;
    this->col = c;
}

double Point::getRow() {
    return this->row;
}

double Point::getCol() {
    return this->col;
}

bool Point::Eqals(Point p) {
    if ((this->row == p.getRow()) && (this->col == p.getCol())) {
        return true;
    } else {
        return false;
    }
}