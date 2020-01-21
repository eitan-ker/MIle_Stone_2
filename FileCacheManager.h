//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_FILECACHEMANAGER_H
#define MILE_STONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "Solver.h"
using namespace std;
template <typename T, typename Q>
class FileCacheManager : public CacheManager<T,Q> {
 public:
  FileCacheManager<T,Q>(){};
  int doWeHaveSolution(T problem) {
    typename unordered_map<T, Q>::iterator it = this->getProblemQueryMap().begin();
    if (it != this->getProblemQueryMap().end()) {
      return 1;
    } else {
      try {
        ifstream myfile1{problem + ".txt", ios::out};
        if (!myfile1) {
          return 0;
        }
        if (!myfile1.is_open()) {
          return 0;
        }
        return 1;
      } catch(...) {

      }
    } // return if there is a solution
  }
  Q pop(T problem) {
    int hashCode = std::hash<std::string>()(problem);
    if ( this->getProblemQueryMap().find(problem) == this->getProblemQueryMap().end() ) {
      // not found in map, searching file system
      Q obj5;
      try {
        ifstream myfile1{to_string(hashCode), ios::in};
        if(myfile1.is_open()) {
          myfile1 >> obj5;
        }
        myfile1.close();
        this->getProblemQueryMap().insert({problem,obj5});
      } catch (const char *e) {
        cout << e << endl;
      }
      return obj5;
    } else {
      auto it = this->getProblemQueryMap().find(problem);
      return it->second;
    }
  } // pop solution to problem P
  void save(T problem, Q solution) {
    int hashCode = std::hash<std::string>()(problem);
    this->getProblemQueryMap()[problem] = solution; // save solution s to problem P in map
    try {
      ofstream myfile{to_string(hashCode), ios::out | ios::trunc};
      if (!myfile.is_open()) {
        throw "cant open file";
      }
      myfile<<solution;
      myfile.close();
    } catch (const char *e) {
      throw "error oppening file";
    }
  }
};


#endif //MILE_STONE_2_FILECACHEMANAGER_H