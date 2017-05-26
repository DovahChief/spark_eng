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
        protected:
			std::vector<math::mat4> m_transform_stack;
		protected:
			renderer2D(){
				m_transform_stack.push_back(math::mat4(1.0f));
			}
		public:
			void push(const math::mat4& _matriz, bool _override = false){
				if (!_override)
					m_transform_stack.push_back(m_transform_stack.back() * _matriz);
				else
					m_transform_stack.push_back(_matriz);
			};
			void pop(){
				if (m_transform_stack.size() > 1)
					m_transform_stack.pop_back();
				//TODO agregar log
			};

			virtual void begin(){}
			virtual void end(){}
			virtual void submit(const renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	} /* namespace graphics */
} /* namespace spark */
