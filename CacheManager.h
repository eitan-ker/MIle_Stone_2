//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_CACHEMANAGER_H
#define MILE_STONE_2_CACHEMANAGER_H

#include <unordered_map>
#include <mutex>
#include "Solver.h"

using namespace std;

template<class T, class Q>
class CacheManager {
private:
    unordered_map<T, Q> problemQuery;
 public:
    // check if it's ok - later with the program
    virtual unordered_map<T, Q> &getProblemQueryMap() {
        return this->problemQuery;
    }

    virtual int doWeHaveSolution(T problem) = 0; // return if there is a solution
    virtual Q pop(T problem) = 0; // pop solution to problem P
    virtual void save(T problem, Q solution) = 0; // save solution s to problem P

};

#endif //MILE_STONE_2_CACHEMANAGER_H
