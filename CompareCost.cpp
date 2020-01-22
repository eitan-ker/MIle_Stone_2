#include "State.h"
//
// Created by meni on 21/01/2020.
//
template<class P>
struct CompareCost {
    bool operator()(State<P>* const& p1, State<P>* const& p2)
    {
        return p1->gettotalCost() > p2->gettotalCost();
    }
};
