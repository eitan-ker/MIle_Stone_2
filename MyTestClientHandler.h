//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYTESTCLIENTHANDLER_H
#define MILE_STONE_2_MYTESTCLIENTHANDLER_H

#include <cstring>
#include <unistd.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <class T, class Q>
class MyTestClientHandler : public CLientHandler {
 private :
  Solver* solver;
  CacheManager<T,Q>* cm;
 public:
  void handleClient(int socket) {
      string next_buff = "";
      int sim_index = 0;
      int endFlag = 0, solFlag = 0, is_sent = 0;
      string solution = "";
      while (endFlag != 1) {
          //reading from client
          char buffer[1024] = {0};
          string value_buf = next_buff;
          int valread = read(socket, buffer, 1024);
          if (!strcmp(buffer, "END")) {
              // stop communication
              endFlag = 1;
          } else {
              int i = 0;
              string bufferString = buffer;
              // send 1024 bites of buffer - info required is 328 bites
              solFlag = this->cm->doWeHaveSolution(value_buf);
              if (solFlag) { // if we have a solution in cache
                  solution = this->cm->pop(value_buf); // we get the solution from cache

                            // send solution to client
                  while(!solution.empty()) {
                      is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);
                  }
                  if (is_sent == -1) {
                      std::cout << "Error sending message" << std::endl;
                  }


              } else {
                  // we don't have a solution
                  solution = this->solver->solve(value_buf); // solution have the solution string

                             // send solution to client
                  while(!solution.empty()) {
                      is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);
                  }
                  if (is_sent == -1) {
                      std::cout << "Error sending message" << std::endl;
                  }


                  // solve with Solver
                  this->cm->save(value_buf ,solution); // save the probkem and solution
              }
          }

      }
  }

  MyTestClientHandler(Solver *s, CacheManager<T,Q>* cache) : solver(s), cm(cache) {}
};


#endif //MILE_STONE_2_MYTESTCLIENTHANDLER_H
