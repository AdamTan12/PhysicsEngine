#ifndef QUAT_H
#define QUAT_H
#include <cmath>
#include "Vector3.h"

using namespace std;

struct Quat {
    float x, y, z, w = 0;
    Quat();
    void rotate(float x, float y, float z);
};

#endif