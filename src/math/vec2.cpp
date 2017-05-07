/*
 * vec2.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */
#include "vec2.h"

namespace spark{
    namespace math{

        vec2::vec2(){
            x = y = 0.0f;
        }

        vec2::vec2(const float& _x, const float& _y){
                x = _x;
                y = _y;
        }

        vec2& vec2::add(const vec2& otro){
            x += otro.x;
            y += otro.y;
            return (* this);
        }

        vec2& vec2::subtract(const vec2& otro){
            x -= otro.x;
            y -= otro.y;
            return (* this);
        }

        vec2& vec2::multiplie(const vec2& otro){
            x *= otro.x;
            y *= otro.y;
            return (* this);
        }

        vec2& vec2::divide(const vec2& otro){
            if(otro.x == 0 || otro.y == 0) return (* this);
            x /= otro.x;
            y /= otro.y;
            return (* this);
        }

    } /* namespace math */
}/* namespace spark */




