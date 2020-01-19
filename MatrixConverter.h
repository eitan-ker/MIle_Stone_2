//
// Created by eizzker on 17/01/2020.
//

#ifndef MILE_STONE_2_MATRIXCONVERTER_H
#define MILE_STONE_2_MATRIXCONVERTER_H

#include <sstream>
#include "Searchable.h"
#include "Solver.h"
#include "State.h"
#include "Point.h"

template<class T, class P>

class MatrixConverter : public Searcheable<T, P> {
private:
    vector<vector<State<Point> *>> _matrix;
    State<Point> *initalState;
    State<Point> *goalState;
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
        // intial state and goal state vector
        vector<int> states(2);
        // lines
        for (i = 0; i < matrLength; i++) {
            if (r == lineLength + 2) {
                break;
            }
            if (matr[i] == '\n') {
                // if we initial matrix
                if (r < lineLength) {
                    stringValues = onlyValues(line + ",", lineLength);
                    vector<State<Point> *> vec;
                    // columns
                    for (c = 0; c < lineLength; c++) {
                        Point *p = new Point(r, c);
                        State<Point> *s = new State<Point>(p, stringValues[c]);
                        vec.insert(vec.end(), s);
                    }
                    _matrix.push_back(vec);
                    r++;
                    line = "";
                    continue;
                } else {
                    states = onlyValues(line + ",", 2);
                    int y = states.back();
                    states.pop_back();
                    int x = states.back();
                    states.pop_back();
                    if (r == lineLength) {
                        this->initalState = _matrix[x][y];
                    } else {
                        this->goalState = _matrix[x][y];
                    }
                    r++;
                    line = "";
                    continue;
                }
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

    MatrixConverter(string problem){
        int lineLength = countLength(problem);
        initializeArray(problem, lineLength);
    }

    State<Point> *getInitialState() {
        return this->initalState;
    }

    bool isGoalState(State<Point>& state) {
  State<P>* goal = this->getGoalState();
        return state.Equals(*goal);
    }
    State<Point>* getGoalState() {
      return this->goalState;
    }

    vector<State<Point>> getAllPossibleStates(State<Point>& state) {
        int leftFlag = 0, rightFlag = 0, upFlag = 0, downFlag = 0;
        vector<State<Point> *> possibleStates;
        double positionRow = state.getState().getRow();
        double positionCol = state.getState().getCol();
        int matrixSize = _matrix.size();
        if (positionRow != 0) {
            possibleStates.push_back(_matrix[positionRow - 1][positionCol]);
        }
        if (positionRow != matrixSize - 1) {
            possibleStates.push_back(_matrix[positionRow + 1][positionCol]);
        }
        if (positionCol != 0) {
            possibleStates.push_back(_matrix[positionRow][positionCol - 1]);
        }
        if (positionCol != matrixSize - 1) {
            possibleStates.push_back(_matrix[positionRow][positionCol + 1]);
        }
        return possibleStates;
    }
};


#endif //MILE_STONE_2_MATRIXCONVERTER_H