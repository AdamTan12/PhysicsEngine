#ifndef COLLIDER_H
#define COLLIDER_H
#include "Component.h"
#include "Object.h"
#include "Mesh.h"

struct Collider : public Component {
    Collider();
    Collider(Object* gameObject);
    bool collideWith(Face& face);
};

#endif