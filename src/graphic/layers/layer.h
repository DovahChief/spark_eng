//
// Created by jose on 11/05/17.
//
#pragma once

#include <vector>

#include "../SpriteRenderer/renderer2D.h"
#include "../SpriteRenderer/renderable2D.h"
#include "../shader.h"
#include "../../math/mat4.h"

//toma el control de los renderers

namespace spark {
    namespace graphics{
        class layer{

        protected:
            renderer2D* m_renderer;
            std::vector<renderable2D*> m_renderables;
            shader* m_shad;
            math::mat4 m_mat_proy;
        protected:
            layer(renderer2D * _rend, shader* _shad, math::mat4 _prMat);
        public:
            virtual ~layer();
            virtual void  add(renderable2D* _rend);
            virtual void render();
        };
    }/* namespace graphics */
}/* namespace spark */
