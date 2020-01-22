//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__STATE_H_
#define MILE_STONE2__STATE_H_

#include "Point.h"

template<class P>
class State {
private :
    P *_state; // the state represented by point
    double _cost; // cost to reach this state
    double _totalCost;
    int is_visited;
    State<P> *_cameFrom; //the state we came from to this state
public:
    State(P *state, double cost) {
        this->_cost = cost;
        this->_state = state;
        this->_cameFrom = nullptr;
        this->is_visited = 0;
        this->_totalCost = 0;
    };

    void set_visited() {
        this->is_visited = 1;
    }

    int getVisited() {
        return this->is_visited;
    }

    void setCameFrom(State<P> *parent) {
        this->_cameFrom = parent;
        if (parent->gettotalCost() != 0) {
            this->settotalCost(this->getCost() + parent->gettotalCost());
        } else {
            this->settotalCost(this->getCost() + parent->getCost());
        }
    }

    double getCost() {
        return this->_cost;
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
};

#endif //MILE_STONE2__STATE_H_
