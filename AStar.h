//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__ASTAR_H_
#define MILE_STONE2__ASTAR_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include "Searcher.h"
#include "Searchable.h"
#include "CompareG.cpp"
void WriteDirection(int decideDirection);
template<class T, class Q, class P>
class AStar : public Searcher<T, Q, P> {
 private:
  std::priority_queue<State<P>*, vector<State<P>*>, CompareG<P>>  priorityQueue;
  std::set<State<P>*>  OpenList;
  std::map<State<P>*,int> cameFrom;
  stack<State<P>*> Selectedpath;
  int totalCost;
  string shortestPath = "";
  int whenToGetLine;
 public:
  string getShortestPath() {
    return this->shortestPath;
  }
  AStar() {
    this->totalCost = 0;
    this->whenToGetLine = 0;
  }

  int calculateG(State<P> *state) {
    typename std::map<State<P>*,int>::iterator it;
    it = cameFrom.find(state);
    if (it != cameFrom.end()) {
      return cameFrom[state];
    } else {
      return std::numeric_limits<int>::max();
    }
  }
  int calculateF(Searcheable<T, P>* searchable, State<P> *state) {
    return calculateG(state) + calculateH(searchable, state);
  }
  int calculateH(Searcheable<T, P>* searcheable, State<P> *state) { // calculate H using Manhattan distance
    return abs(state->getState()->getRow() - searcheable->getGoalState()->getState()->getRow()) +
        abs(state->getState()->getCol() - searcheable->getGoalState()->getState()->getCol());
  }
  int decideWhereICameFrom(State<P>* state) {/*return the direction we move from parent : 0-initial state,
 * 1-came to the left
 * 2-came to the right
 * 3-came down
 * 4-came up*/
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
  void WriteDirection(int decideDirection, int totalCost) {
    string extra;
    switch (decideDirection) {
      case 1:
        extra = "Left (" + to_string(totalCost) + ")";
        this->shortestPath+=extra;
        break;
      case 2 :
        extra = "Right (" + to_string(totalCost) + ")";
        this->shortestPath+=extra;
        break;
      case 3 :
        extra = "Down (" + to_string(totalCost) + ")";
        this->shortestPath+=extra;
        break;
      case 4 :extra = "Up (" + to_string(totalCost) + ")";
        this->shortestPath+=extra;
        break;
      default:break;
    }
  }
  void addToSelectedpath(State<P>* state) { //fill the stack so that the initial state is on the top and goal state is at the bottom
    if (state->getCameFrom()==nullptr) {
      this->Selectedpath.push(state);
      return;
    }
    this->Selectedpath.push(state);
    this->addToSelectedpath(state->getCameFrom());
  }
  void printPath() {
    int decideDirection;
    while(!(this->Selectedpath.empty())) {
      decideDirection = decideWhereICameFrom(this->Selectedpath.top());
      WriteDirection(decideDirection, this->Selectedpath.top()->getG());
      if(decideDirection!= 0 && this->Selectedpath.size() > 1) {
        this->shortestPath+=",";
      }
      if(this->whenToGetLine > 9) {
        this->shortestPath+="\r\n";
        this->whenToGetLine = 0;
      }
      this->whenToGetLine++;
      this->Selectedpath.pop();
    }
  }
  Q search(Searcheable<T, P> *searcheable) { //based on Wikipedia A* algo
    State<P> *square;
    typename std::set<State<P> *>::iterator it6;
    typename std::vector<State<P> *>::iterator it;
    int minCost = 0, minCost1 = 0;
    int i = 0, currentSquare = 0;
    OpenList.insert(searcheable->getInitialState());
    priorityQueue.push(searcheable->getInitialState());
    cameFrom[searcheable->getInitialState()] = searcheable->getInitialState()->gettotalCost();
    searcheable->getInitialState()->setG(cameFrom[searcheable->getInitialState()]);
    searcheable->getInitialState()->setF(searcheable->getInitialState()->getG() + calculateH(searcheable, searcheable->getInitialState()));
    while (!priorityQueue.empty()) {
      State<P> *square = priorityQueue.top();
        priorityQueue.pop();
        it6 = OpenList.find(square);
        if(it6 != OpenList.end()) {
          OpenList.erase(square);
        }
      if ((square)->Equals(searcheable->getGoalState())) {
        addToSelectedpath(square);
        printPath();
        return getShortestPath();
      }
      vector<State<P> *> successors = searcheable->getAllPossibleStates(square); // generate square's successors
        for (it = successors.begin(); it != successors.end(); ++it) {
          State<P> *successor = *it;
          int tentative_gScore = calculateG(square) + (*it)->getCost();
          if (tentative_gScore < calculateG(successor)) {
            this->cameFrom[successor] = tentative_gScore;
            successor->setG(tentative_gScore);
            successor->setF(successor->getG() + calculateH(searcheable, successor));
            (*it)->setCameFrom(square);
            if (OpenList.find(successor) == OpenList.end()) {
              OpenList.insert(successor);
              priorityQueue.push(successor);
            }
          }
          }
        }
    throw "Failed to find the Destination Cell\n"; //in case the goal state is not reachable
  }
};
#endif //MILE_STONE2__ASTAR_H_
