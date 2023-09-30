#ifndef SOLVER_H
#define SOLVER_H

#include "cube.h"
#include "states.h"
#include <string>
#include <iostream>
#include <vector>

class Solver {
    Cube c;
    States s;
    std::string scram;
    int moveCount = 0;

    uint_fast8_t solution[15];
    uint_fast8_t pos = 0;
public:
    void printSolution(uint_fast8_t state);
    void performMove(uint_fast8_t id);
    void reverseMove(uint_fast8_t id);
    void scramble();
    bool performAlgorithm();
    bool prune(uint_fast8_t id, uint_fast8_t lastMove, uint_fast8_t state);
    bool recursive_solve(uint_fast8_t state, uint_fast8_t n = 15, uint_fast8_t lastMove = 18);
    int solve();

    Solver(std::string scram);
};

#endif