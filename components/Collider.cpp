#include "Collider.h"

Collider::Collider() {

};
Collider::Collider(Object* gameObject) : Component(gameObject, gameObject->transform) {

}
bool Collider::collideWith(Collider* collider) {
    //check collision logic here
    return true;
}
