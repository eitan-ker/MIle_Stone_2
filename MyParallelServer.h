//
// Created by eizzker on 25/01/2020.
//

#ifndef MILE_STONE_2_MYPARALLELTESTER_H
#define MILE_STONE_2_MYPARALLELTESTER_H

#include "Server.h"
#include "FileCacheManager.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "ClientHandler.h"
#include "Point.h"
using namespace std;

class MyParallelServer : public Server<string,string,Point>{
public:
    void open(int port, CLientHandler<string,string,Point> *c); // open server with port num
    void stop(); // close server
};


#endif //MILE_STONE_2_MYPARALLELTESTER_H
