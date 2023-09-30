#include "solver.h"
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

void Solver::printSolution(uint_fast8_t state) {
    switch(state) {
        case 0: cout << "Good Edges: "; break;
        case 1: cout << "Group 1: "; break;
        case 2: cout << "Group 2.1: "; break;
        case 3: cout << "Group 2.2: "; break;
        case 4: cout << "Group 3.1: "; break;
        case 5: cout << "Group 3.2: "; break;
        case 6: cout << "Solved State: "; break;
    }
    for (int i = 0; i < pos; ++i) {
        switch(solution[i]) {
            case 0: cout << "U "; break;
            case 1: cout << "R "; break;
            case 2: cout << "F "; break;
            case 3: cout << "D "; break;
            case 4: cout << "L "; break;
            case 5: cout << "B "; break;
            case 6: cout << "U\' "; break;
            case 7: cout << "R\' "; break;
            case 8: cout << "F\' "; break;
            case 9: cout << "D\' "; break;
            case 10: cout << "L\' "; break;
            case 11: cout << "B\' "; break;
            case 12: cout << "U2 "; break;
            case 13: cout << "R2 "; break;
            case 14: cout << "F2 "; break;
            case 15: cout << "D2 "; break;
            case 16: cout << "L2 "; break;
            case 17: cout << "B2 "; break;
        }
    }
    cout << "\n";
}

void Solver::performMove(uint_fast8_t id) {
    switch(id) {
        case 0: c.u(); break;
        case 1: c.r(); break;
        case 2: c.f(); break;
        case 3: c.d(); break;
        case 4: c.l(); break;
        case 5: c.b(); break;
        case 6: c.uPrime(); break;
        case 7: c.rPrime(); break;
        case 8: c.fPrime(); break;
        case 9: c.dPrime(); break;
        case 10: c.lPrime(); break;
        case 11: c.bPrime(); break;
        case 12: c.u2(); break;
        case 13: c.r2(); break;
        case 14: c.f2(); break;
        case 15: c.d2(); break;
        case 16: c.l2(); break;
        case 17: c.b2(); break;
    }
}

void Solver::reverseMove(uint_fast8_t id) {
    switch(id) {
        case 0: c.uPrime(); break;
        case 1: c.rPrime(); break;
        case 2: c.fPrime(); break;
        case 3: c.dPrime(); break;
        case 4: c.lPrime(); break;
        case 5: c.bPrime(); break;
        case 6: c.u(); break;
        case 7: c.r(); break;
        case 8: c.f(); break;
        case 9: c.d(); break;
        case 10: c.l(); break;
        case 11: c.b(); break;
        case 12: c.u2(); break;
        case 13: c.r2(); break;
        case 14: c.f2(); break;
        case 15: c.d2(); break;
        case 16: c.l2(); break;
        case 17: c.b2(); break;
    }
}

void Solver::scramble() {
    istringstream sock{scram};
    string move;
    while(sock >> move) {
        if (move == "U") c.u();
        if (move == "U\'") c.uPrime();
        if (move == "U2") c.u2();
        if (move == "D") c.d();
        if (move == "D\'") c.dPrime();
        if (move == "D2") c.d2();
        if (move == "R") c.r();
        if (move == "R\'") c.rPrime();
        if (move == "R2") c.r2();
        if (move == "L") c.l();
        if (move == "L\'") c.lPrime();
        if (move == "L2") c.l2();
        if (move == "F") c.f();
        if (move == "F\'") c.fPrime();
        if (move == "F2") c.f2();
        if (move == "B") c.b();
        if (move == "B\'") c.bPrime();
        if (move == "B2") c.b2();
    }
}

bool Solver::performAlgorithm() {
    int alg[11] = {3,13,12,14,6,13,12,13,14,9,13};
    for (int i = 0; i < 11; ++i) {
        performMove(alg[i]);
        solution[pos] = alg[i];
        ++pos;
    }
        if (s.checkState(c, 5)) {
        printSolution(5);
        pos = 0;
        moveCount += 11;
        return true;
    }
    pos = 0;
    return false;
}

bool Solver::prune(uint_fast8_t id, uint_fast8_t lastMove, uint_fast8_t state) {
    if (state != 0 && (id == 2 || id == 5 || id == 8 || id == 11)) return true;
    if ((state != 0 && state != 1) && (id == 1 || id == 4 || id == 7 || id == 10)) return true;
    if (state >= 6 && (id == 0 || id == 3 || id == 6 || id == 9)) return true;
    if ((id >= 0 && id <= 2) || (id >= 6 && id <= 8) || (id >= 12 && id <= 14)) {
        if (lastMove % 3 == id % 3) {
            return true;
        }
        return false;
    } else if (lastMove != 18 && lastMove % 6 == id % 6) {
        return true;
    }
    return false;
}

bool Solver::recursive_solve(uint_fast8_t state, uint_fast8_t n, uint_fast8_t lastMove) {
    for(uint_fast8_t i = 1; i < n + 1; ++i) {
        for (uint_fast8_t k = 0; k < 18; ++k) {
            if (prune(k, lastMove, state)) continue;
            performMove(k);
            solution[pos] = k;
            ++pos;
            if (i == 1 && s.checkState(c, state)) {
                printSolution(state);
                moveCount += pos;
                pos = 0;
                return true;
            }
            if (recursive_solve(state, i - 1, k)) {
                return true;
            }
            --pos;
            reverseMove(k);
            }
    }
    return false;
}

int Solver::solve() {
    for(uint_fast8_t i = 0; i < 7; ++i) {
        if (s.checkState(c, i)) {
            printSolution(i);
        } else if (i == 5) {
            if (!performAlgorithm()) {
                recursive_solve(5);
            }
        } else {
            recursive_solve(i);
        }
    }
    cout << "\nMove Count: " << moveCount << endl;
    return moveCount;
}

Solver::Solver(string scram): scram{scram} {
    scramble();
}
