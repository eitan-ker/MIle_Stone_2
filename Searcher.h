//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__SEARCHER_H_
#define MILE_STONE2__SEARCHER_H_
using namespace std;
template<class T,class Q>
class Searcher { // gets a problem - we decide how we want to get it(string, io...)
 public:
  virtual Q search(T& searchable) {

  }
};
#endif //MILE_STONE2__SEARCHER_H_
