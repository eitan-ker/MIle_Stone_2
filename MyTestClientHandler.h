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
  Solver<T,Q>* solver;
  CacheManager<T,Q>* cm;
 public:
  void handleClient(int socket) {
      int sim_index = 0;
      int endFlag = 0, solFlag = 0, is_sent = 0;
      char* splitBuf;
      string solution = "";
      //reading from client
      char buffer[1024] = {0};
      int valread = read(socket, buffer, 1024);
      splitBuf = strtok(buffer, "\n");
      while (endFlag != 1) {

          if (!strcmp(splitBuf, "END")) {
              // stop communication
              endFlag = 1;
          } else {
              int i = 0;
              string bufferString = buffer;
              // send 1024 bites of buffer - info required is 328 bites
              solFlag = this->cm->doWeHaveSolution(splitBuf);
              if (solFlag) { // if we have a solution in cache
                  solution = this->cm->pop(splitBuf); // we get the solution from cache
                  cout << solution << endl;

                            // send solution to client
                      is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);

                  if (is_sent == -1) {
                      std::cout << "Error sending message" << std::endl;
                  }

              } else {
                  // we don't have a solution
                  solution = this->solver->solve(splitBuf); // solution have the solution string
                  cout << solution << endl;

                             // send solution to client
                      is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);
                  if (is_sent == -1) {
                      std::cout << "Error sending message" << std::endl;
                  }


                  // solve with Solver
                  this->cm->save(splitBuf ,solution); // save the probkem and solution
              }
              splitBuf = strtok(NULL, "\n");
          }

      }
  }

  MyTestClientHandler(Solver<T,Q> *s, CacheManager<T,Q>* cache) : solver(s), cm(cache) {}
};


#endif //MILE_STONE_2_MYTESTCLIENTHANDLER_H
