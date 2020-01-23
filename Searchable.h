//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__SEARCHABLE_H_
#define MILE_STONE2__SEARCHABLE_H_
#include <vector>
#include "State.h"
using namespace std;
template<class T, class P>
class Searcheable { // gets a problem - we decide how we want to get it(string, io...)
 public:
  Searcheable<T,P>(){}
  virtual State<P>* getInitialState() = 0;
  virtual State<P>* getGoalState() = 0;
  virtual bool isGoalState(State<P>* state) = 0;
  virtual vector<State<P> *> getAllPossibleStates(State<P>* state) = 0;
  virtual void ResetMatrix() = 0;
};
#endif //MILE_STONE2__SEARCHABLE_H_
