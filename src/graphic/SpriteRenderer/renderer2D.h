/*
 * renderer2D.h
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */
#pragma once

#include <GL/glew.h>
#include "../../math/maths.h"
#include "renderable2D.h"

namespace spark {
	namespace graphics {

		class renderer2D {

		public:
			virtual void begin(){}
			virtual void end(){}
			virtual void submit(const renderable2D* renderable) = 0;
			virtual void flush() = 0;

		};

	} /* namespace graphics */
} /* namespace spark */
