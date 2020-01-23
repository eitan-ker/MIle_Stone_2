//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYSERIALSERVER_H
#define MILE_STONE_2_MYSERIALSERVER_H


#include "Server.h"
#include "ClientHandler.h"
#include "Point.h"
#include <iostream>
#include <sys/socket.h>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdio.h>
#include <thread>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>


using namespace std;

class MySerialServer : public Server<string,string,Point> {
public:

    void open(int port, CLientHandler<string,string,Point> *c); // open server with port num
// listen until accept client, than execute ClientHandler
    void executeServer(CLientHandler<string,string,Point> *c, sockaddr_in address, int socketfd);

    void stop(); // close server
// we need to implement protocol of comunication between client and server

};


#endif //MILE_STONE_2_MYSERIALSERVER_H
