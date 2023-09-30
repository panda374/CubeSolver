#include "states.h"

bool States::goodEdges(const Cube c) {
    for (int i = 0; i < 12; ++i) {
        if (c.edges[i].orientation != 0) 
            return false;
    }
    return true;
}

bool States::cross(const Cube c) {
    for (int i = 8; i < 12; ++i) {
        if (c.edges[i].index != i || c.edges[i].orientation != 0) {
            return false;
        }
    }
    return true;
}

bool States::pair1(const Cube c) {
    if (c.edges[5].index == 5 && c.edges[5].orientation == 0 && c.corners[4].index == 4 && c.corners[4].orientation == 0) {
        return true;
    }
    return false;
}

bool States::pair2(const Cube c) {
    if (c.edges[4].index == 4 && c.edges[4].orientation == 0 && c.corners[5].index == 5 && c.corners[5].orientation == 0) {
        return true;
    }
    return false;
}

bool States::pair3(const Cube c) {
    if (c.edges[7].index == 7 && c.edges[7].orientation == 0 && c.corners[6].index == 6 && c.corners[6].orientation == 0) {
        return true;
    }
    return false;
}

bool States::pair4(const Cube c) {
    if (c.edges[6].index == 6 && c.edges[6].orientation == 0 && c.corners[7].index == 7 && c.corners[7].orientation == 0) {
        return true;
    }
    return false;
}

bool States::yellowSide(const Cube c) {
    for (int i = 0; i < 4; ++i) {
        if (c.corners[i].orientation != 0) {
            return false;
        }
    }
    return true;
}

bool States::group1(const Cube c) {
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].orientation != 0) {
            return false;
        }
    }
    if ((c.edges[4].index == 4 || c.edges[4].index == 5 || c.edges[4].index == 6 || c.edges[4].index == 7) &&
        (c.edges[5].index == 4 || c.edges[5].index == 5 || c.edges[5].index == 6 || c.edges[5].index == 7) &&
        (c.edges[6].index == 4 || c.edges[6].index == 5 || c.edges[6].index == 6 || c.edges[6].index == 7) &&
        (c.edges[7].index == 4 || c.edges[7].index == 5 || c.edges[7].index == 6 || c.edges[7].index == 7)) {
        return true;
    }
    return false;
}

bool States::group2_1(const Cube c) {
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].index % 2 != i % 2) {
            return false;
        }
    }
    if ((c.edges[4].index == 4 || c.edges[4].index == 5 || c.edges[4].index == 6 || c.edges[4].index == 7) &&
        (c.edges[5].index == 4 || c.edges[5].index == 5 || c.edges[5].index == 6 || c.edges[5].index == 7) &&
        (c.edges[6].index == 4 || c.edges[6].index == 5 || c.edges[6].index == 6 || c.edges[6].index == 7) &&
        (c.edges[7].index == 4 || c.edges[7].index == 5 || c.edges[7].index == 6 || c.edges[7].index == 7)) {
           return true;
        }
    return false;
}

bool States::group2_2(const Cube c) {
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].index % 2 != i % 2) {
            return false;
        }
    }
    if ((c.edges[1].index == 1 || c.edges[1].index == 3 || c.edges[1].index == 9 || c.edges[1].index == 11) &&
        (c.edges[3].index == 1 || c.edges[3].index == 3 || c.edges[3].index == 9 || c.edges[3].index == 11) &&
        (c.edges[9].index == 1 || c.edges[9].index == 3 || c.edges[9].index == 9 || c.edges[9].index == 11) &&
        (c.edges[11].index == 1 || c.edges[11].index == 3 || c.edges[11].index == 9 || c.edges[11].index == 11) &&

        (c.edges[4].index == 4 || c.edges[4].index == 5 || c.edges[4].index == 6 || c.edges[4].index == 7) &&
        (c.edges[5].index == 4 || c.edges[5].index == 5 || c.edges[5].index == 6 || c.edges[5].index == 7) &&
        (c.edges[6].index == 4 || c.edges[6].index == 5 || c.edges[6].index == 6 || c.edges[6].index == 7) &&
        (c.edges[7].index == 4 || c.edges[7].index == 5 || c.edges[7].index == 6 || c.edges[7].index == 7))
            return true;
    return false;
}

