//
// Created by eizzker on 13/01/2020.
//
using namespace std;

#include <unistd.h>
#include <cstring>
#include "MyTestClientHandler.h"
template <typename T, typename Q>
void MyTestClientHandler<T,Q> :: handleClient(int socket, int sol) {
    string next_buff = "";
    int  sim_index = 0;
    int endFlag = 0, solFlag = 0;

    while (endFlag != 1) {
        //reading from client
        char buffer[1024] = {0};
        string value_buf = next_buff;
        int valread = read(socket, buffer, 1024);
        if(!strcmp(buffer, "END")) {
            endFlag = 1;
        } else {
            int i = 0;
            string bufferString = buffer;
            // send 1024 bites of buffer - info required is 328 bites
            for (i = 0; i < valread; i++) {
                if ((bufferString[i] == ',') || (buffer[i] == '\n')) {
                    sim_index++;
                    value_buf = "";
                    // we got \n now - end of line
                    if (buffer[i] == '\n') {

                        solFlag = this->cm.doWeHaveSolution(value_buf);
                        if (solFlag) { // if we have a colution in cache
                            this->solver = this->cm.pop(value_buf); // we get the solution from cache
                        } else {
                            // we don;t have a solution

                            // solve with Solver
                            // solver = new Solver(value_buf)
                            this->cm.save(solver);
                        }

                        sim_index = 0;
                    }
                    continue;
                } else if (i == valread - 1) { // in case i have string that continues in the next buffer
                    value_buf = value_buf + bufferString[i];
                    next_buff = value_buf;
                    continue;
                }
                // concatenate value
                value_buf = value_buf + bufferString[i];
            }
        }

    }
    //ofstream outputfile{"output.txt"};
    // reading line by line
    // for each line:
    // search solution in cache
    // else(not found) send to resolver]
}