#ifndef MESH_H
#define MESH_H
#include <vector>
#include "glm/glm.hpp"

using namespace std;
struct Mesh {
    vector<glm::vec3> vertices;
    Mesh();
};
#endif