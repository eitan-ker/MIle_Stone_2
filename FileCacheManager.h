//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_FILECACHEMANAGER_H
#define MILE_STONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "Solver.h"
using namespace std;
template <typename T, typename Q>
class FileCacheManager : public CacheManager<T,Q> {
 public:
  FileCacheManager<T,Q>(){};
  int doWeHaveSolution(T problem) {
    typename unordered_map<T,Q> ::iterator it = this->getProblemQueryMap().begin();
    if (it != this->getProblemQueryMap().end()){
      return 1;
    } else {
      return 0;
    }
  } // return if there is a solution
  Q pop(T problem) {
    return this->getProblemQueryMap()[problem];
  } // pop solution to problem P
  void save(T problem, Q solution) {
    this->getProblemQueryMap()[problem] = solution;
  } // save solution s to problem P
};


#endif //MILE_STONE_2_FILECACHEMANAGER_H
