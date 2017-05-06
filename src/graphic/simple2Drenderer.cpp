/*
 * renderer2D.cpp
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#include "simple2Drenderer.h"

namespace spark { namespace graphics {


	void simple2DRenderer::submit(const renderable2D* renderable){
		m_renderQue.push_back(renderable);
	}

	void simple2DRenderer::flush(){
		while(!(m_renderQue.empty()))
		{
			const renderable2D* renderable = m_renderQue.front();
			renderable->getVAO()->bind();
			renderable->getIBO()->bind();

			renderable->getShader().
					setUniformMAT4("ml_mat",math::mat4::translation(renderable->get_position()));
			glDrawElements(GL_TRIANGLES, renderable->getIBO()->get_cont(), GL_UNSIGNED_SHORT, 0);

			renderable->getIBO()->unbind();
			renderable->getVAO()->unbind();

			m_renderQue.pop_front();
		}
	}


} /* namespace graphics */
} /* namespace spark */
