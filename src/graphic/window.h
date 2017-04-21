/*
 * window.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_WINDOW_H_
#define GRAPHIC_WINDOW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*para un solo display usa variables de eventos estaticas
 y agregar static a las funciones de evento
*/

namespace spark{ namespace graphics{

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

    class window{

    public: //interfaz
        window(const char* nombre, int ancho, int alto);
        ~window();
        void update () ;
        void clear() const;
        bool cerrado() const;

        inline int get_ancho() const {return (m_ancho);}
        inline int get_alto()  const {return (m_alto);}
        inline void set_alto(int alto) {m_alto = alto;}
        inline void set_ancho(int ancho) {m_ancho = ancho;}

        //funciones de evento
        bool is_key_pressed(unsigned int keycode) const;
        bool is_mouse_btn_pressed(unsigned int boton) const;
        void mouse_position(double& x, double& y) const;

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

    }
}




#endif /* GRAPHIC_WINDOW_H_ */
