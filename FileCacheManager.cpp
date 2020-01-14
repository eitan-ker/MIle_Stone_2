//
// Created by eizzker on 13/01/2020.
//

#include "FileCacheManager.h"
#include <iostream>
template <class T, class Q>
Q FileCacheManager<T,Q>::pop(T problem) { //draw the solution for problem from map
 return getProblemQueryMap()[problem];
}
template <class T, class Q>
int FileCacheManager<T,Q>::doWeHaveSolution(T problem) { // ask if we have solution for given problem as a parameter
  typename unordered_map<T,Q> ::iterator it = getProblemQueryMap().begin();
  if (it != getProblemQueryMap().end()){
    return 1;
  } else {
    return 0;
  }
}
template <class T, class Q>
void FileCacheManager<T,Q>::save(T problem, Q solution) { //save problem-solution pair to map
  getProblemQueryMap()[problem] = solution;
}
