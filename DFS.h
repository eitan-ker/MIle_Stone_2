//
// Created by meni on 22/01/2020.
//

#ifndef MILE_STONE2__DFS_H_
#define MILE_STONE2__DFS_H_
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include "Searcher.h"
#include "Searchable.h"
template<class T, class Q, class P>
class DFS : public Searcher<T, Q, P> {
 private:
  std::priority_queue<State<P>*>  DFSQueue;
  vector<State<P>*> markedNodes;
  string shortestPath = "";
  int whenToGetLine;
  int totalCost = 0;
 public:
  string getShortestPath() {
    return this->shortestPath;
  }
  DFS() {
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
  Q search(Searcheable<T, P> *searcheable) {
    int decideDirection;
    State<P> *square;
    this->DFSQueue.push(searcheable->getInitialState());
    this->markedNodes.push_back(searcheable->getInitialState());
    while (!DFSQueue.empty()) {
      square = DFSQueue.top();
      DFSQueue.pop();
      if (square->Equals(searcheable->getGoalState())) {
        decideDirection = decideWhereICameFrom(square);
        WriteDirection(decideDirection, square->gettotalCost());
        if(this->whenToGetLine > 8) {
          this->shortestPath+="\r\n";
          this->whenToGetLine = 0;
        }
        this->whenToGetLine++;
        return this->shortestPath;
      } else {
        decideDirection = decideWhereICameFrom(square);
        WriteDirection(decideDirection, square->gettotalCost());
        if(decideDirection!= 0) {
          this->shortestPath+=",";
        }
        if(this->whenToGetLine > 8) {
          this->shortestPath+="\r\n";
          this->whenToGetLine = 0;
        }
        this->whenToGetLine++;
        vector<State<P> *> successors = searcheable->getAllPossibleStates(square); // generate square's successors
        typename std::vector<State<P> *>::iterator it;
        typename std::vector<State<P> *>::iterator it2;
        for (it = successors.begin(); it != successors.end(); ++it) {
          it2 = std::find(markedNodes.begin(), markedNodes.end(), *it);
          if (it2 == markedNodes.end()) {
            (*it)->setCameFrom(square);
            markedNodes.push_back(*it);
            DFSQueue.push(*it);
          }
        }
      }
    }
    throw "goal not found";
  }
};

#endif //MILE_STONE2__DFS_H_
