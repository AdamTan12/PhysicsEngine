#include "MeshCollider.h"

MeshCollider::MeshCollider() {}

MeshCollider::MeshCollider(Object* gameObject) : Collider(gameObject) {

}
bool MeshCollider::setMesh(Mesh* mesh) {
    this->mesh = mesh;
    return true;
}
bool MeshCollider::collideWith(Collider* other) {
    //grab edges and face normals of other collider and check collisions with our own
    vector<glm::vec3> axi;
    //cout << mesh->edges.size() << endl;

    // glm::mat4 modelA = glm::mat4_cast(transform->rotation)
    //             * glm::translate(glm::mat4(1.0f), transform->position)
    //             * glm::scale(glm::mat4(1.0f), transform->scale);

    // glm::mat4 modelB = glm::mat4_cast(other->transform->rotation)   // quaternion
    //             * glm::translate(glm::mat4(1.0f), other->transform->position)
    //             * glm::scale(glm::mat4(1.0f), other->transform->scale);
    glm::mat4 modelA = transform->getWorldMatrix();
    glm::mat4 modelB = other->transform->getWorldMatrix();

    for (int i = 0; i < mesh->edges.size(); i ++) {
        for (int j = 0; j < other->mesh->edges.size(); j ++) {
            glm::vec3 worldEdgePrimary = glm::mat3(modelA) * mesh->edges[i];
            glm::vec3 worldEdgeSecondary = glm::mat3(modelB) * other->mesh->edges[j];
            glm::vec3 axis = glm::cross(worldEdgePrimary, worldEdgeSecondary);
            if (glm::length(axis) > 1e-6f)
                axi.push_back(glm::normalize(axis));
        }
    }
            
    for (int i = 0; i < mesh->faces.size(); i ++) {
        axi.push_back(glm::normalize(glm::mat3(glm::transpose(glm::inverse(modelA))) * mesh->faces[i].norm));
    }
    for (int i = 0; i < other->mesh->faces.size(); i ++) {
        axi.push_back(glm::normalize(glm::mat3(glm::transpose(glm::inverse(modelB))) * other->mesh->faces[i].norm));
    }
    int overlap = true;
    for (int a = 0; a < axi.size(); a ++) {

        glm::vec3 axis = axi[a];
        //to get projection, do dot product of vertex on
        //need to apply transform onto vertex

        

        float minA = glm::dot(glm::vec3(modelA * glm::vec4(mesh->vertices[0], 1.0f)), axis);
        float maxA = minA;
        for (int i = 0; i < mesh->vertices.size(); i ++) {
            glm::vec3 vertex = mesh->vertices[i];
            glm::vec3 worldVertex = glm::vec3(modelA * glm::vec4(vertex, 1.0f));
            float p = glm::dot(worldVertex, axis);
            if (p > maxA)
                maxA = p;
            if (p < minA)
                minA = p;
        }
                
        float minB = glm::dot(glm::vec3(modelB * glm::vec4(other->mesh->vertices[0], 1.0f)), axis);
        float maxB = minB;
        for (int i = 0; i < other->mesh->vertices.size(); i ++) {
            glm::vec3 vertex = other->mesh->vertices[i];
            glm::vec3 worldVertex = glm::vec3(modelB * glm::vec4(vertex, 1.0f));
            float p = glm::dot(worldVertex, axis);
            if (p > maxB)
                maxB = p;
            if (p < minB)
                minB = p;
        }

        if (maxA < minB || maxB < minA) {
            return false;
        }
    }
    return true;
}

