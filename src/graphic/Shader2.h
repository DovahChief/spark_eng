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
#include "../math/mat4.h"
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>

namespace spark{ namespace graphics{

class shader
{
    public:
        shader(const std::string& _file_v, const std::string& _file_f);
        virtual ~shader();
        void enable();
        void disable();
        void update();
        void update(const transform& _tr, const camara& _cam);
        void update(const transform& _tr);
        GLuint get_id(){return (m_shader_id);}

    private:
        static const unsigned int NUM_SHADERS = 2;
        enum {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint m_shader_id;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};
}}
#endif /* GRAPHIC_SHADER2_H_ */
