//
// Created by meni on 21/01/2020.
//

#ifndef MILE_STONE2__BESTFIRSTSEARCH_H_
#define MILE_STONE2__BESTFIRSTSEARCH_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "Searcher.h"
#include "Searchable.h"
#include "CompareCost.cpp"
template<class T, class Q, class P>
class BestFirstSearch : public Searcher<T, Q, P> {
 private:
  std::priority_queue<State<P>*, vector<State<P>*>, CompareCost<P>>  priorityQueue;
  vector<State<P>*> markedNodes;
  vector<State<P>*> examinedNodes;
  stack<State<P>*> Selectedpath;
  string shortestPath = "";
  int whenToGetLine;
 public:
  string getShortestPath() {
    return this->shortestPath;
  }
  BestFirstSearch() {
    this->whenToGetLine = 0;
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
  void WriteDirection(int decideDirection, double totalCost) {
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
  void addToSelectedpath(State<P>* state) {
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
      WriteDirection(decideDirection, this->Selectedpath.top()->gettotalCost());
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
  Q search(Searcheable<T, P> *searcheable) {
    int decideDirection;
    State<P> *square;
    this->priorityQueue.push(searcheable->getInitialState());
    this->markedNodes.push_back(searcheable->getInitialState());
    while (!priorityQueue.empty()) {
      square = priorityQueue.top();
      priorityQueue.pop();
      if (square->Equals(searcheable->getGoalState())) {
        addToSelectedpath(square);
        printPath();
        return getShortestPath();
      } else {
        vector<State<P> *> successors = searcheable->getAllPossibleStates(square); // generate square's successors
        typename std::vector<State<P> *>::iterator it;
        typename std::vector<State<P> *>::iterator it2;
        for (it = successors.begin(); it != successors.end(); ++it) {
          it2 = std::find(markedNodes.begin(), markedNodes.end(), *it);
          if (it2 == markedNodes.end()) {
            (*it)->setCameFrom(square);
            markedNodes.push_back(*it);
            priorityQueue.push(*it);
          }
        }
      }
      this->examinedNodes.push_back(square);
    }
    throw "goal not found";
  }
};
#endif //MILE_STONE2__BESTFIRSTSEARCH_H_