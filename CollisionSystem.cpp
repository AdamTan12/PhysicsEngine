#include "CollisionSystem.h"
#include "components/Collider.h"


vector<Collider*> CollisionSystem::colliders;

void CollisionSystem::collisionLoop() {
    //cout << colliders.size() << endl;
    for (int i = 0; i < colliders.size(); i ++) {
        Collider* c1 = colliders[i];
        for (int j = 0; j < colliders.size(); j ++) {
            Collider* c2 = colliders[j];
            if (c1 == c2) {
                continue;
            }
            if (c1->collideWith(c2)) {
                //implement collision logic here, ie. physics stuff
                cout << "colliding" << endl;
            }
            else
                cout << "..." << endl;
        }
    }
}