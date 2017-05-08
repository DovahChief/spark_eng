//
// Created by jose on 7/05/17.
//

#include "sprite.h"

namespace spark{
    namespace graphics{

        sprite::sprite(float _x, float _y, float _ancho, float _alto, const math::vec4& _color)
        : renderable2D(math::vec3(_x,_y,0), math::vec2(_ancho, _alto), _color)
        {

        }
    } /* namespace graphics */
} /* namespace spark */
