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