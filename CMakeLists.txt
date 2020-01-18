cmake_minimum_required(VERSION 3.15)
project(Mile_Stone2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Mile_Stone_2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h StringReverser.h MyTestClientHandler.h Solver.cpp Solver.h CacheManager.h FileCacheManager.h OT.h Searchable.h Searcher.h State.h AStar.h)