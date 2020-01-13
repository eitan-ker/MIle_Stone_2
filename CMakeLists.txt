cmake_minimum_required(VERSION 3.15)
project(Mile_Stone_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Mile_Stone_2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h)