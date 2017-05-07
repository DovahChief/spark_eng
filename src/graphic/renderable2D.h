/*
 * renderable2D.h
 *
 *  Created on: 06/05/2017
 *      Author: jose
 */

#pragma once

#include "shader.h"

#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"

#include "../math/maths.h"


namespace spark{
	namespace graphics{

		// plain old data
		struct VertexData {
			math::vec3 vertex;
			math::vec4 color;
		};

		class renderable2D{

		protected:
			math::vec3 m_position;
			math::vec2 m_size;
			math::vec4 m_color;

			vertexArray* m_vertexArray;
			indexBuffer* m_indexBuffer;

			shader& m_shader;
		public:
			renderable2D(math::vec3 _pos, math::vec2 _size, math::vec4 _color, shader& _shader)
			: m_position(_pos), m_size(_size), m_color(_color), m_shader(_shader)
			{
				m_vertexArray = new vertexArray { };

				GLfloat vertices [] {
					0,0,0,
					0, m_size.y, 0,
					m_size.x, m_size.y, 0,
					m_size.x, 0 , 0
				};

				GLfloat colors [] {
						m_color.x, m_color.y, m_color.z, m_color.w,
						m_color.x, m_color.y, m_color.z, m_color.w,
						m_color.x, m_color.y, m_color.z, m_color.w,
						m_color.x, m_color.y, m_color.z, m_color.w
				};

				m_vertexArray->addBuffer(new buffer {vertices, 	4*3, 3 }, 0);
				m_vertexArray->addBuffer(new buffer {colors, 	4*4, 4 }, 1);
				GLushort indices[] {0,1,2,2,3,0 };
				m_indexBuffer = new indexBuffer { indices, 6 };
			}

			virtual ~renderable2D(){
				delete m_vertexArray;
				delete m_indexBuffer;
			}

		public:

			inline const vertexArray* getVAO() const {return (m_vertexArray);}
			inline const indexBuffer* getIBO() const {return (m_indexBuffer);}
			inline shader& getShader() const {return (m_shader);}

			inline const math::vec3& get_position() const {return (m_position);}
			inline const math::vec2& get_size(){return (m_size);}
			inline const math::vec4& get_color(){return (m_color);}
		};

	} /* namespace graphics */
} /* namespace spark */

