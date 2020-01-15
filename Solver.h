//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_SOLVER_H
#define MILE_STONE_2_SOLVER_H

#include <string>
using namespace std;
class Solver { // gets a problem - we decide how we want to get it(string, io...)
    // solve(:Problem):Solution
    // different implementation for different problems
    virtual string solve(string problem) = 0;

};


#endif //MILE_STONE_2_SOLVER_H
