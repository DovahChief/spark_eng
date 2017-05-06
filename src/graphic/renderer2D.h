/*
 * renderer2D.h
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#ifndef GRAPHIC_RENDERER2D_H_
#define GRAPHIC_RENDERER2D_H_

#include <GL/glew.h>
#include "../math/maths.h"
#include "renderable2D.h"

namespace spark { namespace graphics {

	class renderer2D {

	protected:
		virtual void submit(const renderable2D* renderable) = 0;
		virtual void flush() = 0;

	};

} /* namespace graphics */
} /* namespace spark */

#endif /* GRAPHIC_RENDERER2D_H_ */
