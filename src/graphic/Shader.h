/*
 * Shader2.h
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#pragma once


#include "../utils/file_utils.h"
#include "../math/mat4.h"
#include "../math/vec2.h"

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <iostream>

namespace spark{
	namespace graphics{

		class Shader
		{
			public:
				Shader(const std::string& _file_v, const std::string& _file_f);
				virtual ~Shader();
				void enable();
				void disable();


				void setUniform1f(const GLchar* _nombre, float val );
				void setUniform1i(const GLchar* _nombre, int val );
				void setUniform2f(const GLchar* _nombre, const math::vec2& _vector );
				void setUniform3f(const GLchar* _nombre, const math::vec3& _vector );
				void setUniform4f(const GLchar* _nombre, const math::vec4& _vector );

				void setUniformMAT4(const GLchar* _nombre, const math::mat4 _mat);

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

				GLint get_UniformLocation(const GLchar* _nombre);

		};
	}/* namespace graphics */
}/* namespace spark */

