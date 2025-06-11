#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp> 
using namespace std;

struct Transform {
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;  
    Transform();
};
#endif