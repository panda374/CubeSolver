#ifndef STATES_H
#define STATES_H

#include "cube.h"

class States {
public:
    bool goodEdges(const Cube c);
    bool cross(const Cube c);
    bool pair1(const Cube c);
    bool pair2(const Cube c);
    bool pair3(const Cube c);
    bool pair4(const Cube c);
    bool yellowSide(const Cube c);
    bool group1(const Cube c);
    bool group2_1(const Cube c);
    bool group2_2(const Cube c);
    bool group3_1(const Cube c);
    bool group3_2(const Cube c);
    bool group3_3(const Cube c);
    bool cornersPermutated(const Cube c);
    bool solved(const Cube c);
    bool checkState(const Cube c, unsigned int id);
};

#endif