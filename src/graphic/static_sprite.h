//
// Created by jose on 7/05/17.
//

#pragma once

#include "renderable2D.h"

namespace spark{
    namespace graphics{
        class static_sprite: public renderable2D {

        private:
            vertexArray* m_vertexArray;
            indexBuffer* m_indexBuffer;
            shader& m_shader;

        public:
            static_sprite(float _x, float _y, float _ancho, float _alto, const math::vec4& _color, shader& _shader);
            virtual ~static_sprite();

            inline const vertexArray* getVAO() const {return (m_vertexArray);}
            inline const indexBuffer* getIBO() const {return (m_indexBuffer);}
            inline shader& getShader() const {return (m_shader);}
        };


    } /* namespace graphics */
} /* namespace spark */