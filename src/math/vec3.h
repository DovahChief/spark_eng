/*
 * vec3.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#pragma once

#include <iostream>

/*
     Nota :los operadores de division ignoran siempre que se divida entre cero

*/

namespace spark{ namespace math{

    struct vec3{
        float x , y, z;
        vec3();
        vec3(const float& _x, const float& _y, const float& _z);

        vec3& add(const vec3& otro);
        vec3& subtract(const vec3& otro);
        vec3& multiplie(const vec3& otro);
        vec3& divide(const vec3& otro);

        friend vec3 operator-(vec3 uno, const vec3& otro) {return (uno.subtract(otro));}
        friend vec3 operator*(vec3 uno, const vec3& otro) {return (uno.multiplie(otro));}
        friend vec3 operator+(vec3 uno, const vec3& otro) {return (uno.add(otro));}
        friend vec3 operator/(vec3 uno, const vec3& otro) {return (uno.divide(otro));}

        vec3& operator+=(const vec3& otro){return (add(otro));};
        vec3& operator-=(const vec3& otro){return (subtract(otro));};
        vec3& operator*=(const vec3& otro){return (multiplie(otro));};
        vec3& operator/=(const vec3& otro){return (divide(otro));};

        bool operator==(const vec3& otro){ return (x==otro.x && y == otro.y && z == otro.z);}
        bool operator!=(const vec3& otro){ return (!(*this == otro));}

        friend std::ostream& operator<<(std::ostream& stream, const vec3& vec){
            stream << "vec3 : ("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")";
            return (stream);
        }

    };

} }

