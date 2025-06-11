#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "Mesh.h"

using namespace std;

class Object;

struct MeshRenderer {
    GLuint VBO, VAO;
    Mesh *mesh= nullptr;
    Object *parent = nullptr;
    MeshRenderer();
    MeshRenderer(Object *parent);
    void Draw(GLuint shader);
    void setMesh(Mesh *mesh);
};
#endif