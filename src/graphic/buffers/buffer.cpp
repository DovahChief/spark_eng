/*
 * buffer.cpp
 *
 *  Created on: 23/04/2017
 *      Author: jose
 */

#include "buffer.h"

namespace spark {
	namespace graphics {

		buffer::buffer(GLfloat* _data, GLsizei _count, GLuint _comp_count)
			:m_Component_count(_comp_count)
			{
				glGenBuffers(1, &m_buffer_ID);
				glBindBuffer(GL_ARRAY_BUFFER, m_buffer_ID);
				glBufferData(GL_ARRAY_BUFFER, _count* sizeof(GLfloat), _data, GL_STATIC_DRAW);
				glBindBuffer(GL_ARRAY_BUFFER, 0);

			}

		void buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_buffer_ID);
		}

		void buffer::unbind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		buffer::~buffer() {
			glDeleteBuffers(1, &m_buffer_ID);
		}


	} /* namespace graphics */
} /* namespace spark */
