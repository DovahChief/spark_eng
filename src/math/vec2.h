/*
 * vec2.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#pragma once
#include <iostream>

/*
     Nota :los operadores de division ignoran siempre que se divida entre cero

*/

namespace spark{
    namespace math{

        struct vec2{
            float x , y;
            vec2();
            vec2(const float& _x, const float& _y);

            vec2& add(const vec2& otro);
            vec2& subtract(const vec2& otro);
            vec2& multiplie(const vec2& otro);
            vec2& divide(const vec2& otro);

            friend vec2 operator+(vec2 uno, const vec2& otro) {return (uno.add(otro));}
            friend vec2 operator-(vec2 uno, const vec2& otro) {return (uno.subtract(otro));}
            friend vec2 operator*(vec2 uno, const vec2& otro) {return (uno.multiplie(otro));}
            friend vec2 operator/(vec2 uno, const vec2& otro) {return (uno.divide(otro));}

            vec2& operator+=(const vec2& otro){return (add(otro));};
            vec2& operator-=(const vec2& otro){return (subtract(otro));};
            vec2& operator*=(const vec2& otro){return (multiplie(otro));};
            vec2& operator/=(const vec2& otro){return (divide(otro));};

            bool operator==(const vec2& otro){ return (x==otro.x && y == otro.y);}
            bool operator!=(const vec2& otro){ return (!(*this == otro));}

            friend std::ostream& operator<<(std::ostream& stream, const vec2& vec){
                stream << "vec2 : ("<<vec.x<<", "<<vec.y<<")";
                return (stream);
            }

        };

    } /* namespace math */
} /* namespace spark */

