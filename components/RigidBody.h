#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "glm/glm.hpp"
#include "../Object.h"
#include <glm/gtc/quaternion.hpp> 

struct RigidBody : public Component {
    glm::vec3 angularVelocity;
    glm::vec3 centerOfMass;
    glm::vec3 inertiaTensor;
    glm::quat inertiaTensorRotation;
    glm::vec3 linearVelocity;
    float mass;
    glm::vec3 position;
    glm::quat rotation;
    bool useGravity;
    glm::vec3 worldCenterOfMass;

    RigidBody();
    RigidBody(Object *object);

    void AddForce(glm::vec3 force);
    void AddForceAtPosition(glm::vec3 force, glm::vec3 position);
    void AddTorque(glm::vec3 force);
    void PublishTransform();
    void ResetCenterOfMass();
    void ResetInertiaTensor();
    void GetAccumulatedForce();
    void GetAccumulatedTorque();
};

#endif