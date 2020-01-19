//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_SOLVER_H
#define MILE_STONE_2_SOLVER_H

#include <string>
using namespace std;
template<class T, class Q, class p>
class Solver { // gets a problem - we decide how we want to get it(string, io...)
public:
    virtual Q solve(T problem) = 0;
};


#endif //MILE_STONE_2_SOLVER_H