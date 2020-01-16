//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYSERIALSERVER_H
#define MILE_STONE_2_MYSERIALSERVER_H


#include "Server.h"
#include "ClientHandler.h"
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

class MySerialServer : public Server {
public:

    void open(int port, CLientHandler *c); // open server with port num
// listen until accept client, than execute ClientHandler
    void executeServer(int port, CLientHandler *c);

    void stop(); // close server
// we need to implement protocol of comunication between client and server
    void protocol();

};


#endif //MILE_STONE_2_MYSERIALSERVER_H
