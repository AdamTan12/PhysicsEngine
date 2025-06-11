#include <utility>
#include "Object.h"
#include "Mesh.h"

Object::Object() {
    name = "gameObject";
    transform = new Transform();
}

// implement template functions in header files, kinda cringe
// template<typename T>
// T* Object::AddComponent() {
//     auto up = std::make_unique<T>(this);  // always calls T(Object*)
//     T* raw = up.get();
//     components.emplace_back(std::move(up));
//     return raw;
// }
