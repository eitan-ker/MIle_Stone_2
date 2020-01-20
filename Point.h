//
// Created by eizzker on 18/01/2020.
//

#ifndef MILE_STONE_2_POINT_H
#define MILE_STONE_2_POINT_H
class Point {
private:
    double row;
    double col;
public:
    Point(double r, double c);
    double getCol();
    double getRow();
    bool Equals(Point* p);
};


#endif //MILE_STONE_2_POINT_H
