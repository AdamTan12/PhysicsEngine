#include "camera.h"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera() {
    // assume we are at origin
    mEye = glm::vec3(0.0f, 0.0f, 10.0f);
    // we are looking into the '-z' direction
    mViewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    // assume we are on a perfect plane
    mUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
}
glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(mEye, mViewDirection, mUpVector);
}
void Camera::MoveFoward() {

}
void Camera::MoveBackward() {

}
void Camera::MoveLeft() {

}
void Camera::MoveRight() {

}