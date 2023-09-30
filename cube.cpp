#include "cube.h"

using namespace std;

void Cube::print() {
     for (int i = 0; i < 12; ++i) {
          cout << i << ".\tid: " << edges[i].index << "\tor: " << edges[i].orientation << endl; 
     }
     cout << '\n';
     for (int i = 0; i < 8; ++i) {
          cout << i << ".\tid: " << corners[i].index << "\tor: " << corners[i].orientation << endl; 
     }
}

void Cube::updateCornerOrientation(int id, int amount) {
     corners[id].orientation += amount;
     corners[id].orientation %= 3;
}

void Cube::updateEdgeOrientation(int id) {
     edges[id].orientation ^= 1;
}

void Cube::u() {
     Corner temp = corners[0];
     corners[0] = corners[3];
     corners[3] = corners[2];
     corners[2] = corners[1];
     corners[1] = temp;

     Edge temp2 = edges[0];
     edges[0] = edges[3];
     edges[3] = edges[2];
     edges[2] = edges[1];
     edges[1] = temp2;
}
void Cube::uPrime() {
     Corner temp = corners[1];
     corners[1] = corners[2];
     corners[2] = corners[3];
     corners[3] = corners[0];
     corners[0] = temp;

     Edge temp2 = edges[1];
     edges[1] = edges[2];
     edges[2] = edges[3];
     edges[3] = edges[0];
     edges[0] = temp2;
}
void Cube::u2() {
     swap(corners[0], corners[2]);
     swap(corners[1], corners[3]);
     
     swap(edges[0], edges[2]);
     swap(edges[1], edges[3]);
}
void Cube::d() {
     Corner temp = corners[4];
     corners[4] = corners[7];
     corners[7] = corners[6];
     corners[6] = corners[5];
     corners[5] = temp;

     Edge temp2 = edges[8];
     edges[8] = edges[11];
     edges[11] = edges[10];
     edges[10] = edges[9];
     edges[9] = temp2;
}
void Cube::dPrime() {
     Corner temp = corners[5];
     corners[5] = corners[6];
     corners[6] = corners[7];
     corners[7] = corners[4];
     corners[4] = temp;

     Edge temp2 = edges[9];
     edges[9] = edges[10];
     edges[10] = edges[11];
     edges[11] = edges[8];
     edges[8] = temp2;
}
void Cube::d2() {
     swap(corners[4], corners[6]);
     swap(corners[5], corners[7]);

     swap(edges[8], edges[10]);
     swap(edges[9], edges[11]);
}
void Cube::r() {
     Corner temp = corners[1];
     corners[1] = corners[2];
     corners[2] = corners[5];
     corners[5] = corners[6];
     corners[6] = temp;

     Edge temp2 = edges[1];
     edges[1] = edges[4];
     edges[4] = edges[9];
     edges[9] = edges[7];
     edges[7] = temp2;
     updateCornerOrientation(6,2);
     updateCornerOrientation(5,1);
     updateCornerOrientation(2,2);
     updateCornerOrientation(1,1);
}
void Cube::rPrime() {
     Corner temp = corners[6];
     corners[6] = corners[5];
     corners[5] = corners[2];
     corners[2] = corners[1];
     corners[1] = temp;

     Edge temp2 = edges[7];
     edges[7] = edges[9];
     edges[9] = edges[4];
     edges[4] = edges[1];
     edges[1] = temp2;
     updateCornerOrientation(6,2);
     updateCornerOrientation(5,1);
     updateCornerOrientation(2,2);
     updateCornerOrientation(1,1);
}
void Cube::r2() {
     swap(corners[1], corners[5]);
     swap(corners[2], corners[6]);

     swap(edges[1], edges[9]);
     swap(edges[4], edges[7]);
}
void Cube::l() {
     Corner temp = corners[0];
     corners[0] = corners[7];
     corners[7] = corners[4];
     corners[4] = corners[3];
     corners[3] = temp;

     Edge temp2 = edges[3];
     edges[3] = edges[6];
     edges[6] = edges[11];
     edges[11] = edges[5];
     edges[5] = temp2;
     updateCornerOrientation(7,1);
     updateCornerOrientation(4,2);
     updateCornerOrientation(3,1);
     updateCornerOrientation(0,2);
}
void Cube::lPrime() {
     Corner temp = corners[3];
     corners[3] = corners[4];
     corners[4] = corners[7];
     corners[7] = corners[0];
     corners[0] = temp;

     Edge temp2 = edges[5];
     edges[5] = edges[11];
     edges[11] = edges[6];
     edges[6] = edges[3];
     edges[3] = temp2;
     updateCornerOrientation(7,1);
     updateCornerOrientation(4,2);
     updateCornerOrientation(3,1);
     updateCornerOrientation(0,2);
}
void Cube::l2() {
     swap(corners[0], corners[4]);
     swap(corners[3], corners[7]);
     
     swap(edges[3], edges[11]);
     swap(edges[5], edges[6]);
}
void Cube::f() {
     Corner temp = corners[3];
     corners[3] = corners[4];
     corners[4] = corners[5];
     corners[5] = corners[2];
     corners[2] = temp;

     Edge temp2 = edges[2];
     edges[2] = edges[5];
     edges[5] = edges[8];
     edges[8] = edges[4];
     edges[4] = temp2;

     updateCornerOrientation(3,2);
     updateCornerOrientation(2,1);
     updateCornerOrientation(5,2);
     updateCornerOrientation(4,1);

     updateEdgeOrientation(2);
     updateEdgeOrientation(5);
     updateEdgeOrientation(8);
     updateEdgeOrientation(4);
}
void Cube::fPrime() {
     Corner temp = corners[2];
     corners[2] = corners[5];
     corners[5] = corners[4];
     corners[4] = corners[3];
     corners[3] = temp;

     Edge temp2 = edges[4];
     edges[4] = edges[8];
     edges[8] = edges[5];
     edges[5] = edges[2];
     edges[2] = temp2;

     updateCornerOrientation(3,2);
     updateCornerOrientation(2,1);
     updateCornerOrientation(5,2);
     updateCornerOrientation(4,1);

     updateEdgeOrientation(2);
     updateEdgeOrientation(5);
     updateEdgeOrientation(8);
     updateEdgeOrientation(4);
}
void Cube::f2() {
     swap(corners[3], corners[5]);
     swap(corners[2], corners[4]);

     swap(edges[2], edges[8]);
     swap(edges[4], edges[5]);
}
void Cube::b() {
     Corner temp = corners[1];
     corners[1] = corners[6];
     corners[6] = corners[7];
     corners[7] = corners[0];
     corners[0] = temp;

     Edge temp2 = edges[0];
     edges[0] = edges[7];
     edges[7] = edges[10];
     edges[10] = edges[6];
     edges[6] = temp2;

     updateCornerOrientation(0,1);
     updateCornerOrientation(1,2);
     updateCornerOrientation(6,1);
     updateCornerOrientation(7,2);

     updateEdgeOrientation(0);
     updateEdgeOrientation(7);
     updateEdgeOrientation(10);
     updateEdgeOrientation(6);
}
void Cube::bPrime() {
     Corner temp = corners[0];
     corners[0] = corners[7];
     corners[7] = corners[6];
     corners[6] = corners[1];
     corners[1] = temp;

     Edge temp2 = edges[6];
     edges[6] = edges[10];
     edges[10] = edges[7];
     edges[7] = edges[0];
     edges[0] = temp2;

     updateCornerOrientation(0,1);
     updateCornerOrientation(1,2);
     updateCornerOrientation(6,1);
     updateCornerOrientation(7,2);

     updateEdgeOrientation(0);
     updateEdgeOrientation(7);
     updateEdgeOrientation(10);
     updateEdgeOrientation(6);
}
void Cube::b2() {
     swap(corners[0], corners[6]);
     swap(corners[1], corners[7]);

     swap(edges[0], edges[10]);
     swap(edges[6], edges[7]);
}

Cube::Cube() {
     for (int i = 0; i < 12; ++i) {
          edges[i].index = i;
          edges[i].orientation = 0;
     }
     for (int i = 0; i < 8; ++i) {
          corners[i].index = i;
          corners[i].orientation = 0;
     }
}

Cube::Cube(const Cube &other) {
     for(int i = 0; i < 12; ++i) {
          edges[i] = other.edges[i];
     }
     for(int i = 0; i < 8; ++i) {
          corners[i] = other.corners[i];
     }
}

Cube &Cube::operator=(const Cube &other) {
     for(int i = 0; i < 12; ++i) {
          edges[i] = other.edges[i];
     }
     for(int i = 0; i < 8; ++i) {
          corners[i] = other.corners[i];
     }
     return *this;
}