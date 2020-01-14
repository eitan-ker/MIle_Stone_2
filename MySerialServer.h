//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYSERIALSERVER_H
#define MILE_STONE_2_MYSERIALSERVER_H


#include "Server.h"
#include "ClientHandler.h"

class MySerialServer: public Server {
  void open(int port, CLientHandler c) = 0; // open server with port num
  void stop(); // close server
// we need to implement protocol of comunication between client and server
  void protocol();

};


#endif //MILE_STONE_2_MYSERIALSERVER_H
