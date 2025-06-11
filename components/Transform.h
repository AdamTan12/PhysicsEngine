#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp> 
#include "Component.h"
using namespace std;

struct Transform : public Component{
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;  
    Transform();
    Transform(Object* gameObject);
};
#endif