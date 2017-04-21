/*
 * Shader2.h
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_SHADER2_H_
#define GRAPHIC_SHADER2_H_


#include "transform.h"
#include "camara.h"
#include "../utils/file_utils.h"
#include <string>
#include <GL/glew.h>
namespace spark{ namespace graphics{
class Shader2
{
    public:
        Shader2( const std::string& file_name);
        virtual ~Shader2();
        void Bind();
        void Update(const transform& tr, const camara& cam);
        void Update(const transform& tr);
    protected:

    private:
        static const unsigned int NUM_SHADERS = 2;

        //Shader2(const Shader2& other){}
        //void operator=(const shader& other) {}

        enum {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint m_programa;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};
}}



#endif /* GRAPHIC_SHADER2_H_ */
