/*
 * mat4.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#include "mat4.h"

namespace spark {
    namespace math{

        inline float to_radians(float grados){ return ((float) (grados * (M_PI / 180.0f)));}
            //construuctor en cero
            mat4::mat4(){
                for (int i = 0; i < 4 * 4; i++ )
                        elements[i]= 0.0f;
            }
            //constructor de matriz diagonalizada
            mat4::mat4(float _diagonal){
                for (int i = 0; i < 4 * 4; i++ )
                    elements[i]= 0.0f;

                elements[0 + 0 * 4] = _diagonal;
                elements[1 + 1 * 4] = _diagonal;
                elements[2 + 2 * 4] = _diagonal;
                elements[3 + 3 * 4] = _diagonal;

            }
            //constrictor de identidad (diagonal en 1)
            mat4 mat4::identity(){ return (mat4(1.0f)); }
            //algoritmo de multiplicacion de matrices
            mat4& mat4::multiply(const mat4& otro){
                float data[16];
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        float sum { 0.0f };
                        for(int k = 0; k < 4; k++){
                            //element [ fila + columna * 4 ]
                            sum += elements[j + k * 4] * otro.elements[k + i * 4];
                        }
                    data[j + i * 4] = sum;
                    }
                }
                memcpy(elements, data, 16* sizeof(float));
                return (*this);
            }
            //sobrecarga de operadores
            mat4 operator*(mat4 izq, const mat4& right) { return (izq.multiply(right)); }
            mat4& mat4::operator*=(const mat4& right)         { return (multiply(right)); }
            //matriz ortografica
            mat4 mat4::orthographic(float izq, float der, float aba, float arr,float cerca, float lejos)
            {
                mat4 result(1.0);

                result.elements[0 + 0 * 4] = 2.0f/(der - izq);
                result.elements[1 + 1 * 4] = 2.0f/(arr - aba);
                result.elements[2 + 2 * 4] = 2.0f/(cerca - lejos);

                result.elements[0 + 3 * 4] = (izq + der) / (izq - der);
                result.elements[1 + 3 * 4] = (aba + arr) / (aba - arr);
                result.elements[2 + 3 * 4] = (lejos + cerca) / (lejos - cerca);

                return (result);
            }
            //matriz de perspectiva
            mat4 mat4::perspective(float fov, float aspect_ratio, float cerca, float lejos)
            {
                mat4 result(1.0);
                float q { 1.0f / tan(to_radians(0.5f * fov)) };
                float a { q / aspect_ratio };
                float b { (cerca + lejos) / (cerca - lejos) };
                float c { (2.0f * cerca * lejos) / (cerca - lejos) };

                result.elements[0 + 0 * 4] = a;
                result.elements[1 + 1 * 4] = q;
                result.elements[2 + 2 * 4] = b;
                result.elements[3 + 2 * 4] = -1.0f;
                result.elements[3 + 3 * 4] = c;

                return (result);
            }

            //matriz de traslacion
            mat4 mat4::translation(const vec3& transl) {
                mat4 result(1.0f);

                result.elements[0 + 3 * 4] = transl.x;
                result.elements[1 + 3 * 4] = transl.y;
                result.elements[2 + 3 * 4] = transl.z;

                return (result);
            }
            //matriz de escala
            mat4 mat4::scale(const vec3& scale){
                mat4 result(1.0f);

                result.elements[0 + 0 * 4] = scale.x;
                result.elements[1 + 1 * 4] = scale.y;
                result.elements[2 + 2 * 4] = scale.z;

                return (result);
            }
            //matriz de rotacion
            mat4 mat4::rotation(float angulo, const vec3& eje){
                mat4 result(1.0f);

                float r = to_radians(angulo);
                float c = cos(r);
                float s = sin(r);
                float omc { 1.0f - c };

                float x = eje.x;
                float y = eje.y;
                float z = eje.z;

                result.elements[0 + 0 * 4] = x * x * omc + c;
                result.elements[0 + 1 * 4] = y * x * omc + z * s;
                result.elements[0 + 2 * 4] = x * z * omc - y * s;

                result.elements[1 + 0 * 4] = x * y * omc - z * s;
                result.elements[1 + 1 * 4] = y * y * omc + c;
                result.elements[1 + 2 * 4] = y * z * omc + x * s;

                result.elements[2 + 0 * 4] = x * z * omc + y * s;
                result.elements[2 + 1 * 4] = y * z * omc - x * s;
                result.elements[2 + 2 * 4] = z * z * omc + c;

                return (result);

            }

    } /* namespace math */

} /* namespace spark */




