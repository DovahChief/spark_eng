/*
 * shader.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "shader.h"
#include <vector>
#include <iostream>

namespace spark{ namespace graphics{

 	 shader::shader(const char* ruta_vertex,const char* ruta_fragment)
 	 : m_ruta_fragment (ruta_fragment), m_ruta_vertex(ruta_vertex)
 	 {
 		 	 m_shader_id = load();
 	 }

 	 shader::~shader(){ glDeleteProgram(m_shader_id);}

 	 GLuint shader::load(){
 		 GLuint programa 	= glCreateProgram();
 		 GLuint vertex 		= glCreateShader(GL_VERTEX_SHADER);
 		 GLuint fragment 	= glCreateShader(GL_FRAGMENT_SHADER);

 		 const char* vert_src = lee_arch(m_ruta_vertex).c_str();
 		 const char* frag_src = lee_arch(m_ruta_fragment).c_str();

 		 glGetShaderSource(vertex, 1, &vert_src, NULL);
 		 glCompileShader(vertex);

 		 GLint result;
 		 glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

 		 if(result == GL_FALSE){
 			GLint length;
 			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
 			std::vector<char> error(length);
 			glGetShaderInfoLog(vertex, length, &length, &error[0]);
 			std::cout<<"Fallo al compilar vertex shader" << std::endl << &error[0] << std::endl;
 			glDeleteShader(vertex);
 			return (0);
 		 }

 		 glGetShaderSource(fragment, 1, &frag_src, NULL);
		 glCompileShader(fragment);

		 result = 0;
		 glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

		 if(result == GL_FALSE){
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout<<"Fallo al compilar fragment shader"<< std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return (0);
		 }

		 glAttachShader(programa, vertex);
		 glAttachShader(programa, fragment);

		 glLinkProgram(programa);
		 glValidateProgram(programa);

		 glDeleteShader(fragment);
		 glDeleteShader(vertex);

		 return (programa);

 	 }

 	 void shader::enable() const {
 		 glUseProgram(m_shader_id);
 	 }
 	 void shader::disable() const{
 		 glUseProgram(0);
 	 }

}}


