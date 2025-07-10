#include "Collider.h"

Collider::Collider() {

};
Collider::Collider(Object* gameObject) : Component(gameObject, gameObject->transform) {

}
bool Collider::collideWith(Face& face) {
    
}
