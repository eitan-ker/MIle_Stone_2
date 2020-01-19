//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__ASTAR_H_
#define MILE_STONE2__ASTAR_H_
#include <iostream>
#include <cmath>
#include <vector>
#include "Searcher.h"
#include "Searchable.h"
template <class T, class Q>
class AStar : public Searcher<T,Q> {
 private:
  vector<T> openlist;
  vector<T> closedlist;
  double totalCost;
public:
  AStar(){
    this->totalCost = 0;// initialize total cost as zero
  };
    Q search(Searcheable<T> searcheable) {
      T square;
      int i = 0, currentSquare = 0;
      openlist.push_back(searcheable.getInitialState());
      while(!openlist.empty()) {
        double minCost = openlist.begin()->getCost();
        for (typename std::vector<T>::iterator it = openlist.begin() ; it != openlist.end(); ++it, i++) {
          if(*it.getCost() < minCost) { // find the point with the least f in the open list
            minCost = *it.getCost();
            currentSquare = i - 1;
          }
        }
        typename std::vector<T>::iterator it1 = openlist.begin()+i;
        square = *it1; //current q
        openlist.erase(it1); // pop q from openlist
        this->totalCost += square.getCost();
        vector<T> successors = searcheable.getAllPossibleStates(square); // generate square's successors
        for (typename std::vector<T>::iterator it = successors.begin() ; it != successors.end(); ++it) {
          (*it).setCameFrom(square);
        }
        for (typename std::vector<T>::iterator it = successors.begin() ; it != successors.end(); ++it) {
          if(*it.Equals(searcheable.getGoalState())) {
            this->totalCost += *it.getCost();
            return this->totalCost;
          } else {
            T successor = *it;
            typename std::vector<T>::iterator it2 = find(openlist.begin(), openlist.end(), successor); //find successor in openlist
            typename std::vector<T>::iterator it3 = find(closedlist.begin(), closedlist.end(), successor); //find successor in closedlist
            if (it2 != openlist.end() && (searcheable.calculateF(successor) < searcheable.calculateF(*it2))) { /* if a node with the same position as
              successor is in the OPEN list which has a
              lower f than successor, skip this successor*/
              openlist.push_back(successor);
            } else if(it3 != closedlist.end() && (searcheable.calculateF(successor) < searcheable.calculateF(*it3))){
              openlist.push_back(successor);
            } else {
            // do nothing with the current successor
            }
          }
        }
        closedlist.push_back(square);
      }
    }
};
#endif //MILE_STONE2__ASTAR_H_