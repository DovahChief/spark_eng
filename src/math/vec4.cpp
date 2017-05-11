/*
 * vec4.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */


#include "vec4.h"

namespace spark{
    namespace math{

        vec4::vec4(const float& _x, const float& _y,const float& _z, const float& _w ){
                x = _x;
                y = _y;
                z = _z;
                w = _w;
        }

        vec4& vec4::add(const vec4& otro){
            x += otro.x;
            y += otro.y;
            z += otro.z;
            w += otro.w;
            return (* this);
        }

        vec4& vec4::subtract(const vec4& otro){
            x -= otro.x;
            y -= otro.y;
            z -= otro.z;
            w -= otro.w;
            return (* this);
        }

        vec4& vec4::multiplie(const vec4& otro){
            x *= otro.x;
            y *= otro.y;
            z *= otro.z;
            w *= otro.w;
            return (* this);
        }

        vec4& vec4::divide(const vec4& otro){
            if(otro.x == 0 || otro.y == 0 || otro.z == 0 || otro.w == 0) return (* this);
            x /= otro.x;
            y /= otro.y;
            z /= otro.z;
            w /= otro.w;
            return (* this);
        }
    }/* namespace math */
}/* namespace spark */


