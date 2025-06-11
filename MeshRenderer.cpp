#include "MeshRenderer.h"
#include "Object.h"   
MeshRenderer::MeshRenderer() {}
MeshRenderer::MeshRenderer(Object *p) {
    parent = p;
}
void MeshRenderer::setMesh(Mesh *mesh) {
    this->mesh = mesh;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(glm::vec3), mesh->vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);
}
void MeshRenderer::Draw(GLuint shaderProgram) {
    if (mesh != nullptr) {
        // u_model
        glm::mat4 model = glm::mat4_cast(parent->transform->rotation);
        model = glm::translate(model, parent->transform->position);
        model = glm::scale(model, parent->transform->scale);

        // u_perspective
        glm::mat4 perspective = glm::perspective(glm::radians(45.0f), 
                                                    800.0f/600.0f,
                                                    0.1f, 10.0f);
        GLint per = glGetUniformLocation(shaderProgram, "u_perspective");
        GLint loc = glGetUniformLocation(shaderProgram, "u_model");
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(per, 1, GL_FALSE, (glm::value_ptr(perspective)));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, mesh->vertices.size());

    }
}