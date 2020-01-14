//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_SERVER_H
#define MILE_STONE_2_SERVER_H


#include "ClientHandler.h"

class Server {
public:
    virtual void open(int port, CLientHandler c) = 0; // open server with port num
    virtual void stop() = 0; // close server for the same port

    virtual void protocol();
    // do we need more func?
};


#endif //MILE_STONE_2_SERVER_H
