#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "../Mesh.h"
#include "Component.h"

using namespace std;

class Object;

struct MeshRenderer : public Component {
    GLuint VBO, VAO;
    Mesh *mesh = nullptr;
    MeshRenderer();
    MeshRenderer(Object* gameObject);
    void Draw(GLuint shader);
    void setMesh(Mesh *mesh);
};
#endif