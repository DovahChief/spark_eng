/*
 * display.h
 *
 *  Created on: 19/04/2017
 *      Author: jose
 */

#ifndef GRAPHIC_DISPLAY_H_
#define GRAPHIC_DISPLAY_H_


#include <string>
#include <SDL2/SDL.h>


class display{
    public:
        display(const std::string& titulo, int ancho, int alto);
        virtual ~display();
        void update();
        void _clear(float r, float g, float b, float a);
        bool is_closed();
    protected:

    private:
        bool cerrado;
        display(const display& other){};
        void operator=(const display& other){ };
        SDL_Window * m_ventana;
        SDL_GLContext m_glcontext;
};

#endif /* GRAPHIC_DISPLAY_H_ */
