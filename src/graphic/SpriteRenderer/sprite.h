//
// Created by jose on 7/05/17.
//

#pragma once


#include "renderable2D.h"

namespace spark{
    namespace graphics{

        class sprite : public renderable2D {
        private:

        public:
            sprite(float _x, float _y, float _ancho, float _alto, const math::vec4& _color);
        };

    } /* namespace graphics */
} /* namespace spark */

