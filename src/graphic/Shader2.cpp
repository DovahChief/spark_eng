/*
 * Shader2.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "Shader2.h"

#include "shader.h"
#include <fstream>
#include <iostream>

namespace spark{ namespace graphics{

static void check_shader_err(GLuint shader, GLuint flag, bool esPrograma, const std::string& msj_err);
static std::string carga_shader(const std::string& file_name);
static GLuint crea_shader( const std::string& text, GLenum shader_type);

Shader2::Shader2(const std::string& file_name ){
    //ctor
    m_programa = glCreateProgram();
    m_shaders[0] = crea_shader(carga_shader(file_name + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = crea_shader(carga_shader(file_name + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i=0; i<NUM_SHADERS; i++)
        glAttachShader(m_programa, m_shaders[i]);


    glBindAttribLocation(m_programa, 0, "position"); //checar
    glBindAttribLocation(m_programa, 1, "textCoord");

    glLinkProgram(m_programa);
    check_shader_err(m_programa, GL_LINK_STATUS, true, "Error en ligado de programa");

    glValidateProgram(m_programa);
    check_shader_err(m_programa, GL_VALIDATE_STATUS, true, "Error en validando programa");

    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_programa, "transform");
}

Shader2::~Shader2(){
    //dtor
    for(unsigned int i=0; i<NUM_SHADERS; i++){
        glDetachShader(m_programa, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_programa);
}

void Shader2::Bind(){
    glUseProgram(m_programa);
}
/*
void Shader2::Update(const transform& tr, const camara& cam){
    glm::mat4 model = cam.get_view_projection() * tr.get_model();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
    //glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &tr.get_model()[0][0]);
}
*/
void Shader2::Update(const transform& tr){
    glm::mat4 model =  tr.get_model();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
    //glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &tr.get_model()[0][0]);
}

//crea shader
static GLuint crea_shader( const std::string& text, GLenum shader_type){
    GLint shader = glCreateShader(shader_type);

    if(shader == 0) std::cerr<<"Error: fallo en creacion del shader "<<std::endl;

    const GLchar* shader_source_str[1];
    GLint shader_source_ln[1];

    shader_source_str[0] = text.c_str();
    shader_source_ln[0] = text.length();

    glShaderSource(shader, 1, shader_source_str, shader_source_ln);
    glCompileShader(shader);

    check_shader_err(shader, GL_COMPILE_STATUS, false, "Error compilando shader");

    return (shader);
}

//carga shader
static std::string carga_shader(const std::string& file_name){
    std::ifstream archivo;
    archivo.open((file_name).c_str());

    std::string salida, linea;

    if(archivo.is_open()){
        while(archivo.good()){
            getline( archivo, linea);
            salida.append(linea + "\n");
        }
    }else {
        std::cerr<<"Fallo al abrir el archivo : "<<file_name<<std::endl;
    } return (salida);
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
}}
