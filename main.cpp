//
// Created by eizzker on 15/01/2020.
//
#include "MySerialServer.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
using namespace std;
int main() {
  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* cacheFile = new FileCacheManager<string, string>();
  Solver<string,string>* solver = new StringReverser<string,string>();
  CLientHandler *c = new MyTestClientHandler<string,string>(solver, cacheFile);
  s->open(8520, c);
    int sleeptime = 120000;
    try {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));
    }
    catch (...) {
        throw "there was a problem with sleep";
    }
return 0;
}