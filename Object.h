#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "components/Transform.h"
#include "components/Component.h"
using namespace std;


struct Object {
    string name;
    Transform *transform;
    vector<Component*> components;
    Object();

    template<typename T>
    T* AddComponent() {
        static_assert(std::is_base_of<Component, T>::value, "AddComponent<T>: T must inherit from Component");
        T* component = new T(this);
        components.push_back(component);
        return component;
    };
    template<typename T>
    T* GetComponent() {
        static_assert(std::is_base_of<Component, T>::value, "AddComponent<T>: T must inherit from Component");
        for (int i = 0; i < components.size(); i ++) {
            if (dynamic_cast<T*>(components[i]) != nullptr)
                return dynamic_cast<T*>(components[i]);
        }
        return nullptr;
    }
};
#endif