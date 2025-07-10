#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp> 
#include "Component.h"
using namespace std;
/**
 * @brief Inherits from Component.
 * 
 * every Object must contain a transform.
 */
struct Transform : public Component{
    /**
     * @brief Position (xyz) of parent Object represented by vec3
     */
    glm::vec3 position;
    /**
     * @brief Rotation of parent Object as a quat
     */
    glm::quat rotation;
    /**
     * @brief Rotation (xyz) of parent Object as a vec3
     */
    glm::vec3 scale;  
    /**
     * default constructor
     */
    Transform();
    /**
     * @brief Constructs a Transform Component with all fields as default values.
     * 
     * position initialized with zero vector.
     * 
     * rotation initialized with identity quaternion.
     * 
     * scale initialized with vector consisting of all ones (1, 1, 1).
     * 
     * @param gameObject Object that this Transform is attached to.
     */
    Transform(Object* gameObject);
};
#endif