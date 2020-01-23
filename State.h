//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__STATE_H_
#define MILE_STONE2__STATE_H_

#include <limits>
#include "Point.h"

template<class P>
class State {
private :
    P *_state; // the state represented by point
    int _cost; // cost to reach this state
    int _totalCost;
    int is_visited;
    int calculateG;
    int calculateF;
    State<P> *_cameFrom; //the state we came from to this state
public:
    State(P *state, double cost) {
        this->_cost = cost;
        this->_state = state;
        this->_cameFrom = nullptr;
        this->is_visited = 0;
        this->_totalCost = 0;
        this->calculateG =  std::numeric_limits<int>::max();
        this->calculateF =  std::numeric_limits<int>::max();
    };

    void set_visited() {
        this->is_visited = 1;
    }

    int getVisited() {
        return this->is_visited;
    }

    void setCameFrom(State<P> *parent) {
        this->_cameFrom = parent;
        this->settotalCost(this->getCost() + parent->gettotalCost());
    }

    int getCost() {
        return this->_cost;
    }

    void resetState() {
      this->_cameFrom = nullptr;
      this->is_visited = 0;
      this->calculateG = 0;
      this->calculateF = 0;
      this->_totalCost = 0;
    }
    int gettotalCost() {
        return this->_totalCost;
    }

    void settotalCost(int val) {
        this->_totalCost += val;
    }

    void setCost(int val) {
        this->_cost = val;
    }

    P *getState() {
        return this->_state;
    }

    bool Equals(State<P> *s) {
        return this->_state->Equals(s->getState());
    }

    State<P> *getCameFrom() {
        return this->_cameFrom;
    }
    void setG(int val) {
      this->calculateG = val;
    }
    int getG() {
      return this->calculateG;
    }
    void setF(int val) {
      this->calculateF = val;
    }
    int getF() {
      return this->calculateF;
    }
};

#endif //MILE_STONE2__STATE_H_
