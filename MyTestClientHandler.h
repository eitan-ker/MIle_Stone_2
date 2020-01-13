//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_MYTESTCLIENTHANDLER_H
#define MILE_STONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h";

class MyTestClientHandler : public CLientHandler {
private :
    Solver solver;
    CacheManager cm;

};


#endif //MILE_STONE_2_MYTESTCLIENTHANDLER_H
