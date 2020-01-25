//
// Created by eizzker on 18/01/2020.
//

#ifndef MILE_STONE_2_POINT_H
#define MILE_STONE_2_POINT_H
class Point {
private:
    int row;
    int col;
public:
    Point(int r, int c);
    int getCol();
    int getRow();
    bool Equals(Point* p);
	virtual ~Point(){}
};


#endif //MILE_STONE_2_POINT_H
