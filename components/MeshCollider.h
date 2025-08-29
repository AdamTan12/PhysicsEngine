#ifndef MESHCOLLIDER_H
#define MESHCOLLIDER_H
#include "Collider.h"
#include "../Mesh.h"

struct MeshCollider : public Collider {
       
    MeshCollider();
    MeshCollider(Object* gameObject);
    ~MeshCollider() = default;

    bool setMesh(Mesh* mesh);
    bool collideWith(Collider* other) override;
};

#endif
