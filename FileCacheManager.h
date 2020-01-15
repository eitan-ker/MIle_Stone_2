//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_FILECACHEMANAGER_H
#define MILE_STONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "Solver.h"
using namespace std;
template <class T, class Q>
class FileCacheManager : public CacheManager<T,Q> {
 public:
  //FileCacheManager();
  int doWeHaveSolution(T problem); // return if there is a solution
  Q pop(T problem); // pop solution to problem P
  void save(T problem, Q solution); // save solution s to problem P
  unordered_map<T, Q> &getProblemQueryMap();
};


#endif //MILE_STONE_2_FILECACHEMANAGER_H
