//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_CACHEMANAGER_H
#define MILE_STONE_2_CACHEMANAGER_H

#include <unordered_map>
#include "Solver.h"
template<typename T, typename Q>
class CacheManager {
  // check if it's ok - later with the program

  std::unordered_map<T,Q> problemQuery;
  int doWeHaveSolution() = 0; // return if there is a solution
  Solver pop() = 0; // pop solution to problem P
  void save(Solver s) = 0; // save solution s to problem P
};
#endif //MILE_STONE_2_CACHEMANAGER_H