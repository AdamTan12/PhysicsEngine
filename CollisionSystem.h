#ifndef COLLISION_SYSTEM
#define COLLISION_SYSTEM

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
//#include "components/Collider.h" use forward declaration
using namespace std;

class Collider;

struct CollisionSystem {
    //create instance in cpp file
    static vector<Collider*> colliders;
    static void collisionLoop();
};

#endif