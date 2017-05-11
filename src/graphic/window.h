/*
 * window.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*para un solo display usa variables de eventos estaticas
 y agregar static a las funciones de evento
*/

namespace spark{
    namespace graphics{

        constexpr auto MAX_KEYS = 1024;
        constexpr auto MAX_BUTTONS = 32;

        class window{

        public: //interfaz
            window(const char* _nombre, int _ancho, int _alto);
            ~window();
            void update () ;
            void clear() const;
            bool cerrado() const;

            inline int get_ancho() const {return (m_ancho);}
            inline int get_alto()  const {return (m_alto);}
            inline void set_alto(int _alto) {m_alto = _alto;}
            inline void set_ancho(int _ancho) {m_ancho = _ancho;}

            //funciones de evento
            bool is_key_pressed(unsigned int _keycode) const;
            bool is_mouse_btn_pressed(unsigned int _boton) const;
            void mouse_position(double& _x, double& _y);

        private://metodos privados
            bool init();
            friend  void key_callback(GLFWwindow * win,  int key, int scancode, int action, int mods);
            friend  void mouse_btn_call(GLFWwindow * win,  int btn, int action, int mods);
            friend  void cursor_pos_call(GLFWwindow * win,  double xpos, double ypos);

        private: //data members
            const char* m_nombre;
            int m_ancho, m_alto;
            bool m_cerrado;
            GLFWwindow* m_ventana;

            //eventos
            bool m_keys[MAX_KEYS];
            bool m_mouse_btn[MAX_BUTTONS];
            double mouse_x, mouse_y;


        };

    } /* namespace graphics */
} /* namespace spark */

