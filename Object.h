#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "components/Transform.h"
#include "components/Component.h"
using namespace std;

/**
 * @brief Represents a gameobject in the scene.
 * 
 * This struct serves as the base for all entities in the world.
 * Each struct has a name, transform, and a set of attached components.
 */
struct Object {
    /**
     * @brief The name of this object.
     */
    string name;
    /**
     * @brief Pointer to the transform attached to this object.
     * 
     * This transform represents the object's position, rotation, and scale in world space.
     */
    Transform *transform;
    /**
     * @brief Vector of all the components attached to this object.
     * 
     * Components define the object's behaviour, such as rendering, physics, or scripting.
     */
    vector<Component*> components;

    /**
     * @brief Default constructor.
     */
    Object();

    /**
     * @brief Adds respective component of type T to this object's components and returns a pointer to the added component.
     * 
     * Type of T must be derived from Component.
     * Can't add a component of type T already attached to this object.
     * 
     * @tparam T The component type to add.
     * @return Pointer to added component of type T (T*).
     * 
     */
    template<typename T>
    T* AddComponent() {
        static_assert(std::is_base_of<Component, T>::value, "AddComponent<T>: T must inherit from Component");
        T* component = new T(this);
        components.push_back(component);
        return component;
    };
    /**
     * @brief Get the component of type T that is attached to this object.
     * 
     * Type of T must be derived from Component.
     * 
     * @tparam T Type of component to find.
     * @return Pointer to found component of type T (T*).
     */
    template<typename T>
    T* GetComponent() {
        static_assert(std::is_base_of<Component, T>::value, "AddComponent<T>: T must inherit from Component");
        for (int i = 0; i < components.size(); i ++) {
            if (dynamic_cast<T*>(components[i]) != nullptr)
                return dynamic_cast<T*>(components[i]);
        }
        return nullptr;
    }
};
#endif