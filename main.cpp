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
#include "MyParallelTester.h"
using namespace std;
int main() {
  //  Server<string,string,Point>* s = new MySerialServer();
    Server<string,string,Point>* s = new MyParallelServer();

  CacheManager<string, string>* cacheFile = new FileCacheManager<string, string>();
  Solver<string,string,Point>* solver = new OA<string,string,Point>(/*new AStar<string, string>()*/);
  CLientHandler<string,string,Point> *c = new MyClientHandler<string,string,Point>(solver, cacheFile);
  s->open(8520, c);
    int sleeptime = 1200000000;
    try {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
    }
    catch (...) {
        throw "there was a problem with sleep";
    }
return 0;
}