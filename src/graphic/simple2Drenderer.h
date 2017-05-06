/*
 * simple2Drenderer.h
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#ifndef GRAPHIC_SIMPLE2DRENDERER_H_
#define GRAPHIC_SIMPLE2DRENDERER_H_

#include "renderer2D.h"
#include "../math/maths.h"

#include <deque>
#include <GL/glew.h>

namespace spark { namespace graphics {

	class simple2DRenderer: public renderer2D {

	private:
		std::deque<const renderable2D*> m_renderQue;

	public:
			virtual void submit(const renderable2D* renderable) override;
			virtual void flush() override;


	};

} /* namespace graphics */
} /* namespace spark */

#endif /* GRAPHIC_SIMPLE2DRENDERER_H_ */
