/*
 * Shader2.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "shader.h"


namespace spark{
	namespace graphics{

		static void check_shader_err(GLuint shader, GLuint flag, bool esPrograma, const std::string& msj_err);
		static GLuint load( const std::string& text, GLenum shader_type);

		shader::shader(const std::string& _file_v, const std::string& _file_f){
			//ctor
			m_shader_id = glCreateProgram();
			m_shaders[0] = load(F::lee_arch(_file_v), GL_VERTEX_SHADER);
			m_shaders[1] = load(F::lee_arch(_file_f), GL_FRAGMENT_SHADER);

			for(unsigned int i=0; i<NUM_SHADERS; i++)
				glAttachShader(m_shader_id, m_shaders[i]);

			glBindAttribLocation(m_shader_id, 0, "position");
			glBindAttribLocation(m_shader_id, 1, "color");
			//todo: agregar 1 para normal, 2 para terxture_coord y 3 para texture_id

			glLinkProgram(m_shader_id);
			check_shader_err(m_shader_id, GL_LINK_STATUS, true, "Error en ligado de programa");

			glValidateProgram(m_shader_id);
			check_shader_err(m_shader_id, GL_VALIDATE_STATUS, true, "Error en validando programa");

			m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_shader_id, "transform");

		}
		shader::~shader(){
			//dtor
			for(unsigned int i=0; i<NUM_SHADERS; i++){
				glDetachShader(m_shader_id, m_shaders[i]);
				glDeleteShader(m_shaders[i]);
			}
			glDeleteProgram(m_shader_id);
		}

		GLint shader::get_UniformLocation(const GLchar* _nombre){
			return (glGetUniformLocation(m_shader_id, _nombre));
		}

		void shader::enable(){
			glUseProgram(m_shader_id);
		}
		void shader::disable(){
			glUseProgram(0);
		}


		void shader::setUniformMAT4(const GLchar* _nombre, const math::mat4 _mat){
			glUniformMatrix4fv(get_UniformLocation(_nombre), 1, GL_FALSE, _mat.elements);
		}


		void shader::setUniform1f(const GLchar* _nombre, float val ){
			glUniform1f(get_UniformLocation(_nombre), val);
		}
		void shader::setUniform1i(const GLchar* _nombre, int val ){
			glUniform1i(get_UniformLocation(_nombre), val);
		}
		void shader::setUniform2f(const GLchar* _nombre, const math::vec2& _vector ){
			glUniform2f(get_UniformLocation(_nombre), _vector.x, _vector.y);
		}
		void shader::setUniform3f(const GLchar* _nombre, const math::vec3& _vector ){
			glUniform3f(get_UniformLocation(_nombre), _vector.x, _vector.y, _vector.z);
		}
		void shader::setUniform4f(const GLchar* _nombre, const math::vec4& _vector ){
			glUniform4f(get_UniformLocation(_nombre), _vector.x, _vector.y, _vector.z, _vector.w);
		}

		//crea shader
		static GLuint load( const std::string& text, GLenum shader_type){
			GLint shader = glCreateShader(shader_type);

			if(shader == 0) std::cerr<<"Error: fallo en creacion del shader "<<std::endl;

			const GLchar*shader_source_str[1] { };
			GLint shader_source_ln[1] { };

			shader_source_str[0] = text.c_str();
			shader_source_ln[0] = text.length();

			glShaderSource(shader, 1, shader_source_str, shader_source_ln);
			glCompileShader(shader);

			check_shader_err(shader, GL_COMPILE_STATUS, false, "Error compilando shader");

			return (shader);
		}

		//maneja mensaje de error
		static void check_shader_err(GLuint shader, GLuint flag, bool esPrograma, const std::string& msj_err){
			GLint exito = 0;
			GLchar error[1024] =  {0};

			if (esPrograma) glGetProgramiv(shader, flag, &exito);
			else            glGetShaderiv (shader, flag, &exito);

			if(exito == GL_FALSE){
				if(esPrograma)  glGetProgramInfoLog(shader, sizeof(error), NULL, error);
				else            glGetShaderInfoLog (shader, sizeof(error), NULL, error);
				std::cerr<< msj_err << " : '"<< error << "'"<<std::endl;
			}
		}
	}
}
