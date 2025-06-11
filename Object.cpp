#include "Object.h"
#include "Mesh.h"

Object::Object() {
    name = "gameObject";
    transform = new Transform();
    meshRenderer = new MeshRenderer(this);
}