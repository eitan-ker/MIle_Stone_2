//
// Created by eizzker on 17/01/2020.
//

#ifndef MILE_STONE_2_MATRIXCONVERTER_H
#define MILE_STONE_2_MATRIXCONVERTER_H

#include <sstream>
#include "Searchable.h"
#include "Solver.h"
#include "State.h"

template<class T>

class MatrixConverter : public Searcheable<T> {
private:
    vector<vector<State<string> *>> _matrix;
public :
    // make matrix
    int countLength(string problem) {
        std::string s = problem;
        std::string delimiter = "\n", delimiter2 = ",";
        int counter = 0;
        size_t pos = 0, pos2 = 0;
        std::string token, token2;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            token = token + ",";
            while ((pos2 = token.find(delimiter2)) != std::string::npos) {
                token2 = token.substr(0, pos2);
                counter++;
                token.erase(0, pos2 + delimiter2.length());
            }
            break;
        }
        return counter;
    }

    void initializeArray(string matr, int lineLength) {
        int i = 0, j = 0, counter = 0, r = 0, c = 0, matrLength = matr.length();
        string line = "";
        vector<int> stringValues(lineLength);
        for (i = 0; i < matrLength; i++) {
            if (r == lineLength) {
                break;
            }
            if (matr[i] == '\n') {
                stringValues = onlyValues(line + ",", lineLength);
                vector<State<string> *> vec;
                for (c = 0; c < lineLength; c++) {
                    stringstream rr, cc;
                    rr << r;
                    cc << c;
                    string rs = rr.str();
                    string cs = cc.str();
                    string state = rs + "," + cs;
                    State<string> *s = new State<string>(state, stringValues[c]);
                    vec.insert(vec.end(), s);
                }
                _matrix.push_back(vec);
                r++;
                line = "";
                continue;
            }
            line = line + matr[i];
        }
    }

    vector<int> onlyValues(string stringBuf, int length) {
        std::string s = stringBuf;
        std::string delimiter = ",";
        int counter = 0;
        size_t pos = 0;
        std::string token;
        vector<int> stringValues;
        int tempNum = 0;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            stringstream convert(token);
            convert >> tempNum;
            stringValues.push_back(tempNum);
            s.erase(0, pos + delimiter.length());
        }
        return stringValues;
    }

    MatrixConverter(string problem) {
        int lineLength = countLength(problem);
        initializeArray(problem, lineLength);
    }

    State<T> getInitialState() {
    }

    bool isGoalState(State<T> state) {
    }

    vector<State<T>> getAllPossibleStates(State<T> state) {
    }
};


#endif //MILE_STONE_2_MATRIXCONVERTER_H