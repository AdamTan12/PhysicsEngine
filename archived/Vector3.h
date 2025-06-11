#ifndef VECTOR3_H
#define VECTOR3_H
using namespace std;

struct Vector3 {
    float x;
    float y;
    float z;
    Vector3();
    Vector3(float x, float y, float z): x{x}, y{y}, z{z} {};
    //~Vector3();
    Vector3& operator=(const Vector3& vector);
    
    Vector3 operator+(const Vector3& vector) const;
    Vector3 operator-(const Vector3& vector) const;

    Vector3& operator+=(const Vector3& vector);
    Vector3& operator-=(const Vector3& vector);
};
#endif