//
// Created by eizzker on 22/01/2020.
//

#ifndef MILE_STONE_2_MYPARALLELSERVER_H
#define MILE_STONE_2_MYPARALLELSERVER_H

#include <netinet/in.h>
#include "Server.h"
#include "Point.h"
#include <iostream>

using namespace std;

class MyParallelServer : public Server<string,string,Point> {
public:
    void open(int port, CLientHandler<string,string,Point> *c); // open server with port num
// listen until accept client, than execute ClientHandler
    void executeServer(CLientHandler<string,string,Point> *c, sockaddr_in address, int socketfd);

    void runThread(CLientHandler<string,string,Point> *c, int client_socket);

    void stop(); // close server
};


#endif //MILE_STONE_2_MYPARALLELSERVER_H
