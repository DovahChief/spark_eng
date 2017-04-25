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

 	 shader_2::shader_2(const char* _ruta_vertex,const char* _ruta_fragment)
 	 : m_ruta_fragment (_ruta_fragment), m_ruta_vertex(_ruta_vertex)
 	 {
 		 	 m_shader_id = load();
 	 }

 	 shader_2::~shader_2(){ glDeleteProgram(m_shader_id);}

 	 GLuint shader_2::load(){
 		 GLuint programa 	= glCreateProgram();
 		 GLuint vertex 		= glCreateShader(GL_VERTEX_SHADER);
 		 GLuint fragment 	= glCreateShader(GL_FRAGMENT_SHADER);
 		 GLint vert_source_ln[1];
 		 GLint frag_source_ln[1];

 		 std::string vert_src = F::lee_arch(m_ruta_vertex);
 		 std::string frag_src = F::lee_arch(m_ruta_fragment);

 		 const char *vrt_s = vert_src.c_str();
 		 vert_source_ln[0] = vert_src.length();

 		 const char *frg_s = frag_src.c_str();
 		 frag_source_ln[0] = frag_src.length();

 		 glShaderSource(vertex, 1, &vrt_s, vert_source_ln);
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

 		 glShaderSource(fragment, 1, &frg_s, frag_source_ln);
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

 	 void shader_2::enable() const {
 		 glUseProgram(m_shader_id);
 	 }
 	 void shader_2::disable() const{
 		 glUseProgram(0);
 	 }

}}
