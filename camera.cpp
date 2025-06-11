#include "camera.h"
#include "glm/gtc/matrix_transform.hpp"

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