bool States::group3_1(const Cube c) {
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].index % 2 != i % 2) {
            return false;
        }
    }
    for (int i = 0; i < 4; i += 2) {
        if (c.corners[i].index != c.corners[i+1].index - 1) {
            return false;
        }
    }
    if ((c.edges[1].index == 1 || c.edges[1].index == 3 || c.edges[1].index == 9 || c.edges[1].index == 11) &&
        (c.edges[3].index == 1 || c.edges[3].index == 3 || c.edges[3].index == 9 || c.edges[3].index == 11) &&
        (c.edges[9].index == 1 || c.edges[9].index == 3 || c.edges[9].index == 9 || c.edges[9].index == 11) &&
        (c.edges[11].index == 1 || c.edges[11].index == 3 || c.edges[11].index == 9 || c.edges[11].index == 11) &&

        (c.edges[4].index == 4 || c.edges[4].index == 5 || c.edges[4].index == 6 || c.edges[4].index == 7) &&
        (c.edges[5].index == 4 || c.edges[5].index == 5 || c.edges[5].index == 6 || c.edges[5].index == 7) &&
        (c.edges[6].index == 4 || c.edges[6].index == 5 || c.edges[6].index == 6 || c.edges[6].index == 7) &&
        (c.edges[7].index == 4 || c.edges[7].index == 5 || c.edges[7].index == 6 || c.edges[7].index == 7))
            return true;
    return false;
}

bool States::group3_2(const Cube c) {
    for (int i = 0; i < 8; i += 2) {
        if (c.corners[i].index != c.corners[i+1].index - 1) {
            return false;
        }
    }
    if ((c.edges[1].index == 1 || c.edges[1].index == 3 || c.edges[1].index == 9 || c.edges[1].index == 11) &&
        (c.edges[3].index == 1 || c.edges[3].index == 3 || c.edges[3].index == 9 || c.edges[3].index == 11) &&
        (c.edges[9].index == 1 || c.edges[9].index == 3 || c.edges[9].index == 9 || c.edges[9].index == 11) &&
        (c.edges[11].index == 1 || c.edges[11].index == 3 || c.edges[11].index == 9 || c.edges[11].index == 11) &&

        (c.edges[4].index == 4 || c.edges[4].index == 5 || c.edges[4].index == 6 || c.edges[4].index == 7) &&
        (c.edges[5].index == 4 || c.edges[5].index == 5 || c.edges[5].index == 6 || c.edges[5].index == 7) &&
        (c.edges[6].index == 4 || c.edges[6].index == 5 || c.edges[6].index == 6 || c.edges[6].index == 7) &&
        (c.edges[7].index == 4 || c.edges[7].index == 5 || c.edges[7].index == 6 || c.edges[7].index == 7))
            return true;
    return false;
}

bool States::cornersPermutated(const Cube c) {
    for (int i = 4; i < 12; ++i) {
        if (c.edges[i].index != i) {
            return false;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].index != i) {
            return false;
        }
    }
    return true;
}

bool States::solved(const Cube c) {
    for (int i = 0; i < 12; ++i) {
        if (c.edges[i].index != i) {
            return false;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (c.corners[i].index != i) {
            return false;
        }
    }
    return true;
}

bool States::checkState(const Cube c, unsigned int id) {
    switch(id) {
        case 0:
            return goodEdges(c); break;
        case 1:
            return group1(c); break;
        case 2:
            return group2_1(c); break;
        case 3:
            return group2_2(c); break;
        case 4:
            return group3_1(c); break;
        case 5:
            return group3_2(c); break;
        case 6:
            return solved(c); break;
    }
    return false;
}