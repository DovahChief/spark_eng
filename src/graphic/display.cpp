/*
 * display.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */
#include "display.h"

#include <iostream>
#include <GL/glew.h>

display::display(const std::string& titulo, int ancho, int alto){
    //ctor
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE , 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_ventana = SDL_CreateWindow(titulo.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 ancho, alto, SDL_WINDOW_OPENGL);

    m_glcontext = SDL_GL_CreateContext(m_ventana);

    GLenum status = glewInit();

    if(status != GLEW_OK)
        std::cerr<<"Fallo al inicializar opengl"<<std::endl;
    cerrado = false;
    std::cout<<"en el ctor del display"<<std::endl;
}

display::~display(){
    //dtor
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_ventana);
    SDL_Quit();
    std::cout<<"en el dtor del display"<<std::endl;
}

void display::update (){
    SDL_GL_SwapWindow(m_ventana);
    SDL_Event event;
    while(SDL_PollEvent(&event)) if(event.type == SDL_QUIT) cerrado = true;
    //callback event
}

bool display::is_closed(){return cerrado;}

void display::_clear(float r = 0.0f, float g = 0.15f, float b = 0.3f, float a = 1.0f){
        glClearColor(r,g,b,a);
        glClear(GL_COLOR_BUFFER_BIT);
}




