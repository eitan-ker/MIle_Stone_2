//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__ASTAR_H_
#define MILE_STONE2__ASTAR_H_
#include <iostream>
#include <vector>
#include "Searcher.h"
#include "Searchable.h"
template <class T, class Q>
class AStar : public Searcher<T,Q> {
public:
    Q search(Searcheable<T> searcheable) {
        State<T> initialState = searcheable.getInitialState();


    }
    AStar(){};
};
#endif //MILE_STONE2__ASTAR_H_