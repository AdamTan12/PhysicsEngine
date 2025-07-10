#ifndef MESHCOLLIDER_H
#define MESHCOLLIDER_H
#include "Collider.h"
#include "../Mesh.h"

struct MeshCollider : public Collider {
    Mesh* mesh = nullptr;

    MeshCollider();
    MeshCollider(Object* gameObject);
    ~MeshCollider();

};

#endif
