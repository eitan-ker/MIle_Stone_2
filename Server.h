//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_SERVER_H
#define MILE_STONE_2_SERVER_H


#include "ClientHandler.h"
template <class T, class Q, class P>
class Server {
 public:
  virtual void open(int port, CLientHandler<T,Q,P> *c) = 0; // open server with port num
  virtual void stop() = 0; // close server for the same port
  virtual ~Server(){}

};


#endif //MILE_STONE_2_SERVER_H
