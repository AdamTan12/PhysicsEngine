#ifndef MESH_H
#define MESH_H
#include <vector>
#include "glm/glm.hpp"

using namespace std;
/**
 * @brief Represents the triangle created by three vectors in world space.
 * 
 * Similar to a plane.
 */
struct Face {
    /**
     * @brief i1, i2, and i3 represent the different indices of the vectors used to create this face.
     */
    glm::vec3 i1, i2, i3;
    /**
     * @brief
     */
    glm::vec3 baseNormal;
    /**
     * @brief
     */
    glm::vec3 norm;
};
/**
 * @brief 3d structure to represent a model.
 * 
 * made of multiple triangles
 */
struct Mesh {
    /**
     * @brief Vector(data structure) of vertices that are used in the mesh.
     * 
     */
    vector<glm::vec3> vertices;
    /**
     * @brief Vector(data structure) of indices that correlate to which vertices should be grouped to create the mesh.
     */
    vector<unsigned int> indices;
    /**
     * @brief Vector(data structure) of faces that make up the mesh.
     */
    vector<Face> faces;
    /**
     * @brief default constructor
     */
    Mesh();
};
#endif