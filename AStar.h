//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__ASTAR_H_
#define MILE_STONE2__ASTAR_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Searcher.h"
#include "Searchable.h"
void WriteDirection(int decideDirection);
template<class T, class Q, class P>
class AStar : public Searcher<T, Q, P> {
 private:
  vector<State<P>*> openlist;
  vector<State<P>*> closedlist;
  string ShortestPath = "";
 public:
  AStar() {}

  double calculateG(State<P> *state) {
    return state->getCost();
  }
  double calculateF(Searcheable<T, P>* searchable, State<P> *state) {
    return calculateG(state) + calculateH(searchable, state);
  }
  double calculateH(Searcheable<T, P>* searcheable, State<P> *state) { // calculate H using Manhattan distance
    return abs(state->getState()->getRow() - searcheable->getGoalState()->getState()->getRow()) +
        abs(state->getState()->getCol() - searcheable->getGoalState()->getState()->getCol());
  }
  int decideWhereICameFrom(State<P>* state) {/*return the direction we move from parent : 0-initial state,
 * 1-move to the left
 * 2-move to the right
 * 3-move down
 * 4-move up*/
    if (state->getCameFrom() == nullptr) {
      return 0;
    }
    if (state->getState()->getRow() == state->getCameFrom()->getState()->getRow()) {
      if (state->getState()->getCol() > state->getCameFrom()->getState()->getCol()) {
        return 2;
      } else {
        return 1;
      }
    } else {
      if (state->getState()->getRow() > state->getCameFrom()->getState()->getRow()) {
        return 3;
      } else {
        return 4;
      }
    }
  }
  void WriteDirection(int decideDirection) {
    switch (decideDirection) {
      case 1 :this->ShortestPath += "left";
        break;
      case 2 :this->ShortestPath += "right";
        break;
      case 3 :this->ShortestPath += "down";
        break;
      case 4 :this->ShortestPath += "up";
        break;
      default:break;
    }
  }
  Q search(Searcheable<T, P> *searcheable) {
    State<P> *square;
    int i = 0, currentSquare = 0;
    openlist.push_back(searcheable->getInitialState());
    while (!openlist.empty()) {
      double minCost = calculateF(searcheable, openlist[0]);
      for (typename std::vector<State<P>*>::iterator it = openlist.begin(); it != openlist.end(); ++it, i++) {
        if (calculateF(searcheable, *it) < minCost) { // find the point with the least f in the open list
          minCost = calculateF(searcheable, *it);
          currentSquare = i - 1;
        }
      }
      typename std::vector<State<P>*>::iterator it1 = openlist.begin() + currentSquare;
      int decideDirection = decideWhereICameFrom(*it1);
      WriteDirection(decideDirection);
      if(decideDirection!= 0) {
        this->ShortestPath += ",";
      }
      vector<State<P>*> successors = searcheable->getAllPossibleStates(*it1); // generate square's successors
      for (typename std::vector<State<P>*>::iterator it = successors.begin(); it != successors.end(); ++it) {
        (*it)->setCameFrom(*it1);
      }
      for (typename std::vector<State<P> *>::iterator it = successors.begin(); it != successors.end(); ++it) {
        if ((*it)->Equals(searcheable->getGoalState())) {
          decideDirection = decideWhereICameFrom(*it);
          WriteDirection(decideDirection);
          return ShortestPath;
        } else {
          State<P>* successor = *it;
          typename std::vector<State<P>*>::iterator it2 = std::find(openlist.begin(), openlist.end(), successor);
          typename std::vector<State<P>*>::iterator it3 = std::find(closedlist.begin(), closedlist.end(), successor); //find successor in closedlist
          if (it2 != openlist.end()) { /* if a node with the same position as
              successor is in the OPEN list which has a
              lower f than successor, skip this successor*/
            if (calculateF(searcheable, successor) < calculateF(searcheable, *it)) {
              //skip this phase
            }
          } else if (it3 != closedlist.end()) {
            if (calculateF(searcheable, successor) < calculateF(searcheable, *it)) {
              //skip this phase
            } else {
              openlist.push_back(*it);
            }
          } else {
            openlist.push_back(*it);
          }
        }
      }
      closedlist.push_back(*it1);
      openlist.erase(it1);
    }
    throw "Failed to find the Destination Cell\n";
  }
};
#endif //MILE_STONE2__ASTAR_H_