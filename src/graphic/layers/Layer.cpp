//
// Created by jose on 11/05/17.
//

#include "Layer.h"

namespace spark {
    namespace graphics{

        Layer::Layer(renderer2D * _rend, Shader* _shad, math::mat4 _prMat)
        : m_mat_proy(_prMat), m_shad(_shad), m_renderer(_rend)
        {
            m_shad->enable();
            m_shad->setUniformMAT4("pr_mat", m_mat_proy);
            m_shad->disable();
        }

        Layer::~Layer() {
            delete m_renderer;
            delete m_shad;
            for (auto c: m_renderables)
                delete c;
        }

        void Layer::add(renderable2D *_rend)  {
            m_renderables.push_back(_rend);
        }

        void Layer::render() {
            m_shad->enable();
            m_renderer->begin();
            for(const auto _renderable : m_renderables)
                m_renderer->submit(_renderable);

            m_renderer->end();
            m_renderer->flush();
            //m_shad->disable();
        }
    }/* namespace graphics */
}/* namespace spark */