#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdint>
#include <string>
#include "cube.h"
#include "states.h"
#include "solver.h"
#include "searchTree.h"
#define CUBE_COUNT 1

using namespace std;

double round(double a) {
    a = a * 100;
    a = static_cast<int>(a);
    a = a / 100;
    return a;
}

int main() {
    string scramble;
    cout << "Input Scramble: ";
    getline(cin, scramble);
    cout << "\nSolution: " << endl;
    Solver s(scramble);
    clock_t start, end;
    start = clock();
    s.solve();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << round(time_taken);
    cout << " secs" << endl << endl;;
}