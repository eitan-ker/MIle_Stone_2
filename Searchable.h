//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__SEARCHABLE_H_
#define MILE_STONE2__SEARCHABLE_H_
#include <vector>
#include "State.h"
using namespace std;
template<class T>
class Searcheable { // gets a problem - we decide how we want to get it(string, io...)
 public:
  Searcheable() {
    getInitialState().setCost(0);
  }
  virtual State<T>& getInitialState() {

  }
  virtual State<T>& getGoalState() {

  }
  virtual bool isGoalState(State<T>& state) {
  }
  virtual vector<State<T>> getAllPossibleStates(State<T>& state) {
    vector<State<T>> arr;
  }
};
#endif //MILE_STONE2__SEARCHABLE_H_
