#include "State.h"
//
// Created by meni on 21/01/2020.
//
template<class P>
struct CompareG { //comparator for A* star's priority queue
  bool operator()(State<P>* const& p1, State<P>* const& p2)
  {
    return p1->getG() > p2->getG();
  }
};