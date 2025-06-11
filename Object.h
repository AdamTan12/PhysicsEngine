#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <vector>
#include <memory>
#include "components/Transform.h"
#include "components/Component.h"
using namespace std;


struct Object {
    string name;
    Transform *transform;
    vector<unique_ptr<Component>> components;
    Object();

    template<typename T>
    T* AddComponent() {
        auto up = std::make_unique<T>(this);  // always calls T(Object*)
        T* raw = up.get();
        components.emplace_back(std::move(up));
        return raw;
    };
};
#endif