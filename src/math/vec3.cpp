/*
 * vec3.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */
#include "vec3.h"

namespace spark{ namespace math{

    vec3::vec3(){
        x = y = z = 0.0f;
    }

    vec3::vec3(const float& _x, const float& _y, const float& _z){
            x = _x;
            y = _y;
            z = _z;
    }

    vec3& vec3::add(const vec3& otro){
        x += otro.x;
        y += otro.y;
        z += otro.z;
        return (* this);
    }

    vec3& vec3::subtract(const vec3& otro){
        x -= otro.x;
        y -= otro.y;
        z -= otro.z;
        return (* this);
    }

    vec3& vec3::multiplie(const vec3& otro){
        x *= otro.x;
        y *= otro.y;
        z += otro.z;
        return (* this);
    }

    vec3& vec3::divide(const vec3& otro){
        if(otro.x == 0 || otro.y == 0 || otro.z == 0) return (* this);
        x /= otro.x;
        y /= otro.y;
        z /= otro.z;
        return (* this);
    }

}}




