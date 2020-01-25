//
// Created by eizzker on 15/01/2020.
//
#include "MySerialServer.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "OA.h"
#include "AStar.h"
#include "MyParallelServer.h"

using namespace std;

int main(int argc, char** argv) {

    int portNum = stoi(argv[1]);

    Server<string, string, Point> *s = new MyParallelServer();
    CacheManager<string, string> *cacheFile = new FileCacheManager<string, string>();
    Solver<string, string, Point> *solver = new OA<string, string, Point>();
    CLientHandler<string, string, Point> *c = new MyClientHandler<string, string, Point>(solver, cacheFile);

    s->open(portNum, c);
    int sleeptime = 120000;
    try {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
    }
    catch (...) {
        throw "there was a problem with sleep";
    }
    return 0;
}