//
// Created by eizzker on 13/01/2020.
//

#ifndef MILE_STONE_2_FILECACHEMANAGER_H
#define MILE_STONE_2_FILECACHEMANAGER_H

#include <vector>
#include <algorithm>
#include <sstream>
#include "CacheManager.h"
#include "Solver.h"

using namespace std;

template<typename T, typename Q>
class FileCacheManager : public CacheManager<T, Q> {
public:
    FileCacheManager<T, Q>() {};

    int doWeHaveSolution(T problem) {
        int hashCode = std::hash<std::string>()(problem); //calculate hashcode of problem in case its a string
        typename unordered_map<T, Q>::iterator it = this->getProblemQueryMap().begin();
        it = this->getProblemQueryMap().find(problem);
        if (it != this->getProblemQueryMap().end()) {
            return 1;
        } else {
            try {
                ifstream myfile1{to_string(hashCode), ios::in};
                if (!myfile1) {
                    return 0;
                }
                if (!myfile1.is_open()) {
                    return 0;
                }
                return 1;
            } catch (...) {

            }
        } // return 1 if there is a solution
    }

    std::string string_from_vector(const std::vector<std::string> &pieces) {
        std::stringstream ss;

        for (std::vector<std::string>::const_iterator itr = pieces.begin();
             itr != pieces.end();
             ++itr) {
            ss << *itr;
        }

        return ss.str();
    }

    Q pop(T problem) { //pop solution for the client
        int hashCode = std::hash<std::string>()(problem);
        if (this->getProblemQueryMap().find(problem) == this->getProblemQueryMap().end()) {
            // not found in map, searching file system
            Q obj5;
            string res;
            std::vector<std::string> lines;
            try {
                ifstream myfile1{to_string(hashCode), ios::in};
                std::string line;
                if (myfile1.is_open()) { //start getting string from file line by line
                    while (!myfile1.eof()) {
                        getline(myfile1, line);
                        lines.push_back(line + "\n");
                    }
                }
                obj5 = string_from_vector(lines); //eventually assign vector to obj5
                myfile1.close();
                this->getProblemQueryMap().insert(
                        {problem, obj5}); //add this problem-solution pair to the map for future use
            } catch (const char *e) {
                throw e;
            }
            return obj5;
        } else {
            auto it = this->getProblemQueryMap().find(problem);
            return it->second;
        }
    } // pop solution to problem P
    void save(T problem, Q solution) { //save solution to map and file
        int hashCode = std::hash<std::string>()(problem);
        this->getProblemQueryMap()[problem] = solution; // save solution s to problem P in map
        try {
            ofstream myfile{to_string(hashCode), ios::out | ios::trunc};
            if (!myfile.is_open()) {
                throw "cant open file";
            }
            myfile << solution;
            myfile.close();
        } catch (const char *e) {
            throw "error oppening file";
        }
    }
};


#endif //MILE_STONE_2_FILECACHEMANAGER_H