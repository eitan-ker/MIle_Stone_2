//
// Created by eizzker on 17/01/2020.
//

#ifndef MILE_STONE_2_MYCLIENTHANDLER_H
#define MILE_STONE_2_MYCLIENTHANDLER_H

#include <cstring>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <vector>
#include <sstream>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"


template <class T, class Q, class P>

class MyClientHandler : public CLientHandler {
private :
    Solver<T, Q,P> *solver;
    CacheManager<T, Q> *cm;
public:
    void handleClient(int socket) {
        int sim_index = 0;
        int endFlag = 0, solFlag = 0, is_sent = 0, iterFlag = 0, soluLength = 0;
        char *splitBuf;
        string solution = "", bufferString = "", temp = "";
        char buffer[1024] = {0};
        int valread = read(socket, buffer, 1024);
        bufferString = buffer;
        temp = bufferString + ",";
        bufferString = bufferString + "\n";
        soluLength = countLineLength(temp);
        int i = 0;
        for (i = 0; i < soluLength + 2; i++) {
            char tempBuffer[1024] = {0};
            int tempValRead = read(socket, tempBuffer, 1024);
            bufferString = bufferString + tempBuffer + "\n";
        }
        // send 1024 bites of buffer - info required is 328 bites
        solFlag = this->cm->doWeHaveSolution(bufferString);
        if (solFlag) { // if we have a solution in cache
            solution = this->cm->pop(bufferString); // we get the solution from cache




            // send solution to client
            is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);




            if (is_sent == -1) {
                std::cout << "Error sending message" << std::endl;
            }
        } else {
            // we don't have a solution
            solution = this->solver->solve(bufferString); // solution have the solution string



            // send solution to client
            is_sent = send(socket, solution.c_str(), strlen(solution.c_str()), 0);



            if (is_sent == -1) {
                std::cout << "Error sending message" << std::endl;
            }
            // solve with Solver
            this->cm->save(bufferString, solution); // save the probkem and solution
        }
    }

    MyClientHandler(Solver<T,Q,P> *s, CacheManager<T, Q> *cache) : solver(s), cm(cache) {}

    int countLineLength(string line) {
        std::string s = line;
        std::string delimiter = ",";
        int counter = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            counter++;
            s.erase(0, pos + delimiter.length());
        }
        return counter;
    }
};


#endif //MILE_STONE_2_MYCLIENTHANDLER_H
