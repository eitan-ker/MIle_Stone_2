//
// Created by meni on 14/01/2020.
//
#include <string>
#include "StringReverser.h"
using namespace std;
string StringReverser::solve(string problem) { //reverse the given string as a parameter
  int i = problem.length() - 1;
  const char* token = &problem[i];
  string s = "\0";
  while(i >= 0) {
    s+=*token;
    token--;
    i--;
  }
  return s;
}
