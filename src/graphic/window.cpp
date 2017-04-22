/*
 * window.cpp
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */
#include "window.h"

/*
    cuando se agregen las funciones y variables de evento estaticas
    se debe declarar

    //static var init
        bool window::m_keys[MAX_KEYS];
        bool window::m_mouse_btn[MAX_BUTTONS];
        double window::mouse_x;
        double window::mouse_y;

*/

namespace spark{ namespace graphics{


        //helper fun
        void window_resize(GLFWwindow *w, int ancho, int alto);
        void key_callback(GLFWwindow * win,  int key, int scancode, int action, int mods);
        void mouse_btn_call(GLFWwindow * win,  int btn, int action, int mods);
        void cursor_pos_call(GLFWwindow * win,  double xpos, double ypos);
        
        //constructor
        window::window(const char* nombre, int ancho, int alto){
            m_alto = alto;
            m_ancho = ancho;
            m_nombre = nombre;
            if(!init()){
                glfwTerminate();
            }

            for(int i = 0; i < MAX_KEYS; i++)       m_keys[i] = false;
            for(int i = 0; i < MAX_BUTTONS; i++)    m_mouse_btn[i] = false;
        }

        //init window checa que se inicialice todo bien
        bool window::init(){

            if(!glfwInit()){
                std::cout<<" error a inicializar glfw "<<std::endl;
                return false;
            }

            m_ventana =  glfwCreateWindow(m_ancho, m_alto, m_nombre, NULL, NULL);
            if(!m_ventana){
                glfwTerminate();
                std::cout<<"fallo creacion de la ventana"<<std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_ventana);
            glfwSetWindowUserPointer(m_ventana,this);
            glfwSetWindowSizeCallback(m_ventana, window_resize);
            glfwSetKeyCallback(m_ventana , key_callback);
            glfwSetMouseButtonCallback(m_ventana, mouse_btn_call);
            glfwSetCursorPosCallback(m_ventana, cursor_pos_call);
            
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            
            if(glewInit() != GLEW_OK){
                std::cout<<"fallo al inicializar GLEW!!!"<<std::endl;
                    return false;
            }
            return true;
        }

        //destructor
        window::~window(){ glfwTerminate();}

        //revisa que una tecla este presionada
        bool window::is_key_pressed(unsigned int keycode) const{
            //por hacer loguear esto
            if(keycode >= MAX_KEYS) return false;
            return m_keys[keycode];
        }

        //revisa que un boton de mouse este presionado
        bool window::is_mouse_btn_pressed(unsigned int boton) const{
            //por hacer loguear esto
            if(boton >= MAX_BUTTONS) return false;
            return m_mouse_btn[boton];
        }

        void window::mouse_position(double& x, double& y) const{
            x = mouse_x;
            y = mouse_y;
        }

        //checa si la ventana esta cerrada
        bool window::cerrado() const { return glfwWindowShouldClose(m_ventana) == 1;}

        //saca los eventos y actualiza la ventana
        void window::update() {
            glfwPollEvents();
            glfwGetFramebufferSize(m_ventana, &m_ancho, &m_alto);
            glfwSwapBuffers(m_ventana);
        }

        //limpia la pantalla
        void window::clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        //key callback
        void key_callback(GLFWwindow * win,  int key, int scancode, int action, int mods){
            window * w = (window*) glfwGetWindowUserPointer(win);
            w->m_keys[key] = action != GLFW_RELEASE;
         }

         //mouse btn callback
         void mouse_btn_call(GLFWwindow * win,  int btn, int action, int mods){
            window * w = (window*) glfwGetWindowUserPointer(win);
            w->m_mouse_btn[btn] = action != GLFW_RELEASE;
         }

         //mouse pos callback
         void cursor_pos_call(GLFWwindow * win,  double xpos, double ypos){
            window * w = (window*) glfwGetWindowUserPointer(win);
            w->mouse_x = xpos;
            w->mouse_y = ypos;
         }

        //helpers //resize
        void window_resize(GLFWwindow *w, int ancho, int alto){ glViewport(0,0, ancho, alto); }

    }

}



