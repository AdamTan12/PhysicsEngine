#ifndef VERTEX_H
#define VERTEX_H
#include "Vector3.h"
using namespace std;
struct Vertex {
    Vector3 position;
    //Vector3 normal;
    Vertex(Vector3 position);
};
#endif