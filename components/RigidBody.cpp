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
void RigidBody::AddForce(glm::vec3 force) {
    glm::vec3 acceleration = force/mass;
}
void RigidBody::AddForceAtPosition(glm::vec3 force, glm::vec3 position) {

}
void RigidBody::AddTorque(glm::vec3 force) {

}
void RigidBody::PublishTransform() {

}
void RigidBody::ResetCenterOfMass() {

}
void RigidBody::ResetInertiaTensor() {

}
void RigidBody::GetAccumulatedForce() {

}
void RigidBody::GetAccumulatedTorque() {

}