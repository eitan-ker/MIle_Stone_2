//
// Created by meni on 14/01/2020.
//

#ifndef MILE_STONE2__STRINGREVERSER_H_
#define MILE_STONE2__STRINGREVERSER_H_
#include "Solver.h"
template <class T, class Q, class P>
class StringReverser : public Solver<T,Q,P> {
  string solve(string problem) {
    int i = problem.length() - 1;
    const char* token = &problem[i];
    string s = "\0";
    while(i >= 0) {
      s+=*token;
      token--;
      i--;
    }
    return s;
  }
};
#endif //MILE_STONE2__STRINGREVERSER_H_
