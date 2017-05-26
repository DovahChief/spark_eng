/*
 * mat4.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#pragma once
#include "vec3.h"
#include "vec4.h"
#include <math.h>
#include <cstring>
/*
    usa column major ordering para el arreglo
    se accesa con:
    element [ fila + columna * <ancho> ]

    en este caso seria <ancho> = 4

    element [ fila + columna * 4 ]
*/



namespace spark{
	namespace math{

		struct mat4{

			union
			{
				float elements[4 * 4];
				vec4 column[4];
			};

			mat4();
			mat4(float _diagonal);

			static mat4 identity();

			mat4& multiply(const mat4& otro);
			friend mat4 operator*(mat4 izq, const mat4& right);
			mat4& operator*=(const mat4& right);

			vec3 multiply(const vec3& otro) const ;
			vec4 multiply(const vec4& otro) const ;

			friend vec4 operator*(const mat4& izq, const vec4& right);
			friend vec3 operator*(const mat4& izq, const vec3& right);

			static mat4 orthographic(float izq, float der, float aba, float arr, float cerca, float lejos);
			static mat4 perspective(float fov, float aspect_ratio, float cerca, float lejos);

			static mat4 translation(const vec3& transl);
			static mat4 scale(const vec3& scale);
			static mat4 rotation(float angulo, const vec3& eje);

			friend std::ostream& operator<<(std::ostream& stream, const mat4& mat){
                stream << "mat4 : \n |"<<mat.column[0].x<<", "<<mat.column[1].x<<", "<<mat.column[2].x<<", "<<mat.column[3].x<<"|";
                stream << " |"<<mat.column[0].y<<", "<<mat.column[1].y<<", "<<mat.column[2].y<<", "<<mat.column[3].y<<"|";
				stream << " |"<<mat.column[0].z<<", "<<mat.column[1].z<<", "<<mat.column[2].z<<", "<<mat.column[3].z<<"|";
				stream << " |"<<mat.column[0].w<<", "<<mat.column[1].w<<", "<<mat.column[2].w<<", "<<mat.column[3].w<<"|";
				return (stream);
            }

		};
	}/* namespace math */
}/* namespace spark */

