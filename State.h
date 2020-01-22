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
    double _cost; // cost to reach this state
    double _totalCost;
    int is_visited;
    double calculateG;
    double calculateF;
    State<P> *_cameFrom; //the state we came from to this state
public:
    State(P *state, double cost) {
        this->_cost = cost;
        this->_state = state;
        this->_cameFrom = nullptr;
        this->is_visited = 0;
        this->_totalCost = 0;
        this->calculateG =  std::numeric_limits<double>::infinity();
        this->calculateF =  std::numeric_limits<double>::infinity();
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

    double getCost() {
        return this->_cost;
    }

    void resetState() {
      this->_cameFrom = nullptr;
      this->is_visited = 0;
      this->calculateG = 0;
      this->calculateF = 0;
      this->_totalCost = 0;
    }
    double gettotalCost() {
        return this->_totalCost;
    }

    void settotalCost(double val) {
        this->_totalCost += val;
    }

    void setCost(double val) {
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
    void setG(double val) {
      this->calculateG = val;
    }
    double getG() {
      return this->calculateG;
    }
    void setF(double val) {
      this->calculateF = val;
    }
    double getF() {
      return this->calculateF;
    }
};

#endif //MILE_STONE2__STATE_H_
