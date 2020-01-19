//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__OT_H_
#define MILE_STONE2__OT_H_
#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"
#include "MatrixConverter.h"

template<class T,class Q, class P>
class OA : public Solver<T,Q,P> { // gets a problem - we decide how we want to get it(string, io...)
private:
    //Searcheable<T>* _searchable;
   // Searcher<T,Q>* _searcher;
    Searcheable<T,P>* searcheable;
public:
    Q solve(T problem) {
        // State<T> state = new State<string>();
//        searcheable = new MatrixConverter<string,Point>(problem);
        cout << "endl" << endl;
    }
  //  OA(Searcher<T,Q>* searcher) : _searcher(searcher) {}
};
#endif //MILE_STONE2__OT_H_