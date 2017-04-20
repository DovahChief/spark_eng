/*
 * shader.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "shader.h"

namespace spark{ namespace graphics{

 	 shader::shader(const char* ruta_vertex,const char* ruta_fragment){
 		 	 m_ruta_fragment = ruta_fragment;
 		 	 m_ruta_vertex = ruta_fragment;
 		 	 m_shader_id = load();
 	 }

 	 GLuint shader::load(){
 		 GLuint programa = glCreateProgram();

 	 }

}}


