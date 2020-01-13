//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_CACHEMANAGER_H
#define MILE_STONE_2_CACHEMANAGER_H

#include "Solver.h"

class CacheManager {
    // check if it's ok - later with the program

    int doWeHaveSolution(); // return if there is a solution
    Solver pop(); // pop solution to problem P
    void save(Solver s); // save solution s to problem P
};
#endif //MILE_STONE_2_CACHEMANAGER_H
