#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  // for glm::translate, glm::scale, glm::rotate, glm::perspective…
#include <glm/gtc/type_ptr.hpp>  // for glm::value_ptr

#include "components/MeshRenderer.h"
#include "Box.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLuint loadShader(const char* vertexPath, const char* fragmentPath) {
    std::ifstream vFile(vertexPath), fFile(fragmentPath);
    std::stringstream vStream, fStream;
    vStream << vFile.rdbuf(); fStream << fFile.rdbuf();
    std::string vCode = vStream.str(), fCode = fStream.str();
    const char* vSrc = vCode.c_str(), *fSrc = fCode.c_str();

    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vSrc, nullptr);
    glCompileShader(vertex);

    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fSrc, nullptr);
    glCompileShader(fragment);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return program;
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Line", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Camera gCamera = Camera();
    glm::mat4 view = gCamera.getViewMatrix();

    Box box = Box();
    box.AddComponent<MeshRenderer>();
    MeshRenderer* mr = box.GetComponent<MeshRenderer>();
    mr->setMesh(new Mesh());
    box.transform->position.z = -2.0f;
    float x = 0.0f;
    float y = 0.0f;

    // Box box2 = Box();
    // box2.transform->position.y = 1.0f;
    // box2.transform->position.x = 1.0f;
    // box2.transform->scale = glm::vec3(1.0f, 1.2f, 1.0f);
    // box2.meshRenderer->setMesh(new Mesh());
    

    GLuint shaderProgram = loadShader("shaders/vertex.glsl", "shaders/fragment.glsl");
    glUseProgram(shaderProgram);
    GLuint colorLoc = glGetUniformLocation(shaderProgram, "uColor");
    // u_view
    GLint  uView = glGetUniformLocation(shaderProgram, "u_view");
    glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(view));
    // u_perspective
    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), 
                                                800.0f/600.0f,
                                                0.1f, 50.0f);
    GLint per = glGetUniformLocation(shaderProgram, "u_perspective");
    glUniformMatrix4fv(per, 1, GL_FALSE, (glm::value_ptr(perspective)));
    while (!glfwWindowShouldClose(window)) {
        glUseProgram(shaderProgram);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_POLYGON_OFFSET_FILL);
        glPolygonOffset(1.0f, 1.0f);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glUniform3f(colorLoc, 0.0, 0.0, 0.0);
        mr->Draw(shaderProgram);
        //box2.meshRenderer->Draw(shaderProgram);
        glDisable(GL_POLYGON_OFFSET_FILL);
        
        glLineWidth(3.0f);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glUniform3f(colorLoc, 1.0, 1.0, 1.0);
        mr->Draw(shaderProgram);
        //box2.meshRenderer->Draw(shaderProgram);
        x += 0.01f;
        y += 0.01f;
        glm::vec3 eulerDeg(x, y, 0.0f);
        glm::vec3 eulerRad = glm::radians(eulerDeg);
        glm::quat q = glm::quat(eulerRad);

        box.transform->rotation = q;

        //box2.transform->rotation = q;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}
