//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__STATE_H_
#define MILE_STONE2__STATE_H_

#include "Point.h"
template<class P>
class State {
private :
    P* _state; // the state represented by point
    double _cost; // cost to reach this state
    State<P>* _cameFrom; //the state we came from to this state
public:
    State(P* state, double cost) {
        this->_cost = cost;
        this->_state = state;
        this->_cameFrom = nullptr;
    };
    void setCameFrom(State<P>* parent) {
      this->_cameFrom = parent;
    }
    double getCost() {
      return this->_cost;
    }
    void setCost(double val) {
      this->_cost = val;
    }
    P* getState() {
      return this->_state;
    }
    bool Equals(State<P>* s) {
         return this->_state->Equals(s->getState());
    }
    State<P>* getCameFrom() {
      return this->_cameFrom;
    }
};

#endif //MILE_STONE2__STATE_H_
