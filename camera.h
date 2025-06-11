#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"

struct Camera {
    glm::vec3 mEye;
    glm::vec3 mViewDirection;
    glm::vec3 mUpVector;
    
    glm::mat4 mViewMatrix;

    glm::mat4 getViewMatrix() const;
    void MoveFoward();
    void MoveBackward();
    void MoveLeft();
    void MoveRight();
};
#endif