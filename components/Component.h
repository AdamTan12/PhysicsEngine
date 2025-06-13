#ifndef COMPONENT_H
#define COMPONENT_H

class Object;
class Transform;
struct Component {
    Object *gameObject;
    Transform *transform;
    Component();
    Component(Object* gameObject, Transform* t);
    virtual ~Component();
};
#endif