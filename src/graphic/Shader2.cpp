/*
 * Shader2.cpp
 *
 *  Created on: 20/04/2017
 *      Author: jose
 */

#include "Shader2.h"


namespace spark{ namespace graphics{

static void check_shader_err(GLuint shader, GLuint flag, bool esPrograma, const std::string& msj_err);
static GLuint load( const std::string& text, GLenum shader_type);

shader::shader(const std::string& _file_v, const std::string& _file_f){
    //ctor
    m_shader_id = glCreateProgram();
    m_shaders[0] = load(F::lee_arch(_file_v), GL_VERTEX_SHADER);
    m_shaders[1] = load(F::lee_arch(_file_f), GL_FRAGMENT_SHADER);

    for(unsigned int i=0; i<NUM_SHADERS; i++)
        glAttachShader(m_shader_id, m_shaders[i]);

    glBindAttribLocation(m_shader_id, 0, "position"); //checar
    glBindAttribLocation(m_shader_id, 1, "textCoord");

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

void shader::enable(){
    glUseProgram(m_shader_id);
}
void shader::disable(){
    glUseProgram(0);
}

void shader::update(const transform& _tr, const camara& _cam){
    glm::mat4 model = _cam.get_view_projection() * _tr.get_model();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
    
}

void shader::update(){
	transform tr;
	camara cam( glm::vec3(0,0,-10), 70.0f, float(800)/float(450), 0.5f, 100.0f );
	glm::mat4 model = cam.get_view_projection() * tr.get_model();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

void shader::update(const transform& _tr){
    glm::mat4 model =  _tr.get_model();
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
    //glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &tr.get_model()[0][0]);
}

//crea shader
static GLuint load( const std::string& text, GLenum shader_type){
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
