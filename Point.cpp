//
// Created by eizzker on 18/01/2020.
//

#include "Point.h"

Point::Point(int r, int c) {
    this->row = r;
    this->col = c;
}

int Point::getRow() {
    return this->row;
}

int Point::getCol() {
    return this->col;
}

bool Point::Equals(Point* p) {
    return (this->row == p->getRow()) && (this->col == p->getCol());

}