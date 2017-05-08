/*
 * renderer2D.cpp
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#include "simple2Drenderer.h"

namespace spark {
	namespace graphics {


		void simple2DRenderer::submit(const renderable2D* renderable){
			m_renderQue.push_back((static_sprite*)renderable);
		}

		void simple2DRenderer::flush(){
			while(!(m_renderQue.empty()))
			{
				const static_sprite* sprite = m_renderQue.front();
				sprite->getVAO()->bind();
				sprite->getIBO()->bind();

				sprite->getShader().
						setUniformMAT4("ml_mat",math::mat4::translation(sprite->get_position()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->get_cont(), GL_UNSIGNED_SHORT, 0);

				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();

				m_renderQue.pop_front();
			}
		}
	} /* namespace graphics */
} /* namespace spark */
