#ifndef COLLIDER_H
#define COLLIDER_H
#include "Component.h"
#include "../Object.h"
#include "../Mesh.h"

struct Collider : public Component {
    Mesh* mesh = nullptr;
    vector<glm::vec3> edges;

    Collider();
    Collider(Object* gameObject);
    virtual bool collideWith(Collider* other) = 0; //make Collider abstract
};

#endif