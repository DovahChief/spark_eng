/*
 * renderable2D.h
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#pragma once

#include "../shader.h"

#include "../buffers/buffer.h"
#include "../buffers/indexBuffer.h"
#include "../buffers/vertexArray.h"

#include "../../math/maths.h"


namespace spark{
	namespace graphics{

		// plain old data
		struct VertexData {
			math::vec3 vertex;
			//math::vec4 color;
			unsigned int color;
		};

		class renderable2D{

		protected:
			math::vec3 m_position;
			math::vec2 m_size;
			math::vec4 m_color;

		public:
			renderable2D(math::vec3 _pos, math::vec2 _size, math::vec4 _color)
			: m_position(_pos), m_size(_size), m_color(_color)
			{}
			virtual ~renderable2D(){}

		public:

			inline const math::vec3& get_position() const {return (m_position);}
			inline const math::vec2& get_size()const  {return (m_size);}
			inline const math::vec4& get_color() const {return (m_color);}
		};

	} /* namespace graphics */
} /* namespace spark */

