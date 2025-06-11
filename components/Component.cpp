#include "Component.h"
Component::Component() {
    
}
Component::Component(Object* o, Transform* t) {
    gameObject = o;
    transform = t;
}