//
// Created by jose on 7/05/17.
//

#include "static_sprite.h"

namespace spark{
    namespace graphics{


        static_sprite::static_sprite(float _x, float _y, float _ancho, float _alto, const math::vec4& _color, shader& _shader)
        :renderable2D(math::vec3(_x,_y,0), math::vec2(_ancho, _alto), _color) , m_shader(_shader)
        {

            m_vertexArray = new vertexArray { };

            GLfloat vertices [] {
                    0,0,0,
                    0, _alto, 0,
                    _ancho, _alto, 0,
                    _ancho, 0 , 0
            };

            GLfloat colors [] {
                    m_color.x, m_color.y, m_color.z, m_color.w,
                    m_color.x, m_color.y, m_color.z, m_color.w,
                    m_color.x, m_color.y, m_color.z, m_color.w,
                    m_color.x, m_color.y, m_color.z, m_color.w
            };

            m_vertexArray->addBuffer(new buffer {vertices, 	4*3, 3 }, 0);
            m_vertexArray->addBuffer(new buffer {colors, 	4*4, 4 }, 1);
            GLushort indices[] {0,1,2,2,3,0 };
            m_indexBuffer = new indexBuffer { indices, 6 };

        }

        static_sprite::~static_sprite() {
            delete m_vertexArray;
            delete m_indexBuffer;
        }


    } /* namespace graphics */
} /* namespace spark */