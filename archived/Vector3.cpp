#include "Vector3.h"
using namespace std;


Vector3& Vector3::operator=(const Vector3& vector) {
    if (this != &vector) {
        this->x = vector.x;
        this->y = vector.y;
        this->z = vector.z;
    }  
    return *this; 
}
Vector3 Vector3::operator+(const Vector3& vector) const {
    return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}
Vector3 Vector3::operator-(const Vector3& vector) const {
    return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}
Vector3& Vector3::operator+=(const Vector3& vector) {
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    return *this;
}
Vector3& Vector3::operator-=(const Vector3& vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
    return *this;
}