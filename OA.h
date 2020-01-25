//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__OT_H_
#define MILE_STONE2__OT_H_

#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"
#include "MatrixConverter.h"
#include "AStar.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "BFS.h"

template<class T, class Q, class P>
class OA : public Solver<T, Q, P> { // gets a problem - we decide how we want to get it(string, io...)
public:

    Q solve(T problem) {
        Searcheable<T, P> *searcheable = new MatrixConverter<string, Point>(problem);
        Searcher<T, Q, P> *a = new AStar<string, string, Point>();
        string solution = a->search(searcheable);
        return solution;
    }
};

#endif //MILE_STONE2__OT_H_