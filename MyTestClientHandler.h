//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYTESTCLIENTHANDLER_H
#define MILE_STONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <class T, class Q>
class MyTestClientHandler : public CLientHandler {
 private :
  Solver* solver;
  CacheManager<T,Q>* cm;
 public:
  void handleClient(int socket);

  MyTestClientHandler(Solver *s, CacheManager<T,Q>* cache) : solver(s), cm(cache) {}
};


#endif //MILE_STONE_2_MYTESTCLIENTHANDLER_H
