//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_CLIENTHANDLER_H
#define MILE_STONE_2_CLIENTHANDLER_H
#include <fstream>
template <class T, class Q, class P>
class CLientHandler {
 public:
  virtual void handleClient(int socket) = 0; // input stream
};
#endif //MILE_STONE_2_CLIENTHANDLER_H
