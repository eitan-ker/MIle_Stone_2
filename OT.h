//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__OT_H_
#define MILE_STONE2__OT_H_
#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"
template<class T,class Q>
class OT : public Solver<T,Q> { // gets a problem - we decide how we want to get it(string, io...)
 private:
  Searcheable<T> _searchable;
  Searcher<T,Q> _searcher;
 public:
  OT(Searcheable<T> searchable, Searcher<T,Q> searcher) : _searchable(searchable), _searcher(searcher) {}
};
#endif //MILE_STONE2__OT_H_
