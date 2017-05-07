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
/*
    usa coumn major ordering para el arreglo
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

			static mat4 orthographic(float izq, float der, float aba, float arr, float cerca, float lejos);
			static mat4 perspective(float fov, float aspect_ratio, float cerca, float lejos);

			static mat4 translation(const vec3& transl);
			static mat4 scale(const vec3& scale);
			static mat4 rotation(float angulo, const vec3& eje);

		};

	}/* namespace math */
}/* namespace spark */

