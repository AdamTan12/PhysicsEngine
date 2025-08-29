#include "Transform.h"

Transform::Transform() {
    position = glm::vec3(0, 0, 0);
    rotation = glm::quat();
    scale = glm::vec3(1, 1, 1);
}
Transform::Transform(Object* gameObject) : Component(gameObject, this) {
    position = glm::vec3(0, 0, 0);
    rotation = glm::quat();
    scale = glm::vec3(1, 1, 1);
}
glm::mat4 Transform::getWorldMatrix() {
    glm::mat4 transformMatrix = glm::mat4_cast(rotation)
                            * glm::translate(glm::mat4(1.0f), position)
                            * glm::scale(glm::mat4(1.0f), scale);
    Object* parent = gameObject->parent;
    while (parent != nullptr) {
        Transform* parentTransform = parent->transform;
        glm::mat4 parentTransformMatrix = glm::mat4_cast(parentTransform->rotation)
                                    *   glm::translate(glm::mat4(1.0f), parentTransform->position)
                                    *   glm::scale(glm::mat4(1.0f), scale);
        transformMatrix *= parentTransformMatrix;
        parent = parent->parent;
    }
    return transformMatrix;
}