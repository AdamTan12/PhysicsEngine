#ifndef COMPONENT_H
#define COMPONENT_H


class Object;    //forward declaration
class Transform; //forward declaration
/**
 * @brief Component is the base for all components.
 * 
 * An instance of Component should never be made, only children of Component.
 */
struct Component {
    /**
     * @brief Pointer to the gameobject that this Component is attached to.
     */
    Object *gameObject;
    /**
     * @brief Pointer to the transform attached to the gameobject that this Component is attached to.
     */
    Transform *transform;
    /**
     * default constructor
     */
    Component();
    /**
     * @brief Constructs a new Component.
     * 
     * @param gameObject Object that this Component is attached to.
     * @param transform Transform of the Object that this Component is attached to.
     */
    Component(Object* gameObject, Transform* transform);
    virtual ~Component() =0;
};
#endif