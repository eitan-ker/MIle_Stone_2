//
// Created by eizzker on 15/01/2020.
//
#include <stdio.h>
#include <thread>
#include "MySerialServer.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
using namespace std;

int main() {
  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* cacheFile = new FileCacheManager<string, string>();
  Solver* solver = new StringReverser();
  CLientHandler *c = new MyTestClientHandler<string,string>(solver, cacheFile);
  s->executeServer(8520, c);

}