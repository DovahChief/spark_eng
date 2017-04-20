/*
 * vec4.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#ifndef MATH_VEC4_H_
#define MATH_VEC4_H_


#include <iostream>

/*
     Nota :los operadores de division ignoran siempre que se divida entre cero

*/

namespace spark{ namespace math{

    struct vec4{
        float x , y, z, w;

        vec4() = default;
        vec4(const float& _x, const float& _y,const float& _z, const float& _w );

        vec4& add(const vec4& otro);
        vec4& subtract(const vec4& otro);
        vec4& multiplie(const vec4& otro);
        vec4& divide(const vec4& otro);

        friend vec4 operator+(vec4 uno, const vec4& otro) {return (uno.add(otro));}
        friend vec4 operator-(vec4 uno, const vec4& otro) {return (uno.subtract(otro));}
        friend vec4 operator*(vec4 uno, const vec4& otro) {return (uno.multiplie(otro));}
        friend vec4 operator/(vec4 uno, const vec4& otro) {return (uno.divide(otro));}

        vec4& operator+=(const vec4& otro){return (add(otro));};
        vec4& operator-=(const vec4& otro){return (subtract(otro));};
        vec4& operator*=(const vec4& otro){return (multiplie(otro));};
        vec4& operator/=(const vec4& otro){return (divide(otro));};

        bool operator==(const vec4& otro){ return (x==otro.x && y == otro.y && z == otro.z && w == otro.w);}
        bool operator!=(const vec4& otro){ return (!(*this == otro));}

        friend std::ostream& operator<<(std::ostream& stream, const vec4& vec){
            stream << "vec4 : ("<<vec.x<<", "<<vec.y<<", "<<vec.z<<", "<<vec.w<<")";
            return (stream);
        }

    };

} }



#endif /* MATH_VEC4_H_ */
