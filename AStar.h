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
template <class T, class Q, class P>
class AStar : public Searcher<T,Q> {
 private:
  vector<T> openlist;
  vector<T> closedlist;
  string ShortestPath = "";
public:
  AStar(){
  };

    Q search(Searcheable<T,P>& searcheable) {
      T square;
      int i = 0, currentSquare = 0;
      openlist.push_back(searcheable.getInitialState());
      while(!openlist.empty()) {
        double minCost = searcheable(openlist.begin()).calculateF();
        for (typename std::vector<T>::iterator it = openlist.begin() ; it != openlist.end(); ++it, i++) {
          if(calculateF(searcheable,*it) < minCost) { // find the point with the least f in the open list
            minCost = calculateF(searcheable,*it);
            currentSquare = i - 1;
          }
        }
        typename std::vector<T>::iterator it1 = openlist.begin()+i;
        int decideDirection = decideWhereICameFrom(*it1);
        WriteDirection(decideDirection);
        this->ShortestPath+=",";
        vector<T> successors = searcheable.getAllPossibleStates(*it1); // generate square's successors
        for (typename std::vector<T>::iterator it = successors.begin() ; it != successors.end(); ++it) {
          (*it).setCameFrom(*it1);
        }
        openlist.erase(it1);
        for (typename std::vector<T>::iterator it = successors.begin() ; it != successors.end(); ++it) {
          if(*it.Equals(searcheable.getGoalState())) {
            decideDirection = decideWhereICameFrom(*it);
            WriteDirection(decideDirection);
          } else {
            T successor = *it;
            typename std::vector<T>::iterator it2 = find(openlist.begin(), openlist.end(), successor); //find successor in openlist
            typename std::vector<T>::iterator it3 = find(closedlist.begin(), closedlist.end(), successor); //find successor in closedlist
            if (it2 != openlist.end() && (calculateF(searcheable, successor) < calculateF(searcheable, *it2))) { /* if a node with the same position as
              successor is in the OPEN list which has a
              lower f than successor, skip this successor*/
              openlist.push_back(successor);
            } else if(it3 != closedlist.end() && (calculateF(searcheable, successor) < calculateF(searcheable, *it3))){
              openlist.push_back(successor);
            } else {
            // do nothing with the current successor
            }
          }
        }
        closedlist.push_back(square);
      }
      throw "Failed to find the Destination Cell\n";
    }
  double calculateG(State<T>& state) {
    return state.getCost();
  }
  double calculateF(Searcheable<T,P>& searcheable, State<T>& state) {
    return calculateG(state) + calculateH(searcheable,state);
  }
  double calculateH(Searcheable<T,P>& searcheable,State<T>& state) { // calculate H using Manhattan distance
    return abs(state.getState().getRow() - searcheable.getGoalState().getState().getRow()) +
        abs(state.getState().getCol() - searcheable.getGoalState().getState().getCol());
  }
  int decideWhereICameFrom(State<T> state) {/*return the direction we move from parent : 0-initial state,
 * 1-move to the left
 * 2-move to the right
 * 3-move down
 * 4-move up*/
      if(state.getCameFrom() == nullptr) {
        return 0;
      }
      if(state.getState().getRow() == *(state.getCameFrom())->getState().getRow()) {
        if(state.getState().getCol() > *(state.getCameFrom())->getState().getCol()) {
          return 2;
        } else {
          return 1;
        }
      } else {
        if(state.getState().getRow() > *(state.getCameFrom())->getState().getRow()) {
          return 3;
        } else {
          return 4;
        }
      }
    }
    void WriteDirection(int decideDirection) {
      switch(decideDirection) {
        case 1 :
          this->ShortestPath += "left";
          break;
        case 2 :
          this->ShortestPath += "right";
          break;
        case 3 :
          this->ShortestPath += "down";
          break;
        case 4 :
          this->ShortestPath += "up";
          break;
        default:
          break;
      }
    }
};
#endif //MILE_STONE2__ASTAR_H_