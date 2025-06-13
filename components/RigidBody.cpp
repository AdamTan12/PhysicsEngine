#include "RigidBody.h"

RigidBody::RigidBody() {};
RigidBody::RigidBody(Object *object) : Component(object, object->transform) {
    angularVelocity = glm::vec3(0, 0, 0);
    centerOfMass = glm::vec3(0, 0, 0);
    inertiaTensor = glm::vec3(0, 0, 0);
    inertiaTensorRotation = glm::quat(0, 0, 0, 0);
    linearVelocity = glm::vec3(0, 0, 0);
    mass = 0;
    position = glm::vec3(0, 0, 0);
    rotation = glm::quat(0, 0, 0, 0);
    useGravity = true;
    worldCenterOfMass = glm::vec3(0, 0, 0);
}