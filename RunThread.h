//
// Created by eizzker on 25/01/2020.
//

#ifndef MILE_STONE_2_RUNTHREAD_H
#define MILE_STONE_2_RUNTHREAD_H
#include "ClientHandler.h"
#include "Point.h"
using namespace std;
class RunThread {
protected:
    int socket;
    CLientHandler<string,string,Point>* clientHandler;
public:
    RunThread(CLientHandler<string,string,Point>* clientHandler1, int socket1) {
        this->clientHandler = clientHandler1;
        this->socket = socket1;
    }

    CLientHandler<string,string,Point>* getClientHandler() {
        return this->clientHandler;
    }
    int get_Client_Socket() {
        return this->socket;
    }
};
#endif //MILE_STONE_2_RUNTHREAD_H
