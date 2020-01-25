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
private:

public:
    Q solve(T problem) {
        // State<T> state = new State<string>();
        Searcheable<T, P> *searcheable = new MatrixConverter<string, Point>(problem);
        Searcher<T, Q, P> *a = new BFS<string, string, Point>();
        string solution = a->search(searcheable);
        return solution;
    }
	virtual ~OA() {}
};

#endif //MILE_STONE2__OT_H_
