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
  Searcheable() {
      getInitialState()->setCost(0);
  }
  virtual State<P>* getInitialState() {

  }
  virtual State<P>& getGoalState() {

  }
  virtual bool isGoalState(State<P>& state) {
  }
  virtual vector<State<P>> getAllPossibleStates(State<P>& state) {
   // vector<State<P>> arr;
  }
};
#endif //MILE_STONE2__SEARCHABLE_H_
