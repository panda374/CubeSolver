#ifndef CUBE_H
#define CUBE_H

#include <iostream>

struct Edge {
    int index;
    int orientation;
};

struct Corner {
    int index;
    int orientation;
};

class Cube {
public:
    Edge edges[12];
    Corner corners[8];

    void print();
    void updateCornerOrientation(int id, int amount);
    void updateEdgeOrientation(int id);
    void u();
    void uPrime();
    void u2();
    void d();
    void dPrime();
    void d2();
    void r();
    void rPrime();
    void r2();
    void l();
    void lPrime();
    void l2();
    void f();
    void fPrime();
    void f2();
    void b();
    void bPrime();
    void b2();
    Cube();
    Cube(const Cube &other);
    Cube &operator=(const Cube &other);
};

#endif