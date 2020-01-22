//
// Created by eizzker on 21/01/2020.
//

#ifndef MILE_STONE_2_BFS_H
#define MILE_STONE_2_BFS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include "Searcher.h"
#include "Searchable.h"

template<class T, class Q, class P>
class BFS : public Searcher<T, Q, P> {
private:
    string shortestPath = "";
public:
    int decideWhereICameFrom(State<P> *state) {/*return the direction we move from parent : 0-initial state,
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
                this->shortestPath = extra + this->shortestPath;
                break;
            case 2 :
                extra = "Right (" + to_string(totalCost) + ")";
                this->shortestPath = extra + this->shortestPath;
                break;
            case 3 :
                extra = "Down (" + to_string(totalCost) + ")";
                this->shortestPath = extra + this->shortestPath;
                break;
            case 4 :
                extra = "Up (" + to_string(totalCost) + ")";
                this->shortestPath = extra + this->shortestPath;
                break;
            default:
                break;
        }
    }

    void makePath(Searcheable<T, P> *searchable) {
        State<P> *curr = searchable->getGoalState();
        // first print of direcion
        int diraction = decideWhereICameFrom(curr);

        WriteDirection(diraction, curr->gettotalCost());

        curr = curr->getCameFrom();
        // all the rest direction prints.

        while (curr->getCameFrom() != nullptr) {
            this->shortestPath = ", " + this->shortestPath;
            int diraction = decideWhereICameFrom(curr);

            if (curr->getCameFrom() == nullptr) {
                WriteDirection(diraction, curr->getCost());

            } else {
                WriteDirection(diraction, curr->gettotalCost());
            }

            curr = curr->getCameFrom();
        }
    }

    Q search(Searcheable<T, P> *searchable) {

        // Mark the source cell as visited
        searchable->getInitialState()->set_visited();

        // Create a queue for BFS
        queue < State<P> * > q;
        q.push(searchable->getInitialState());  // Enqueue source cell

        // Do a BFS starting from source cell
        while (!q.empty()) {
            State<P> *curr = q.front();
            Point *pt = curr->getState();

            // If we have reached the destination cell,
            // we are done
            if (pt->getRow() == searchable->getGoalState()->getState()->getRow()
                && pt->getCol() == searchable->getGoalState()->getState()->getCol()) {
                int total = curr->gettotalCost(); // need to b changed to string of path;
                makePath(searchable);
                return this->shortestPath;
            }
            // Otherwise dequeue the front cell in the queue
            // and enqueue its adjacent cells
            q.pop();
            vector<State<P> *> adj = searchable->getAllPossibleStates(curr);
            int i = 0;
            int size = adj.size();
            for (i = 0; i < size; i++) {
                if (adj[i]->getVisited() == 0) {
                    adj[i]->set_visited();
                    adj[i]->setCameFrom(curr);
                    q.push(adj[i]);
                }
            }


        }
        // Return -1 if destination cannot be reached
        throw "could not find path";
    }


};


#endif //MILE_STONE_2_BFS_H
