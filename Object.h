#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "Transform.h"
#include "MeshRenderer.h"
using namespace std;


struct Object {
    string name;
    Transform *transform;
    MeshRenderer *meshRenderer;
    Object();
};
#endif